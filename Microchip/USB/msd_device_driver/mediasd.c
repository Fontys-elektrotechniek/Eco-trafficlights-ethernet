/******************************************************************************
 *
 *              SECURE DIGITAL MEDIA INTERFACE
 *
 ******************************************************************************
 * FileName:        MediaSD.c
 * Dependencies:    See include below
 * Processor:       Daytona
 * Compiler:        Daytona
 * Company:         Microchip Technology, Inc.
 *
 * Software License Agreement
 * Microchip Technology Incorporated ("Microchip) and its licensors retain 
 * all ownership and intellectual property rights in the code accompanying 
 * this message and in all derivatives thereto.  The code and information 
 * accompanying this message is provided for your convenience and use with 
 * Microchip products only.  Your acceptance and/or use of this code 
 * constitute agreement to the terms and conditions of this notice.Microchip 
 * disclaims all liability arising from this information and its use.  It is 
 * your responsibility to ensure that your application meets with your 
 * specifications.Further, the implementation and use of the FAT file system 
 * accompanying this code, SD card specifications, MMC card specifications 
 * and other third party tools may require a license from various entities, 
 * including, but not limited to Microsoft� Corporation, SD Card Association 
 * and MMCA.  It is your responsibility to obtain more information regarding 
 * any applicable licensing obligations.
 * 
 * CODE AND INFORMATION ACCOMPANYING THIS MESSAGE IS PROVIDED �AS IS.�  
 * MICROCHIP AND ITS LICENSORS MAKES NO REPRESENTATION OR WARRANTIES OF ANY 
 * KIND WHETHER EXPRESS OR IMPLIED, WRITTEN OR ORAL, STATUTORY OR OTHERWISE, 
 * RELATED TO THE INFORMATION PROVIDED TO YOU, INCLUDING BUT NOT LIMITED TO 
 * ITS CONDITION, QUALITY, PERFORMANCE, MERCHANTABILITY, NON-INFRINGEMENT, 
 * OR FITNESS FOR PURPOSE.  MICROCHIP AND ITS LICENSORS ARE NOT LIABLE, UNDER 
 * ANY CIRCUMSTANCES, FOR SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES, 
 * FOR ANY REASON WHATSOEVER.  	 
 *
 *****************************************************************************
 *
 * $Id: MediaSD.c,v 1.4 2006/10/24 16:37:51 C12923 Exp $
 *
 * $Name:  $
 *
 *****************************************************************************/
 
#include <string.h>
#include "mstimer.h"
#include "usb\mediasd.h"

// Default definition of sleep function.  See mstimer.h
#ifndef SleepMS
    #define SleepMS(m) MSTimerWait(m)
#endif
                        

PRIVATE BOOL SD_ProtocolInit(UINT pb_clk);
PRIVATE BYTE TransactR1( BYTE cmdDat, DWORD args );
PRIVATE BYTE TransactR1CRC(BYTE cmdDat, DWORD args, BYTE crc);
PRIVATE BOOL StartupCard( CARDSTATUS *CardStatus, UINT pb_clk );
PRIVATE void StopCard( CARDSTATUS *cs );
PRIVATE BOOL _CSDRead(BYTE *data);

PRIVATE BYTE _csdBuffer[16];

static inline __attribute__((always_inline)) unsigned char SPICalutateBRG(unsigned int pb_clk, unsigned int spi_clk)
{
    unsigned int brg;

    brg = pb_clk / (2 * spi_clk);

    if(pb_clk % (2 * spi_clk))
        brg++;

    if(brg > 0x100)
        brg = 0x100;

    if(brg)
        brg--;

    return (unsigned char) brg;
}

static inline __attribute__((always_inline)) void OpenSPI(unsigned int config1, unsigned int config2)
{
#if defined (MEDIASD_IF_SPI1)
    OpenSPI1(config1, config2);
#else
    OpenSPI2(config1, config2);
#endif
}

static inline  __attribute__((always_inline)) void CloseSPI(void)
{
#if defined (MEDIASD_IF_SPI1)
    CloseSPI1();
#else
    CloseSPI2();
#endif
}

static inline  __attribute__((always_inline)) void putcSPI(unsigned int data_out)
{
#if defined (MEDIASD_IF_SPI1)
    //***putcSPI1(data_out);
    WriteSPI1(data_out);//****
#else
    //***putcSPI2(data_out);
    WriteSPI2(data_out);//****
#endif
}

static inline  __attribute__((always_inline)) unsigned int getcSPI(void)
{
#if defined (MEDIASD_IF_SPI1)
    return getcSPI1();
#else
    return getcSPI2();
#endif
}

static inline  __attribute__((always_inline)) void ChangeSPIBRG(unsigned int brg)
{
#if defined (MEDIASD_IF_SPI1)
    SpiChnSetBrg(1, brg);
#else
    SpiChnSetBrg(2, brg);
#endif
}

PRIVATE inline  __attribute__((always_inline)) BYTE ByteTransfer( BYTE SendByte )
{
    unsigned int rx_data;

    _SetChipSelect(TRUE);
    
    putcSPI((unsigned int) SendByte);

    rx_data = getcSPI();
        
    _SetChipSelect(FALSE);

    return((BYTE)(rx_data & 0xFF));

}   // ByteTransfer()

inline __attribute__ ((always_inline)) void BufferTransfer(BYTE *buffer, UINT size)
{
    unsigned int i;
    
    _SetChipSelect(TRUE);
    
    for(i = 0; i < size; i++)
    {
        putcSPI((unsigned int) *buffer);
        *buffer++;
        getcSPI();

    }
    _SetChipSelect(FALSE);
}
inline __attribute__ ((always_inline)) void BufferReceive(BYTE *buffer, UINT size)
{
    unsigned int i;
    DWORD_VAL data;
    unsigned int remainder;

#if defined (MEDIASD_IF_SPI1)
    SPI1CONCLR = _SPI1CON_MODE16_MASK | _SPI1CON_ON_MASK;
    SPI1CONSET = _SPI1CON_MODE32_MASK | _SPI1CON_ON_MASK;
#else
    SPI2CONCLR = _SPI2CON_MODE16_MASK | _SPI2CON_ON_MASK;
    SPI2CONSET = _SPI2CON_MODE32_MASK | _SPI2CON_ON_MASK;
#endif

    _SetChipSelect(TRUE);
    
    remainder = size & 0x03;
    
    size >>= 2;

    if(size)
    {

        putcSPI(0xFFFFFFFF);

        for(i = 0; i < (size - 1); i++)
        {
            data.Val  = getcSPI();
            putcSPI(0xFFFFFFFF);
        
            buffer[0] = data.v[3];
            buffer[1] = data.v[2];
            buffer[2] = data.v[1];
            buffer[3] = data.v[0];

            buffer += 4;
        }

        data.Val  = getcSPI();
    
        buffer[0] = data.v[3];
        buffer[1] = data.v[2];
        buffer[2] = data.v[1];
        buffer[3] = data.v[0];

        buffer += 4;
    }

#if defined (MEDIASD_IF_SPI1)
    SPI1CONCLR = _SPI1CON_MODE32_MASK | _SPI1CON_MODE16_MASK | _SPI1CON_ON_MASK;
    SPI1CONSET = _SPI1CON_ON_MASK;
#else
    SPI2CONCLR = _SPI2CON_MODE32_MASK | _SPI2CON_MODE16_MASK | _SPI2CON_ON_MASK;
    SPI2CONSET =  _SPI2CON_ON_MASK;
#endif

    for(i = 0; i < remainder; i++)
    {
        putcSPI((unsigned int)0xFF);
        *buffer = getcSPI();
        *buffer++;

    }


    _SetChipSelect(FALSE);

}
inline __attribute__ ((always_inline)) void CheckBusy(void)
{
    BYTE data;

    _SetChipSelect(TRUE);
    
    do
    {
        putcSPI((unsigned int)0xFF);
        data = getcSPI();
    }while(!data);

    _SetChipSelect(FALSE);

}
inline __attribute__ ((always_inline)) BOOL GetStartToken(UINT timeout)
{
    BYTE data;

    _SetChipSelect(TRUE);
    
    do
    {
        putcSPI((unsigned int)0xFF);
        timeout--;
        data = getcSPI();
    }while((data == 0xFF) && (timeout));
    
    _SetChipSelect(FALSE);

    if(data == 0xFE)
        return TRUE;

    return FALSE;
}
inline __attribute__ ((always_inline)) BYTE GetToken(UINT timeout)
{
    BYTE data;

    _SetChipSelect(TRUE);
    
    do
    {
        putcSPI((unsigned int)0xFF);
        timeout--;
        data = getcSPI();
    }while((data == 0xFF) && (timeout));
    
    _SetChipSelect(FALSE);

    return data;
}

/******************************************************************************
 * Function:        BOOL MediaInit( CARDSTATUS *cs, UINT pb_clk  )
 *
 * PreCondition:    None
 *
 * Input:           cs - Pointer to CARDSTATUS structure
 *                  pb_clk - Peripheral clock frequency (Hz)
 *
 * Output:          TRUE - Media initialized successfully
 *                  FALSE - Media failed to initialize
 *
 * Side Effects:    None
 *
 * Overview:        User-called function to initialize the SD Media. 
 *
 * Note:            None
 *****************************************************************************/
PUBLIC BOOL MediaInit( CARDSTATUS *cs, UINT pb_clk )
{
 
    // Setup the I/O
    SDSetCDDirection();     // CD as input
    SDSetWEDirection();     // WE as input

    // Don't need to fail initialize just because media is not present.
    // We will fail when actual operation is performed and media is not present.
    if( !MediaIsPresent() )
       return FALSE;
   
    cs->_word = 0x00;

    if( StartupCard( cs, pb_clk ) != TRUE ) {

       // There was an issue so turn off the card
       StopCard( cs );
       cs->CS_Failure = 1;
       return FALSE;
    }

	

    return( TRUE );

}   // MediaInit()


/******************************************************************************
 * Function:        void MediaShutdown( void )
 *
 * PreCondition:    None
 *
 * Input:           None
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        User-called function to read a specific sector on the media.
 *
 * Note:            None
 *****************************************************************************/
PUBLIC void MediaShutdown( void )
{
    _SetChipSelect(FALSE);      // Turn off Chip Select
    CloseSPI();

}   // MediaShutdown()


/******************************************************************************
 * Function:        BOOL MediaReadSector( DWORD Sector, BYTE *pDat )
 *
 * PreCondition:    None
 *
 * Input:           Sector - Sector location to perform the read
 *                  pDat - Buffer containing data read from the
 *                         sector location on the media. 
 *
 * Output:          TRUE - Write to media was successful
 *                  FALSE - Failure to write to media
 *
 * Side Effects:    None
 *
 * Overview:        User-called function to read a specific sector on the media.
 *
 * Note:            None
 *****************************************************************************/
PUBLIC BOOL MediaReadSector( DWORD Sector, BYTE *pDat )
{
    volatile unsigned int __time;


    if( !MediaIsPresent() )
       return FALSE;

    __time = ReadCoreTimer();
    
    // Convert to byte address
    Sector *= MEDIA_SECTOR_SIZE;

    // Read 1 block Command
    if( TransactR1( SD_CMD_READ_BLOCK, Sector ) )
       return FALSE;

    // Skip the initial block read responce
    if(!GetStartToken(0xFFFF))
        return FALSE;

    /**
    temp = ByteTransfer( 0xFF );
    Cntr = 0;
    while( temp == 0xFF && Cntr++ < 0x300 )
       temp = ByteTransfer( 0xFF );

    if( temp != 0xFE )	// Start Block Token
       return FALSE;
    **/

    BufferReceive(pDat, MEDIA_SECTOR_SIZE);
    
   
    // read CRC
    ByteTransfer( 0xFF );
    ByteTransfer( 0xFF );
    
    // Extra clock pulse as required by spec
    ByteTransfer( 0xFF );

    __time = ReadCoreTimer() - __time;

    return TRUE;

}   // MediaReadSector()


/******************************************************************************
 * Function:        BOOL MediaWriteSector( DWORD Sector, BYTE *pDat )
 *
 * PreCondition:    None
 *
 * Input:           Sector - Sector location to perform the write
 *                  pDat - Buffer containing data to be written to 
 *                         to the sector location on the media.
 *
 * Output:          TRUE - Write to media was successful
 *                  FALSE - Failure to write to media
 *
 * Side Effects:    None
 *
 * Overview:        User-called function to write a specific sector on
 *                  the media.
 *
 * Note:            None
 *****************************************************************************/
PUBLIC BOOL MediaWriteSector( DWORD Sector, BYTE *pDat )
{
    WORD temp;

    if( MediaIsWriteProtected() || !MediaIsPresent() )
       return FALSE;

    // Convert to byte address
    Sector *= MEDIA_SECTOR_SIZE;

    // Write 1 block
    if( TransactR1( SD_CMD_WRITE_BLOCK, Sector ) != 0 )
       return FALSE;

    ByteTransfer( 0xFF );
    ByteTransfer( 0xFF );
    ByteTransfer( 0xFE );   // Start Block Token

    BufferTransfer(pDat, MEDIA_SECTOR_SIZE);

    ByteTransfer( 0xFF );   // CRC
    ByteTransfer( 0xFF );   // CRC

    temp = ByteTransfer( 0xFF ) & 0x1F;   // Read data Response

    if( temp != 0x5 ) {
       // Data rejected by card
       // Extra clock pulse as required by spec
       ByteTransfer( 0xFF );
       ByteTransfer( 0xFF );
       return FALSE;
    }

    CheckBusy();

    // Extra clock pulse as required by spec
    ByteTransfer( 0xFF );
    ByteTransfer( 0xFF );

    return( TRUE );

}   // MediaWriteSector()


/******************************************************************************
 * Function:        BOOL StartupCard( CARDSTATUS *CardStatus )
 *
 * PreCondition:    Called from MediaInit()
 *
 * Input:           CardStatus - Pointer to CARDSTATUS structure
 *
 * Output:          TRUE - SD initialized successfully
 *                  FALSE - Failure to initialize SD
 *
 * Side Effects:    None
 *
 * Overview:        Internal function to startup the SDMMC Card
 *
 * Note:            Should not be called by user
 *****************************************************************************/
PRIVATE BOOL StartupCard( CARDSTATUS *CardStatus, UINT pb_clk )
{
    if( !SD_ProtocolInit(pb_clk) )
       return( FALSE );

    CardStatus->CS_Inserted = 1;
    CardStatus->CS_Reset = 1;

    // Set the type and write protect
    CardStatus->CS_SDMMC = 1;
    CardStatus->CS_WP = MediaIsWriteProtected();

    return( TRUE );

}   // StartupCard()


/******************************************************************************
 * Function:        void StopCard( CARDSTATUS *cs )
 *
 * PreCondition:    Called from either StartupCard() or MediaShutdown()
 *
 * Input:           cs - Status of the card
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        Internal function to cleanly unmount the card and
 *                  update the status.
 *
 * Note:            Should not be called by user
 *****************************************************************************/
PRIVATE void StopCard( CARDSTATUS *cs )
{
    // Turn off the card
    MediaShutdown();

    cs->_word = 0x00;

}   // StopCard()


/******************************************************************************
 * Function:        BOOL SD_ProtocolInit( void )
 *
 * PreCondition:    Called from MediaInit()
 *
 * Input:           None
 *
 * Output:          TRUE - SD protocol initialized successfully
 *                  FALSE - SD protocol initialized failed
 *
 * Side Effects:    None
 *
 * Overview:        Internal function to initialize the SD protocol.
 *
 * Note:            Should not be called user
 *****************************************************************************/
PRIVATE BOOL SD_ProtocolInit(  UINT pb_clk  )
{
    BYTE resp;
    WORD safe_guard;
		
#define FAT16_SPI_START_CFG_1		(PRI_PRESCAL_64_1 | SEC_PRESCAL_8_1 | MASTER_ENABLE_ON | SPI_CKE_ON | SPI_SMP_ON)
#define FAT16_SPI_START_CFG_2		(SPI_ENABLE)

    SleepMS(5);	
	_SetChipSelect(FALSE); 
    SleepMS(5);	
	OpenSPI(FAT16_SPI_START_CFG_1, FAT16_SPI_START_CFG_2);
    SleepMS(5);	        
    // set the baud to 400kHz
    ChangeSPIBRG(SPICalutateBRG(pb_clk, 400000));	
    SleepMS(5);	        

    // send '1' 80 bits with CS de-asserted
    safe_guard = 10;
    do {
    	putcSPI(0xFF);
    	getcSPI();
        safe_guard--;
    }while( safe_guard );
        
       
    safe_guard = 100;

    do
    {
        resp = TransactR1( SD_CMD_IDLE, 0 );
        SleepMS(5);
        safe_guard--;

    }while( resp != 1 && safe_guard );

    if( resp != 1 )
    {
        return FALSE;
    }

    safe_guard = 100;

    do
    {
        resp = TransactR1( SD_CMD_SEND_OP_COND, 0 );
        SleepMS(5);
        safe_guard--;

    }while( resp && safe_guard );


    if( resp ) // Non-zero
    {
        return FALSE;
    }

    // Set block size
    TransactR1( SD_CMD_SET_BLOCK_LEN, MEDIA_SECTOR_SIZE );		

	if(!_CSDRead(_csdBuffer))
    {
        return FALSE;
    }

	
    ChangeSPIBRG(SPICalutateBRG(pb_clk, 25000000));	

    safe_guard = 255;
	
	do
	{
		BYTE buff[MEDIA_SECTOR_SIZE];
		
		if(MediaReadSector(0, buff))
			break;
			
		safe_guard--;
						
	}while(safe_guard);
	
	if(!safe_guard)
    {
        return FALSE;
    }
	
    //*** NOT NEEDED *** ChangeSPIBRG(SPICalutateBRG(pb_clk, 25000000));	

    _SetChipSelect(FALSE);

    return( TRUE );

}   // SD_ProtocolInit()




PUBLIC BOOL CSDRead(BYTE *buff)
{
	memcpy(buff, _csdBuffer, 16);
	
	return TRUE;
}	
/*********************************************************************
 * Function:       
 *
 * PreCondition:    
 *
 * Input:           
 *
 * Output:          
 *
 * Side Effects:    
 *
 * Overview:        
 *
 * Note:           
 ********************************************************************/
PRIVATE BOOL _CSDRead(BYTE *data)
{
    BYTE    result;
    WORD    index;

	_SetChipSelect(TRUE);

    result = TransactR1CRC(SD_CMD_CSD, 0, 0xAF);
    
    index = 0x2FF;
    
    while((result != 0xFE) && (index))
    {
        result = ByteTransfer(0xFF);
        index--;    
    }
    
    if(!index)
    {
        return FALSE;
    }
    
    for(index = 0; index < 16; index++)
        data[index] = ByteTransfer(0xFF);


    ByteTransfer(0xFF);

    _SetChipSelect(FALSE);

    return TRUE;
}

/******************************************************************************
 * Function:        BYTE ReadByte( BYTE *pBuffer, WORD index )
 *
 * PreCondition:    None
 *
 * Input:           None
 *
 * Output:          A byte of data
 *
 * Side Effects:    None
 *
 * Overview:        User-called function to read from a buffer.
 *
 * Note:            None
 *****************************************************************************/
PUBLIC BYTE ReadByte( BYTE *pBuffer, WORD index )
{
    return( pBuffer[index] );

}   // ReadByte()


/******************************************************************************
 * Function:        BYTE ReadWord( BYTE *pBuffer, WORD index )
 *
 * PreCondition:    None
 *
 * Input:           None
 *
 * Output:          A word of data
 *
 * Side Effects:    None
 *
 * Overview:        User-called function to read from a buffer.
 *
 * Note:            None
 *****************************************************************************/
PUBLIC WORD ReadWord( BYTE *pBuffer, WORD index )
{
    BYTE loByte, hiByte;
    WORD res;

    loByte = pBuffer[index];
    hiByte = pBuffer[index+1];
    res = hiByte;
    res *= 0x100;
    res |= loByte;
    return( res );

}   // ReadWord()


/******************************************************************************
 * Function:        DWORD ReadDWord( BYTE *pBuffer, WORD index )
 *
 * PreCondition:    None
 *
 * Input:           None
 *
 * Output:          Data
 *
 * Side Effects:    None
 *
 * Overview:        User-called function to read from a buffer.
 *
 * Note:            None
 *****************************************************************************/
PUBLIC DWORD ReadDWord( BYTE *pBuffer, WORD index )
{
    BYTE loWord, hiWord;
    DWORD result;

    loWord = ReadWord( pBuffer, index );
    hiWord = ReadWord( pBuffer, index+2 );

    result = hiWord;
    result *= 0x10000;
    result |= loWord;
    return result;

}   // ReadDWord()


/*********************************************************************
 * Function:       
 *
 * PreCondition:    
 *
 * Input:           
 *
 * Output:          
 *
 * Side Effects:    
 *
 * Overview:        
 *
 * Note:           
 ********************************************************************/

PRIVATE BYTE TransactR1( BYTE cmdDat, DWORD args )
{
    WORD        xdat;
	BYTE		command[6];
	
	command[0] = cmdDat | 0x40;
	command[1] = (BYTE)(args >> 24);
	command[2] = (BYTE)(args >> 16);
	command[3] = (BYTE)(args >> 8);
	command[4] = (BYTE)(args);
	command[5] = 0x95;
   
   	BufferTransfer(command, 6);
   	
    
    xdat = GetToken(0xFFFF);

    // Send out extra clock pulse as required by spec
    ByteTransfer( 0xFF );


    return( xdat );

}   // TransactR1()
PRIVATE BYTE TransactR1CRC(BYTE cmdDat, DWORD args, BYTE crc)
{
     WORD temp, xdat;
    DWORD_VAL cmdArgs;
    
    cmdArgs = (DWORD_VAL)args;

    // Shift out the command data
    xdat = ByteTransfer( cmdDat | 0x40 );

    // Now transmit the 4 arg bytes - msb first
    for( temp = 0; temp < 4; temp++ )
       xdat = ByteTransfer( cmdArgs.v[3-temp] );

    // Transmit CRC - only used in the IDLE command
    xdat = ByteTransfer( crc );

    // Send out extra 8 bits
    xdat = ByteTransfer( 0xff );

    // Read Responce
    xdat = ByteTransfer( 0xff );

    // Send out extra clock pulse as required by spec
    ByteTransfer( 0xFF );

    return( xdat );
	
}


