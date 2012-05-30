/******************************************************************************

    USB Mass Storage Device (MSD) Function Driver (Header File)
    
This file defines the USB MSD Function Driver's interface.
*******************************************************************************/
//DOM-IGNORE-BEGIN
/******************************************************************************
 * FileName:		MSD.h
 * Dependencies:
 * Processor:				
 * Hardware:		
 * Assembler:		
 * Linker:		
 * Company:		Microchip Technology, Inc.

 Software License Agreement:
 The software supplied herewith by Microchip Technology Incorporated
 (the “Company”) for its PICmicro® Microcontroller is intended and
 supplied to you, the Company’s customer, for use solely and
 exclusively on Microchip PICmicro Microcontroller products. The
 software is owned by the Company and/or its supplier, and is
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

********************************************************************
 File Description:

 USB Mass Storage Device

 Change History:
 Name				Date            Changes
 Sean Justice		07/10/06		Initial Version
 ********************************************************************/

#ifndef _MSD_HEADER_FILE
#define _MSD_HEADER_FILE
//DOM-IGNORE-END

#include "GenericTypeDefs.h"
#include "usb/usb.h"
#include "usb/mediasd.h"

#define MSD_INTERFACE                       0x08
#define MSD_INTERFACE_SUBCLASS              0x06
#define MSD_PROTOCOL                        0x50

#define MSD_USB_DEVICE_CONFIG               0                       // <-- USB configuration settings that might need to be changed
#define MSD_BUFFER_SIZE                     MEDIA_SECTOR_SIZE
#define MSD_EP_IN_SIZE                      32
#define MSD_EP_OUT_SIZE                     64
#define MSD_USB_ENDPNT                      USB_EP1
#define MSD_CBW_SIZE                        31
#define MSD_CBW_SIGNATURE                   0x43425355
#define MSD_CSW_SIGNATURE                   0x53425355

PUBLIC BOOL MSDInit(unsigned long flags);
PUBLIC BOOL MSDEventhandler(USB_EVENT event, void *data, UINT size);

#endif
