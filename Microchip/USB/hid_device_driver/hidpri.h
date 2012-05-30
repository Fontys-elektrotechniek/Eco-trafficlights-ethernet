/******************************************************************************

    USB Device Abstraction Layer
    
This file contains declarations that are local to the HID function driver.

 * Filename:        hidpri.h
 * Dependancies:    TBD
 * Processor:       TBD
 * Hardware:        TBD
 * Assembler:       TBD
 * Linker:          TBD
 * Company:         Microchip Technology, Inc.

Software License Agreement

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

Author          Date    Comments
--------------------------------------------------------------------------------
SJ              2006    Initial Creation

*******************************************************************************/

#ifdef _HID_PRIVATE_HEADER_FILE

#define HID_REQ_GET_REPORT                  0x01
#define HID_REQ_GET_IDLE                    0x02
#define HID_REQ_GET_PROTOCOL                0x03
#define HID_REQ_SET_REPORT                  0x09
#define HID_REQ_SET_IDLE                    0x0A
#define HID_REQ_SET_PROTOCOL                0x0B

#define HID_GET_DSC_REQ_HID                 0x21
#define HID_GET_DSC_REQ_REPORT              0x22
#define HID_GET_DSC_REQ_PHY                 0x23

#define HID_BOOT_PROTOCOL                   0
#define HID_REPORT_PROTOCOL                 1

typedef struct
{
    BYTE    id;
    BYTE    data[HID_MAX_REPORT_SIZE];
}HID_REPORT_DATA;

typedef struct
{
    BYTE            report_id;
    volatile BYTE   time_remaining;
    BYTE            idle_time;
    BOOL            no_report;
}HID_IDLE_TIME;

typedef BOOL (*PTR_HIDHANDLER)(void *, unsigned int *);
typedef UINT (*PTR_HIDREPORT)(void *); 

typedef struct
{
    UINT                id;
    PTR_HIDHANDLER      reportHandler;
    PTR_HIDREPORT       getReport;
}HID_REPORT_HANDLER;

typedef struct
{
    union
    {
        BYTE bmRequestType;
        struct
        {
            BYTE    recipient:  5;
            BYTE    type:       2;
            BYTE    tx_dir:     1;
        }requestBits;       //TODO: (DF) - C18 doesn't allow anonymous members
    }requestType;       //TODO: (DF) - C18 doesn't allow anonymous members

    BYTE    bRequest;
    
    union
    {
        /***********************************
         * standard chapter 9 setup packet
         ***********************************/
        struct
        {
            WORD    wValue;
            WORD    wIndex;
            WORD    wLength;
        }setupPacket;          //TODO: (DF) - C18 doesn't allow anonymous members
        /***********************************
         * Descriptor Request
         ***********************************/
        struct
        {
            BYTE    descriptorIdx;
            BYTE    descriptorType;
            WORD    interfaceNumber;
            WORD    descriptorLength;
        }descriptorRequest;       //TODO: (DF) - C18 doesn't allow anonymous members
        /***********************************
         * Report Request
         ***********************************/
        struct
        {
            BYTE    reportID;
            BYTE    reportType;
            WORD    interfaceNumber;
            WORD    reportLength;
        }reportRequest;       //TODO: (DF) - C18 doesn't allow anonymous members
        /***********************************
         * Idle Request
         ***********************************/
        struct
        {
            BYTE    reportID;
            BYTE    duration;
            WORD    interfaceNumber;
            WORD    length;
        }idleRequest;       //TODO: (DF) - C18 doesn't allow anonymous members
        /***********************************
         * Protocol Request
         ***********************************/
        struct
        {
            WORD    protocol;
            WORD    interfaceNumber;
            WORD    length;
        }protocolRequest;       //TODO: (DF) - C18 doesn't allow anonymous members
    }ch9Packets;       //TODO: (DF) - C18 doesn't allow anonymous members
}HID_STANDARD_REQ;


PRIVATE WORD HIDIdlePeriodValue(DWORD sys_clk, BYTE *pre_scale);
PRIVATE BOOL HIDHandleRequests(SETUP_PKT *setup);
PRIVATE BYTE *HIDGetProtocol(void);
PRIVATE BOOL HIDSetProtocol(BYTE protocol);
PRIVATE BYTE *HIDGetReport(BYTE report_type, BYTE report_id, UINT *size);
PRIVATE void HIDSetReport(BYTE report_type, BYTE report_id);
PRIVATE void HIDSetIdleTime(BYTE report_Id, BYTE idle_time);

#endif

