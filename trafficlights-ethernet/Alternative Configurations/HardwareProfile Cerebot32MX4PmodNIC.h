/************************************************************************/
/*										                        		*/
/*					HardwareProfileCerebot32MX4PmodNIC.h				*/
/*											                        	*/
/*											                        	*/
/************************************************************************/
/*	Author: 	Jesse Adams									           	*/
/*	Copyright 2011, Digilent Inc.					            		*/
/************************************************************************/
/*  Module Description: 						                		*/
/*											                        	*/
/*	This file contains hardware descriptions for the Cerebot 32MX4 and 	*/
/*	the PmodNIC.														*/
/*                                                                      */
/************************************************************************/
/*  Revision History:						                			*/
/*											                        	*/
/*	01/13/2010 (JesseA): created			                			*/
/*											                        	*/
/************************************************************************/

#ifndef HARDWARE_PROFILE_H
#define HARDWARE_PROFILE_H

#include "Compiler.h"

// Define a macro describing this hardware set up (used in other files)
#define CEREBOT32MX4

// Set configuration fuses (but only in MainDemo.c where THIS_IS_STACK_APPLICATION is defined)
#if defined(SET_FUSES_CEREBOT32MX4)
	#pragma config FPLLODIV = DIV_1, FPLLMUL = MUL_20, FPLLIDIV = DIV_2, FWDTEN = OFF, FPBDIV = DIV_1, POSCMOD = XT, FNOSC = PRIPLL, CP = OFF, FSOSCEN = OFF, IESO = OFF
#endif


// Clock frequency values
// These directly influence timed events using the Tick module.  They also are used for UART and SPI baud rate generation.
#define GetSystemClock()		(80000000ul)			// Hz
#define GetInstructionClock()	(GetSystemClock()/1)	// Normally GetSystemClock()/4 for PIC18, GetSystemClock()/2 for PIC24/dsPIC, and GetSystemClock()/1 for PIC32.  Might need changing if using Doze modes.
#define GetPeripheralClock()	(GetSystemClock()/1)	// Normally GetSystemClock()/4 for PIC18, GetSystemClock()/2 for PIC24/dsPIC, and GetSystemClock()/1 for PIC32.  Divisor may be different if using a PIC32 since it's configurable.

// Hardware I/O pin mappings

// CEREBOT 32MX4 + PIC32MX460F512L + PmodNIC (ENC28J60)connected to SPI2 (port JB of the board)

#define LED0_TRIS			(TRISBbits.TRISB10)
#define LED0_IO				(LATBbits.LATB10)	
#define LED1_TRIS			(TRISBbits.TRISB11)
#define LED1_IO				(LATBbits.LATB11)
#define LED2_TRIS			(TRISBbits.TRISB12)
#define LED2_IO				(LATBbits.LATB12)
#define LED3_TRIS			(TRISBbits.TRISB13)
#define LED3_IO				(LATBbits.LATB13)
#define LED4_TRIS			(TRISAbits.TRISA9)	// The Cerebot 32MX4 only has LEDs 1 through 4 (0 to 3), thus 4 through 7 here
#define LED4_IO				(LATAbits.LATA9)
#define LED5_TRIS			(TRISAbits.TRISA10)	// do nothing.  Connect a PmodLED to pins 7 through 12 of port JK on the Cerebot 32MX4 to verify.
#define LED5_IO				(LATAbits.LATA10)
#define LED6_TRIS			(TRISDbits.TRISD12)
#define LED6_IO				(LATDbits.LATD12)
#define LED7_TRIS			(TRISCbits.TRISC4)
#define LED7_IO				(LATCbits.LATC4)
#define LED_GET()			(*((volatile unsigned char*)(&LATB)))
#define LED_PUT(a)			(*((volatile unsigned char*)(&LATB)) = (a))

//Buttons on digilent boards read Logic High when they are pressed and Logic Low when not.  This is opposite of Microchip development boards.
#define BUTTON0_TRIS		(TRISAbits.TRISA6)
#define	BUTTON0_IO			!(PORTAbits.RA6)
#define BUTTON1_TRIS		(TRISAbits.TRISA7)
#define	BUTTON1_IO			!(PORTAbits.RA7)
#define BUTTON2_TRIS		(TRISDbits.TRISD14)	//The Cerebot 32MX4 does only has buttons 1 and 2, thus 2 and 3 here are 
#define	BUTTON2_IO			!(PORTDbits.RD14)
#define BUTTON3_TRIS		(TRISDbits.TRISD15)	//connected by a PmodSWT on Port JE.
#define	BUTTON3_IO			!(PORTDbits.RD15)

#define UARTTX_TRIS			(TRISFbits.TRISF5)	// This is connected to pin 4 of JH on the Cerebot 32MX4
#define UARTTX_IO			(PORTFbits.RF5)
#define UARTRX_TRIS			(TRISFbits.TRISF4)	// This is connected to pin 3 of JH on the Cerebot 32MX4
#define UARTRX_IO			(PORTFbits.RF4)

// Encoder
#define ENC_IN_SPI2

// ENC28J60 I/O pins
#define ENC_CS_TRIS			(TRISGbits.TRISG9)	// Pin 1 on the PmodNIC.  Pin JB1 of Cerebot 32MX4.
#define ENC_CS_IO			(PORTGbits.RG9)
#define ENC_RST_TRIS		(TRISDbits.TRISD4)	// Pin 9 on the PmodNIC.  Pin JB9 of the Cerebot 32MX4.
#define ENC_RST_IO			(PORTDbits.RD4)
// SPI SCK, SDI, SDO pins are automatically controlled by the 
//PIC32 SPI module 
//SPI2 definitions
#define ENC_SPI_IF			(IFS1bits.SPI2RXIF)
#define ENC_SSPBUF			(SPI2BUF)
#define ENC_SPISTATbits		(SPI2STATbits)
#define ENC_SPICON1			(SPI2CON)
#define ENC_SPICON1bits		(SPI2CONbits)
#define ENC_SPIBRG			(SPI2BRG)

// Select which UART the STACK_USE_UART and STACK_USE_UART2TCP_BRIDGE 
// options will use.  You can change these to U1BRG, U1MODE, etc. if you 
// want to use the UART1 module instead of UART2.
#define UBRG				U2BRG
#define UMODE				U2MODE
#define USTA				U2STA
#define BusyUART()			BusyUART2()
#define CloseUART()			CloseUART2()
#define ConfigIntUART(a)	ConfigIntUART2(a)
#define DataRdyUART()		DataRdyUART2()
#define OpenUART(a,b,c)		OpenUART2(a,b,c)
#define ReadUART()			ReadUART2()
#define WriteUART(a)		WriteUART2(a)
#define getsUART(a,b,c)		getsUART2(a,b,c)
#define putsUART(a)			putsUART2(a)
#define getcUART()			getcUART2()
#define putcUART(a)			do{while(BusyUART()); WriteUART(a); while(BusyUART()); }while(0)
#define putrsUART(a)		putrsUART2(a)

#endif
