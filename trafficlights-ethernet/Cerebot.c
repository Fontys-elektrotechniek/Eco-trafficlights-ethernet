///////////////////////////////////////////////////////////////////////////
//  Product/Project : Trafficlights-ethernet                             //
///////////////////////////////////////////////////////////////////////////
//
//  File Name    : Cerebot.c
//  Version      : 1.0
//  Description  : Specific functions for the Cerebot 32mx4
//
//  Author       : Jim Clermonts
//  Target       : Cerebot 32MX4 (PIC32MX460L512F)
//  Compiler     : MPLAB C Compiler for PIC32
//  IDE          : MPLAB X IDE Beta5.0
//  Programmer   : SKDE PIC32
//  Last Updated : 14-04-2012
//
//  Copyright (c) Fontys 2012.
//  All rights are reserved. Reproduction in whole or in part is
//  prohibited without the written consent of the copyright owner.
///////////////////////////////////////////////////////////////////////////

#include "Cerebot.h"
#include <string.h>
#include <uart.h>
#include "TCPIP Stack/TCPIP.h"

#define DESIRED_BAUDRATE    	(9600)      //The desired BaudRate

BYTE AN0String[8];
static unsigned short wOriginalAppConfigChecksum; // Checksum of the ROM defaults for AppConfig
extern DWORD dwLastIP;
static DWORD t = 0;

void InitializeUART(void)
{
    UARTConfigure(UART2, UART_ENABLE_PINS_TX_RX_ONLY);
    UARTSetFifoMode(UART2, UART_INTERRUPT_ON_TX_NOT_FULL | UART_INTERRUPT_ON_RX_NOT_EMPTY);
    UARTSetLineControl(UART2, UART_DATA_SIZE_8_BITS | UART_PARITY_NONE | UART_STOP_BITS_1);
    UARTSetDataRate(UART2, GetPeripheralClock(), DESIRED_BAUDRATE);
    UARTEnable(UART2, UART_ENABLE_FLAGS(UART_PERIPHERAL | UART_RX | UART_TX));

    // Configure UART2 RX Interrupt
    INTEnable(INT_SOURCE_UART_RX(UART2), INT_ENABLED);
    INTSetVectorPriority(INT_VECTOR_UART(UART2), INT_PRIORITY_LEVEL_2);
    INTSetVectorSubPriority(INT_VECTOR_UART(UART2), INT_SUB_PRIORITY_LEVEL_0);

    // configure for multi-vectored mode
    INTConfigureSystem(INT_SYSTEM_CONFIG_MULT_VECTOR);
}

void InitalizeCrossroadIO(void)
{
    // Your code goes here

    mPORTAClearBits(BIT_7); // Turn off RA7 on startup.
    mPORTASetPinsDigitalOut(BIT_7); // Make RA7 as output.
}

void WriteString(const char *string)
{
    while (*string != '\0')
    {
        while (!UARTTransmitterIsReady(UART2))
            ;

        UARTSendDataByte(UART2, *string);

        string++;

        while (!UARTTransmissionHasCompleted(UART2))
            ;
    }
}

void PutCharacter(const char character)
{
    while (!UARTTransmitterIsReady(UART2))
        ;

    UARTSendDataByte(UART2, character);


    while (!UARTTransmissionHasCompleted(UART2))
        ;
}

void ProcessIO(void)
{
    // Convert potentiometer result into ASCII string
    uitoa((WORD) ADC1BUF0, AN0String);
}

/****************************************************************************
  Function:
    static void InitializeBoard(void)

  Description:
    This routine initializes the hardware.  It is a generic initialization
    routine for many of the Microchip development boards, using definitions
    in HardwareProfile.h to determine specific initialization.

  Precondition:
    None

  Parameters:
    None - None

  Returns:
    None

  Remarks:
    None
 ***************************************************************************/
void InitializeBoard(void)
{
    // LEDs
    LED0_TRIS = 0;
    LED1_TRIS = 0;
    LED2_TRIS = 0;
    LED3_TRIS = 0;
    LED4_TRIS = 0;
    LED5_TRIS = 0;
    LED6_TRIS = 0;
    LED7_TRIS = 0;
    LED_PUT(0x00);

#if defined(__PIC32MX__)
    {
        // Enable multi-vectored interrupts
        INTEnableSystemMultiVectoredInt();

        // Enable optimal performance
        SYSTEMConfigPerformance(GetSystemClock());
        mOSCSetPBDIV(OSC_PB_DIV_1); // Use 1:1 CPU Core:Peripheral clocks

        // Disable JTAG port so we get our I/O pins back, but first
        // wait 50ms so if you want to reprogram the part with
        // JTAG, you'll still have a tiny window before JTAG goes away.
        // The PIC32 Starter Kit debuggers use JTAG and therefore must not
        // disable JTAG.
        DelayMs(50);
#if !defined(__MPLAB_DEBUGGER_PIC32MXSK) && !defined(__MPLAB_DEBUGGER_FS2)
        DDPCONbits.JTAGEN = 0;
#endif
        LED_PUT(0x00); // Turn the LEDs off

        CNPUESET = 0x00098000; // Turn on weak pull ups on CN15, CN16, CN19 (RD5, RD7, RD13), which is connected to buttons on PIC32 Starter Kit boards
    }
#endif

    AD1CHS = 0; // Input to AN0 (potentiometer)
    AD1PCFGbits.PCFG4 = 0; // Disable digital input on AN4 (TC1047A temp sensor)
    AD1PCFGbits.PCFG2 = 0; // Disable digital input on AN2 (potentiometer)

    // ADC
    AD1CON1 = 0x84E4; // Turn on, auto sample start, auto-convert, 12 bit mode (on parts with a 12bit A/D)
    AD1CON2 = 0x0404; // AVdd, AVss, int every 2 conversions, MUXA only, scan
    AD1CON3 = 0x1003; // 16 Tad auto-sample, Tad = 3*Tcy
    AD1CSSL = 1 << 2; // Scan pot

    // Deassert all chip select lines so there isn't any problem with
    // initialization order.  Ex: When ENC28J60 is on SPI2 with Explorer 16,
    // MAX3232 ROUT2 pin will drive RF12/U2CTS ENC28J60 CS line asserted,
    // preventing proper 25LC256 EEPROM operation.
#if defined(ENC_CS_TRIS)
    ENC_CS_IO = 1;
    ENC_CS_TRIS = 0;
#endif
}

/*********************************************************************
 * Function:        void InitAppConfig(void)
 *
 * PreCondition:    MPFSInit() is already called.
 *
 * Input:           None
 *
 * Output:          Write/Read non-volatile config variables.
 *
 * Side Effects:    None
 *
 * Overview:        None
 *
 * Note:            None
 ********************************************************************/
// MAC Address Serialization using a MPLAB PM3 Programmer and
// Serialized Quick Turn Programming (SQTP).
// The advantage of using SQTP for programming the MAC Address is it
// allows you to auto-increment the MAC address without recompiling
// the code for each unit.  To use SQTP, the MAC address must be fixed
// at a specific location in program memory.  Uncomment these two pragmas
// that locate the MAC address at 0x1FFF0.  Syntax below is for MPLAB C
// Compiler for PIC18 MCUs. Syntax will vary for other compilers.
//#pragma romdata MACROM=0x1FFF0
static ROM BYTE SerializedMACAddress[6] = {MY_DEFAULT_MAC_BYTE1, MY_DEFAULT_MAC_BYTE2, MY_DEFAULT_MAC_BYTE3, MY_DEFAULT_MAC_BYTE4, MY_DEFAULT_MAC_BYTE5, MY_DEFAULT_MAC_BYTE6};
//#pragma romdata

void InitAppConfig(void)
{
#if defined(EEPROM_CS_TRIS) || defined(SPIFLASH_CS_TRIS)
    unsigned char vNeedToSaveDefaults = 0;
#endif

    while (1)
    {
        // Start out zeroing all AppConfig bytes to ensure all fields are
        // deterministic for checksum generation
        memset((void*) &AppConfig, 0x00, sizeof (AppConfig));

        AppConfig.Flags.bIsDHCPEnabled = TRUE;
        AppConfig.Flags.bInConfigMode = TRUE;
        memcpypgm2ram((void*) &AppConfig.MyMACAddr, (ROM void*) SerializedMACAddress, sizeof (AppConfig.MyMACAddr));
        //		{
        //			_prog_addressT MACAddressAddress;
        //			MACAddressAddress.next = 0x157F8;
        //			_memcpy_p2d24((char*)&AppConfig.MyMACAddr, MACAddressAddress, sizeof(AppConfig.MyMACAddr));
        //		}
        AppConfig.MyIPAddr.Val = MY_DEFAULT_IP_ADDR_BYTE1 | MY_DEFAULT_IP_ADDR_BYTE2 << 8ul | MY_DEFAULT_IP_ADDR_BYTE3 << 16ul | MY_DEFAULT_IP_ADDR_BYTE4 << 24ul;
        AppConfig.DefaultIPAddr.Val = AppConfig.MyIPAddr.Val;
        AppConfig.MyMask.Val = MY_DEFAULT_MASK_BYTE1 | MY_DEFAULT_MASK_BYTE2 << 8ul | MY_DEFAULT_MASK_BYTE3 << 16ul | MY_DEFAULT_MASK_BYTE4 << 24ul;
        AppConfig.DefaultMask.Val = AppConfig.MyMask.Val;
        AppConfig.MyGateway.Val = MY_DEFAULT_GATE_BYTE1 | MY_DEFAULT_GATE_BYTE2 << 8ul | MY_DEFAULT_GATE_BYTE3 << 16ul | MY_DEFAULT_GATE_BYTE4 << 24ul;
        AppConfig.PrimaryDNSServer.Val = MY_DEFAULT_PRIMARY_DNS_BYTE1 | MY_DEFAULT_PRIMARY_DNS_BYTE2 << 8ul | MY_DEFAULT_PRIMARY_DNS_BYTE3 << 16ul | MY_DEFAULT_PRIMARY_DNS_BYTE4 << 24ul;
        AppConfig.SecondaryDNSServer.Val = MY_DEFAULT_SECONDARY_DNS_BYTE1 | MY_DEFAULT_SECONDARY_DNS_BYTE2 << 8ul | MY_DEFAULT_SECONDARY_DNS_BYTE3 << 16ul | MY_DEFAULT_SECONDARY_DNS_BYTE4 << 24ul;


        // SNMP Community String configuration
#if defined(STACK_USE_SNMP_SERVER)
        {
            BYTE i;
            static ROM char * ROM cReadCommunities[] = SNMP_READ_COMMUNITIES;
            static ROM char * ROM cWriteCommunities[] = SNMP_WRITE_COMMUNITIES;
            ROM char * strCommunity;

            for (i = 0; i < SNMP_MAX_COMMUNITY_SUPPORT; i++)
            {
                // Get a pointer to the next community string
                strCommunity = cReadCommunities[i];
                if (i >= sizeof (cReadCommunities) / sizeof (cReadCommunities[0]))
                    strCommunity = "";

                // Ensure we don't buffer overflow.  If your code gets stuck here,
                // it means your SNMP_COMMUNITY_MAX_LEN definition in TCPIPConfig.h
                // is either too small or one of your community string lengths
                // (SNMP_READ_COMMUNITIES) are too large.  Fix either.
                if (strlenpgm(strCommunity) >= sizeof (AppConfig.readCommunity[0]))
                    while (1);

                // Copy string into AppConfig
                strcpypgm2ram((char*) AppConfig.readCommunity[i], strCommunity);

                // Get a pointer to the next community string
                strCommunity = cWriteCommunities[i];
                if (i >= sizeof (cWriteCommunities) / sizeof (cWriteCommunities[0]))
                    strCommunity = "";

                // Ensure we don't buffer overflow.  If your code gets stuck here,
                // it means your SNMP_COMMUNITY_MAX_LEN definition in TCPIPConfig.h
                // is either too small or one of your community string lengths
                // (SNMP_WRITE_COMMUNITIES) are too large.  Fix either.
                if (strlenpgm(strCommunity) >= sizeof (AppConfig.writeCommunity[0]))
                    while (1);

                // Copy string into AppConfig
                strcpypgm2ram((char*) AppConfig.writeCommunity[i], strCommunity);
            }
        }
#endif

        // Load the default NetBIOS Host Name
        memcpypgm2ram(AppConfig.NetBIOSName, (ROM void*) MY_DEFAULT_HOST_NAME, 16);
        FormatNetBIOSName(AppConfig.NetBIOSName);

#if defined(WF_CS_TRIS)
        // Load the default SSID Name
        WF_ASSERT(sizeof (MY_DEFAULT_SSID_NAME) <= sizeof (AppConfig.MySSID));
        memcpypgm2ram(AppConfig.MySSID, (ROM void*) MY_DEFAULT_SSID_NAME, sizeof (MY_DEFAULT_SSID_NAME));
        AppConfig.SsidLength = sizeof (MY_DEFAULT_SSID_NAME) - 1;

        AppConfig.SecurityMode = MY_DEFAULT_WIFI_SECURITY_MODE;
        AppConfig.WepKeyIndex = MY_DEFAULT_WEP_KEY_INDEX;

#if (MY_DEFAULT_WIFI_SECURITY_MODE == WF_SECURITY_OPEN)
        memset(AppConfig.SecurityKey, 0x00, sizeof (AppConfig.SecurityKey));
        AppConfig.SecurityKeyLength = 0;

#elif MY_DEFAULT_WIFI_SECURITY_MODE == WF_SECURITY_WEP_40
        memcpypgm2ram(AppConfig.SecurityKey, (ROM void*) MY_DEFAULT_WEP_KEYS_40, sizeof (MY_DEFAULT_WEP_KEYS_40) - 1);
        AppConfig.SecurityKeyLength = sizeof (MY_DEFAULT_WEP_KEYS_40) - 1;

#elif MY_DEFAULT_WIFI_SECURITY_MODE == WF_SECURITY_WEP_104
        memcpypgm2ram(AppConfig.SecurityKey, (ROM void*) MY_DEFAULT_WEP_KEYS_104, sizeof (MY_DEFAULT_WEP_KEYS_104) - 1);
        AppConfig.SecurityKeyLength = sizeof (MY_DEFAULT_WEP_KEYS_104) - 1;

#elif (MY_DEFAULT_WIFI_SECURITY_MODE == WF_SECURITY_WPA_WITH_KEY)       || \
	              (MY_DEFAULT_WIFI_SECURITY_MODE == WF_SECURITY_WPA2_WITH_KEY)      || \
	              (MY_DEFAULT_WIFI_SECURITY_MODE == WF_SECURITY_WPA_AUTO_WITH_KEY)
        memcpypgm2ram(AppConfig.SecurityKey, (ROM void*) MY_DEFAULT_PSK, sizeof (MY_DEFAULT_PSK) - 1);
        AppConfig.SecurityKeyLength = sizeof (MY_DEFAULT_PSK) - 1;

#elif (MY_DEFAULT_WIFI_SECURITY_MODE == WF_SECURITY_WPA_WITH_PASS_PHRASE)     || \
	              (MY_DEFAULT_WIFI_SECURITY_MODE == WF_SECURITY_WPA2_WITH_PASS_PHRASE)    || \
	              (MY_DEFAULT_WIFI_SECURITY_MODE == WF_SECURITY_WPA_AUTO_WITH_PASS_PHRASE)
        memcpypgm2ram(AppConfig.SecurityKey, (ROM void*) MY_DEFAULT_PSK_PHRASE, sizeof (MY_DEFAULT_PSK_PHRASE) - 1);
        AppConfig.SecurityKeyLength = sizeof (MY_DEFAULT_PSK_PHRASE) - 1;

#else
#error "No security defined"
#endif /* MY_DEFAULT_WIFI_SECURITY_MODE */

#endif

        // Compute the checksum of the AppConfig defaults as loaded from ROM
        wOriginalAppConfigChecksum = CalcIPChecksum((BYTE*) & AppConfig, sizeof (AppConfig));

#if defined(EEPROM_CS_TRIS) || defined(SPIFLASH_CS_TRIS)
        {
            NVM_VALIDATION_STRUCT NVMValidationStruct;

            // Check to see if we have a flag set indicating that we need to
            // save the ROM default AppConfig values.
            if (vNeedToSaveDefaults)
                SaveAppConfig(&AppConfig);

            // Read the NVMValidation record and AppConfig struct out of EEPROM/Flash
#if defined(EEPROM_CS_TRIS)
            {
                XEEReadArray(0x0000, (BYTE*) & NVMValidationStruct, sizeof (NVMValidationStruct));
                XEEReadArray(sizeof (NVMValidationStruct), (BYTE*) & AppConfig, sizeof (AppConfig));
            }
#elif defined(SPIFLASH_CS_TRIS)
            {
                SPIFlashReadArray(0x0000, (BYTE*) & NVMValidationStruct, sizeof (NVMValidationStruct));
                SPIFlashReadArray(sizeof (NVMValidationStruct), (BYTE*) & AppConfig, sizeof (AppConfig));
            }
#endif

            // Check EEPROM/Flash validitity.  If it isn't valid, set a flag so
            // that we will save the ROM default values on the next loop
            // iteration.
            if ((NVMValidationStruct.wConfigurationLength != sizeof (AppConfig)) ||
                    (NVMValidationStruct.wOriginalChecksum != wOriginalAppConfigChecksum) ||
                    (NVMValidationStruct.wCurrentChecksum != CalcIPChecksum((BYTE*) & AppConfig, sizeof (AppConfig))))
            {
                // Check to ensure that the vNeedToSaveDefaults flag is zero,
                // indicating that this is the first iteration through the do
                // loop.  If we have already saved the defaults once and the
                // EEPROM/Flash still doesn't pass the validity check, then it
                // means we aren't successfully reading or writing to the
                // EEPROM/Flash.  This means you have a hardware error and/or
                // SPI configuration error.
                if (vNeedToSaveDefaults)
                {
                    while (1);
                }

                // Set flag and restart loop to load ROM defaults and save them
                vNeedToSaveDefaults = 1;
                continue;
            }

            // If we get down here, it means the EEPROM/Flash has valid contents
            // and either matches the ROM defaults or previously matched and
            // was run-time reconfigured by the user.  In this case, we shall
            // use the contents loaded from EEPROM/Flash.
            break;
        }
#endif
        break;
    }
}

void DisplayIPValue(IP_ADDR IPVal)
{
    BYTE IPDigit[4];
    BYTE i;

    for (i = 0; i < sizeof (IP_ADDR); i++)
    {
        uitoa((WORD) IPVal.v[i], IPDigit);

        if (i == sizeof (IP_ADDR) - 1)
            break;
    }
}

void CheckIfIPChanged(void)
{
    // If the local IP address has changed (ex: due to DHCP lease change)
    // write the new IP address to the LCD display, UART, and Announce
    // service
    if (dwLastIP != AppConfig.MyIPAddr.Val)
    {
        dwLastIP = AppConfig.MyIPAddr.Val;
        DisplayIPValue(AppConfig.MyIPAddr);

#if defined(STACK_USE_ANNOUNCE)
        AnnounceIP();
#endif
    }
}

void BlinkLed1(void)
{
    // Blink LD1 every second.
    if (TickGet() - t >= TICK_SECOND / 2ul)
    {
        t = TickGet();
        LED0_IO ^= 1;
    }
}

void CheckForButtonPressed(void)
{
    if (BUTTON2_IO == 1)
        WriteString("Button 1 is pressed\r\n");
    if (BUTTON3_IO == 1)
        WriteString("Button 1 is pressed\r\n");
}


// UART 2 interrupt handler
// it is set at priority level 2

void __ISR(_UART2_VECTOR, ipl2) IntUart2Handler(void)
{
    // Is this an RX interrupt?
    if (INTGetFlag(INT_SOURCE_UART_RX(UART2)))
    {
        // Clear the RX interrupt Flag
        INTClearFlag(INT_SOURCE_UART_RX(UART2));

        // Echo what we just received.
        PutCharacter(UARTGetDataByte(UART2));


        // Toggle LED to indicate UART activity
        mPORTAToggleBits(BIT_7);

    }

    // We don't care about TX interrupt
    if (INTGetFlag(INT_SOURCE_UART_TX(UART2)))
    {
        INTClearFlag(INT_SOURCE_UART_TX(UART2));
    }
}

