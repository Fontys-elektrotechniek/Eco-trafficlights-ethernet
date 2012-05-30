/******************************************************************************

    USB Human Interface Device (HID) Function Driver (Header File)

This file defines the HID Function Driver's interface.
 ******************************************************************************/
//DOM-IGNORE-BEGIN
/******************************************************************************

 * FileName:
 * Dependencies:
 * Processor:
 * Hardware:
 * Assembler:
 * Linker:
 * Company:         Microchip Technology, Inc.

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

 USB Device HID Class

 Change History:
 Name         Date            Changes
 ********************************************************************/

#ifndef _HID_HEADER_FILE
#define _HID_HEADER_FILE
//DOM-IGNORE-END

#include "usb/hidreport.h"
#include "usb/hidDesc.h"

/* These items can be overridden by the application **/

#ifndef HID_NUM_DSC
    #define HID_NUM_DSC                         1
#endif

#ifndef HID_EP_IN_SIZE
    #define HID_EP_IN_SIZE                      16
#endif

#ifndef HID_MAX_REPORT_SIZE
    #define HID_MAX_REPORT_SIZE                 64
#endif

#ifndef HID_NUM_REPORTS
    #define HID_NUM_REPORTS                     1
#endif

#ifndef mHIDOpenTimer
    #define mHIDOpenTimer(config, period)       OpenTimer1(config, period)
#endif

#ifndef mHIDConfigIntTimer
    #define mHIDConfigIntTimer(config)          ConfigIntTimer1(config)
#endif

#ifndef mHIDEnableTimerInt
    #define mHIDEnableTimerInt()                EnableIntT1
#endif

#ifndef mHIDDisableTimerInt
    #define mHIDDisableTimerInt()               DisableIntT1
#endif

#ifndef mHIDTimerIntHandler
    #define mHIDTimerIntHandler                 Timer1IntHandler
#endif

#ifndef mHIDClearInt
    #define mHIDClearInt()                      mT1ClearIntFlag()
#endif

#ifndef HID_INT_CONFIG
    #define HID_INT_CONFIG                      (T1_INT_OFF | T1_INT_PRIOR_2 | T1_INT_SUB_PRIOR_1)
#endif

#ifndef HID_TIMER_CONFIG
    #define HID_TIMER_CONFIG                    (T1_ON)
#endif

#ifndef _HID_TIMER_VECTOR_
    #define _HID_TIMER_VECTOR_                  _TIMER_1_VECTOR
#endif

#ifndef HID_EP_IN
    #define HID_EP_IN                           USB_EP1
#endif

/** End of items that can be overridden **/


PUBLIC BOOL HIDInit(unsigned long flags);
PUBLIC BOOL HIDEventHandler(USB_EVENT event, void *data, UINT size);
PUBLIC BOOL HIDSendReport(BYTE id, void *data, UINT size, BOOL change);
PUBLIC BYTE *HIDGetIdleTime(BYTE report_id);
PUBLIC void HIDSetReady(BOOL ready);
PUBLIC BOOL HIDIsReady(void);
#define HIDSignalResume USBDEVSignalResume
PUBLIC BOOL HIDSignalResume(void);

// note need to place in RAM
extern BYTE HIDReport[];
extern const UINT HIDReportSize;
#endif
