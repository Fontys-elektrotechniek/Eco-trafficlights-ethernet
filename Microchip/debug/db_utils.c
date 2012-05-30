/***********************************************************************************
                db_utils
 ***********************************************************************************
 FileName:        db_utils.c
 Dependencies:    None
 Processor:       PIC32
 
 Complier:        MPLAB C Compiler for PIC32 v1.04
                  MPLAB IDE v8.15 or higher
 Company:         Microchip Technology, Inc.
 
 Copyright (c) 2008 Microchip Technology, Inc.
 Software License Agreement
 
 The software supplied herewith by Microchip Technology Incorporated
 (the “Company”) for its PIC32 Microcontroller is intended
 and supplied to you, the Company’s customer, for use solely and
 exclusively on Microchip PIC32 Microcontroller products.
 The software is owned by the Company and/or its supplier, and is
 protected under applicable copyright laws. All rights are reserved.
 Any use in violation of the foregoing restrictions may subject the
 user to criminal sanctions under applicable laws, as well as to
 civil liability for the breach of the terms and conditions of this
 license.
 
 THIS SOFTWARE IS PROVIDED IN AN “AS IS” CONDITION. NO WARRANTIES,
 WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED
 TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. THE COMPANY SHALL NOT,
 IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL OR
 CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 
 *****************************************************************************
 To compile:     pic32-gcc -c db_utils.c
 To create lib:  pic32-ar  -r db_utils.a db_utils.c
 *****************************************************************************
 * Change History:
 * ID			Date            Changes
 * C11842		10/24/2008		added implementation for DBINIT()
 *****************************************************************************
*/

unsigned int __attribute__ (( noinline,nomips16)) db_init(void)
{
	return(0);
}

void  __attribute__ (( noinline,nomips16 )) db_puts(const unsigned char *s, int len)
{
	asm volatile ("li $v0, 1; sdbbp 1" ::: "v0");
}

void  __attribute__ (( noinline,nomips16 )) db_gets(unsigned char *s, int len)
{
	asm volatile ("li $v0, 2; sdbbp 1" ::: "v0");
}

void  __attribute__ (( noinline,nomips16 )) db_set_count(unsigned int val)
{
	asm volatile ("mtc0 %0,$9,0" :: "r"(val));
}

unsigned long  __attribute__ (( noinline,nomips16 )) db_get_count()
{
	unsigned long ret;
	asm volatile ("mfc0 %0,$9,0" : "=r"(ret));
	return ret;
}

void _mon_write (const char * s, unsigned int count)
{
  /* Do not try to output an empty string */
  if (!s)
    return;

	db_puts(s, count);
}

