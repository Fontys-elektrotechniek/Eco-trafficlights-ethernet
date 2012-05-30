/********************************************************************
 *
 *                  debug utility interface.
 *
 *********************************************************************
 * FileName:        db_utils.h
 * Dependencies:    None
 * Processor:       PIC32
 *
 * Complier:        MPLAB C Compiler for PIC32 v1.04
 *                  MPLAB IDE 8.15 or higher
 * Company:         Microchip Technology, Inc.
 *
 * Copyright (c) 2008 Microchip Technology, Inc.
 *
 * Software License Agreement
 *
 * The software supplied herewith by Microchip Technology Incorporated
 * (the “Company”) for its PIC32 Microcontroller is intended
 * and supplied to you, the Company’s customer, for use solely and
 * exclusively on Microchip PIC32 Microcontroller products.
 * The software is owned by the Company and/or its supplier, and is
 * protected under applicable copyright laws. All rights are reserved.
 * Any use in violation of the foregoing restrictions may subject the
 * user to criminal sanctions under applicable laws, as well as to
 * civil liability for the breach of the terms and conditions of this
 * license.
 *
 * THIS SOFTWARE IS PROVIDED IN AN “AS IS” CONDITION. NO WARRANTIES,
 * WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED
 * TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 * PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. THE COMPANY SHALL NOT,
 * IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL OR
 * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 *********************************************************************
 * Change History:
 * ID			Date            Changes
 * C11842		10/24/2008		added implementation for DBINIT()
 * C11842		11/11/2008		added __DEBUG conditional macro expansion
 *********************************************************************
 * This file should be included in the project for the debug print utility
 *********************************************************************/
 
#ifndef _DB_UTILS_H_
#define _DB_UTILS_H_

 
// Debug function prototypes
unsigned int __attribute__ (( noinline,nomips16 )) db_init(void);
void         __attribute__ (( noinline,nomips16 )) db_puts(const unsigned char *s, int len);
void         __attribute__ (( noinline,nomips16 )) db_gets(unsigned char *s, int len);
void _mon_write (const char * s, unsigned int count);

// Pre-defined debug IO configurations:
//
// Define the appropriate label to select the desired 
// debug IO configuration before including this file.
#if defined(PIC32_STARTER_KIT) && defined(__DEBUG)
	#define DBINIT()			db_init()
	#define DBPUTC(c)			db_puts(c,1)
	#define DBPUTS(s)			db_puts(s, strlen(s))
	#define DBPRINTF			printf
	#define DBGETS(s,len)		db_gets(s, len)
	#define DBGETC(c)			db_gets(c,1)
#elif defined(UART2_IO)
	#define DBINIT()            UART2Init()
	#define DBPUTC(c)           UART2PutChar(c)
	#define DBPUTS(s)           UART2PrintString(s)
	#define DBPRINTF
	#define DBGETS(s,len)
	#define DBGETC(c)           (*(c)=UART2GetChar())
#endif

// Default "NULL" definitions (can be overridden)
#ifndef DBINIT
	#define DBINIT()
#endif
#ifndef DBPUTC
	#define DBPUTC(c)
#endif
#ifndef DBPUTS
	#define DBPUTS(s)
#endif
#ifndef DBPRINTF
	#define DBPRINTF
#endif
#ifndef DBGETS
	#define DBGETS(s,len)
#endif
#ifndef DBGETC
	#define DBGETC(c)
#endif

#endif // _DB_UTILS_H_

