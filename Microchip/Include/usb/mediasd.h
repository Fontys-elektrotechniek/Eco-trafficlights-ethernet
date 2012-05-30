/******************************************************************************

       SECURE DIGITAL MEDIA INTERFACE HEADER FILE

This file defines the SD Media Interface.

*******************************************************************************/
//DOM-IGNORE-BEGIN
/******************************************************************************
 * FileName:        MediaSD.h
 * Dependencies:    See include below
 * Processor:       Daytona
 * Compiler:        Daytona
 * Company:         Microchip Technology, Inc.

Software License Agreement
Microchip Technology Incorporated ("Microchip) and its licensors retain 
all ownership and intellectual property rights in the code accompanying 
this message and in all derivatives thereto.  The code and information 
accompanying this message is provided for your convenience and use with 
Microchip products only.  Your acceptance and/or use of this code 
constitute agreement to the terms and conditions of this notice.Microchip 
disclaims all liability arising from this information and its use.  It is 
your responsibility to ensure that your application meets with your 
specifications.Further, the implementation and use of the FAT file system 
accompanying this code, SD card specifications, MMC card specifications 
and other third party tools may require a license from various entities, 
including, but not limited to Microsoft® Corporation, SD Card Association 
and MMCA.  It is your responsibility to obtain more information regarding 
any applicable licensing obligations.

CODE AND INFORMATION ACCOMPANYING THIS MESSAGE IS PROVIDED “AS IS.”  
MICROCHIP AND ITS LICENSORS MAKES NO REPRESENTATION OR WARRANTIES OF ANY 
KIND WHETHER EXPRESS OR IMPLIED, WRITTEN OR ORAL, STATUTORY OR OTHERWISE, 
RELATED TO THE INFORMATION PROVIDED TO YOU, INCLUDING BUT NOT LIMITED TO 
ITS CONDITION, QUALITY, PERFORMANCE, MERCHANTABILITY, NON-INFRINGEMENT, 
OR FITNESS FOR PURPOSE.  MICROCHIP AND ITS LICENSORS ARE NOT LIABLE, UNDER 
ANY CIRCUMSTANCES, FOR SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES, 
FOR ANY REASON WHATSOEVER.  	 
*****************************************************************************/
#ifndef _MEDIASD_H_
#define _MEDIASD_H_
//DOM-IGNORE-END

#include "GenericTypeDefs.h"
#include "sdcard.def"
#include <plib.h>

// PIC32 equivalencies
#if defined (__PIC32MX__)
    #define IOPORT_BIT_0    BIT_0
    #define IOPORT_BIT_1    BIT_1
    #define IOPORT_BIT_2    BIT_2
    #define IOPORT_BIT_3    BIT_3
    #define IOPORT_BIT_4    BIT_4
    #define IOPORT_BIT_5    BIT_5
    #define IOPORT_BIT_6    BIT_6
    #define IOPORT_BIT_7    BIT_7
    #define IOPORT_BIT_8    BIT_8
    #define IOPORT_BIT_9    BIT_9
    #define IOPORT_BIT_10   BIT_10
    #define IOPORT_BIT_11   BIT_11
    #define IOPORT_BIT_12   BIT_12
    #define IOPORT_BIT_13   BIT_13
    #define IOPORT_BIT_14   BIT_14
    #define IOPORT_BIT_15   BIT_15
    #define IOPORT_BIT_16   BIT_16
    #define IOPORT_BIT_17   BIT_17
    #define IOPORT_BIT_18   BIT_18
    #define IOPORT_BIT_19   BIT_19
    #define IOPORT_BIT_20   BIT_20
    #define IOPORT_BIT_21   BIT_21
    #define IOPORT_BIT_22   BIT_22
    #define IOPORT_BIT_23   BIT_23
    #define IOPORT_BIT_24   BIT_24
    #define IOPORT_BIT_25   BIT_25
    #define IOPORT_BIT_26   BIT_26
    #define IOPORT_BIT_27   BIT_27
    #define IOPORT_BIT_28   BIT_28
    #define IOPORT_BIT_29   BIT_29
    #define IOPORT_BIT_30   BIT_30
    #define IOPORT_BIT_31   BIT_31
#endif

#if defined(MEDIASD_IF_SPI1)
#elif defined(MEDIASD_IF_SPI2)
#else
   #error Media SPI port is not defined. See "MEDIASD_IF_XXX" define in fat.def
#endif

#if defined (EXPLORER16_REV_5)
#define SetSPILatch()           {   mPORTBSetPinsDigitalOut(IOPORT_BIT_12 | IOPORT_BIT_13); mPORTBSetBits(IOPORT_BIT_12 | IOPORT_BIT_13);   }
#else
#define SetSPILatch()
#endif
 		
// Hardware interface to SD Card. Modify it as per your hardware.
#if defined(EXPLORER16_REV_1) | defined(EXPLORER16_REV_5)
        
    #if defined(MEDIASD_IF_SPI1)
        
                                             
        #define _SetChipSelect(on)      {   SetSPILatch();\
                                            mPORTBSetPinsDigitalOut(IOPORT_BIT_1);\
                                            if(on)\
                                                mPORTBClearBits(IOPORT_BIT_1);\
                                            else\
                                                mPORTBSetBits(IOPORT_BIT_1);\
                                        }

	                                    
        #define SD_CD                   (mPORTFReadBits(IOPORT_BIT_0))             // Card detect - Read Only
        #define SDSetCDDirection()      mPORTFSetPinsDigitalIn(IOPORT_BIT_0)

                                        
        #define SD_WE                   (mPORTFReadBits(IOPORT_BIT_1))               // Write enable - Read Only
        #define SDSetWEDirection()      mPORTFSetPinsDigitalIn(IOPORT_BIT_1)
    
    #elif defined(MEDIASD_IF_SPI2)

        #define _SetChipSelect(on)      {\
                                            mPORTBSetPinsDigitalOut(IOPORT_BIT_9);\
                                            if(on)\
                                                mPORTBClearBits(IOPORT_BIT_9);\
                                            else\
                                                mPORTBSetBits(IOPORT_BIT_9);\
                                        }

	
        #define SD_CD                   (mPORTGReadBits(IOPORT_BIT_0))               // Card detect - Read Only
        #define SDSetCDDirection()      mPORTGSetPinsDigitalIn(IOPORT_BIT_0)

        #define SD_WE                   (mPORTGReadBits(IOPORT_BIT_1))               // Write enable - Read Only
        #define SDSetWEDirection()      mPORTGSetPinsDigitalIn(IOPORT_BIT_1)
    
    #else
       #error Media SPI port is not defined. See "MEDIASD_IF_XXX" define in fat.def
    #endif
    
#else
        #define _SetChipSelect(on)      {\
                                            mPORTDSetPinsDigitalOut(IOPORT_BIT_8);\
                                            if(on)\
                                                mPORTDClearBits(IOPORT_BIT_8);\
                                            else\
                                                mPORTDSetBits(IOPORT_BIT_8);\
                                        }

	
        #define SD_CD                   (mPORTDReadBits(IOPORT_BIT_9))               // Card detect - Read Only
        #define SDSetCDDirection()      mPORTDSetPinsDigitalIn(IOPORT_BIT_9)

        #define SD_WE                   (mPORTDReadBits(IOPORT_BIT_10))              // Write enable - Read Only
        #define SDSetWEDirection()      mPORTDSetPinsDigitalIn(IOPORT_BIT_10)
        
#endif


#define SD_CMD_IDLE             0
#define SD_CMD_SEND_OP_COND     1
#define SD_CMD_CSD              9
#define SD_CMD_SET_BLOCK_LEN   16
#define SD_CMD_READ_BLOCK      17
#define SD_CMD_WRITE_BLOCK     24

typedef union _MMCstate
{
    struct {
       BYTE isSDMMC : 1;   // Set if it is a SDMMC
       BYTE isWP    : 1;   // Set if it is write protected
    };
    BYTE  _byte;
} MMCSTATE;

typedef union _CARDSTATUS
{
    struct
    {
       BYTE  CS_Inserted:1;  // Card is inserted and initialized
       BYTE  CS_Reset:1;     // Card has just been reset
       BYTE  CS_SDMMC:1;     // Card is of the SDMMC type
       BYTE  CS_WP:1;        // Card is write Protected
       BYTE  CS_Failure:1;   // There was a failure initializing the card
    };
    WORD _word;
} CARDSTATUS;

PUBLIC BOOL MediaInit( CARDSTATUS *cs, UINT pb_clk );
#define MediaIsPresent() (!SD_CD)
#define MediaIsWriteProtected()	(SD_WE)
PUBLIC BOOL MediaReadSector( DWORD Sector, BYTE *pDat );
PUBLIC BOOL MediaWriteSector( DWORD Sector, BYTE *pDat );
PUBLIC void MediaShutDown( void );
PUBLIC BYTE ReadByte( BYTE *pBuffer, WORD index );
PUBLIC WORD ReadWord( BYTE *pBuffer, WORD index );
PUBLIC DWORD ReadDWord( BYTE *pBuffer, WORD index );
PUBLIC BOOL CSDRead(BYTE *buff);

#define MEDIA_SECTOR_SIZE 512


#endif   /* _MEDIASD_H_ */

