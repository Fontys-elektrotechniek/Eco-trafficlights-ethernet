/******************************************************************************

    USB HID Report (Header File)
    
This file defines constants and data types for the USB HID reports.

*******************************************************************************/
//DOM-IGNORE-BEGIN
/******************************************************************************
 FileName:		
 Dependencies:
 Processor:		
 Hardware:		
 Assembler:		
 Linker:		
 Company:		Microchip Technology, Inc.

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
*******************************************************************/
//DOM-IGNORE-END

//DOM-IGNORE-BEGIN
#ifndef _HID_REPORT_HEADER_FILE
#define _HID_REPORT_HEADER_FILE
//DOM-IGNORE-END

#include "GenericTypeDefs.h"

#define mHIDMakeShortPrefix(tag,size)  ((tag << 2) | (size))

#define HID_LONG_ITEM_PREFIX                0xFE
                                            
#define SIZE_0                              0
#define SIZE_1                              1
#define SIZE_2                              2
#define SIZE_4                              3
                                            
#define TYPE_MAIN                           0
#define TYPE_GLOBAL                         1
#define TYPE_LOCAL                          2
/********************************************************************
 Main
********************************************************************/
#define TAG_INPUT                           ((8 << 2) | TYPE_MAIN)
#define TAG_OUTPUT                          ((9 << 2) | TYPE_MAIN)
#define TAG_FEATURE                         ((11 << 2) | TYPE_MAIN)
#define TAG_COLLECTION                      ((10 << 2) | TYPE_MAIN)
#define TAG_END_COLLECTION                  ((12 << 2) | TYPE_MAIN)
/********************************************************************
 Global
*******************************************************************/
#define TAG_USAGE_PAGE                      ((0 << 2) | TYPE_GLOBAL)
#define TAG_LOGICAL_MIN                     ((1 << 2) | TYPE_GLOBAL)
#define TAG_LOGICAL_MAX                     ((2 << 2) | TYPE_GLOBAL)
#define TAG_PHYSICAL_MIN                    ((3 << 2) | TYPE_GLOBAL)
#define TAG_PHYSICAL_MAX                    ((4 << 2) | TYPE_GLOBAL)
#define TAG_UNIT_EXPONENT                   ((5 << 2) | TYPE_GLOBAL)
#define TAG_UNIT                            ((6 << 2) | TYPE_GLOBAL)
#define TAG_REPORT_SIZE                     ((7 << 2) | TYPE_GLOBAL)
#define TAG_REPORT_ID                       ((8 << 2) | TYPE_GLOBAL)
#define TAG_REPORT_COUNT                    ((9 << 2) | TYPE_GLOBAL)
#define TAG_PUSH                            ((10 << 2) | TYPE_GLOBAL)
#define TAG_POP                             ((11 << 2) | TYPE_GLOBAL)
/********************************************************************
 Local
********************************************************************/
#define TAG_USAGE                           ((0 << 2) | TYPE_LOCAL)
#define TAG_USAGE_MIN                       ((1 << 2) | TYPE_LOCAL)
#define TAG_USAGE_MAX                       ((2 << 2) | TYPE_LOCAL)
#define TAG_DESIGNATOR_IDX                  ((3 << 2) | TYPE_LOCAL)
#define TAG_DESIGNATOR_MIN                  ((4 << 2) | TYPE_LOCAL)
#define TAG_DESIGNATOR_MAX                  ((5 << 2) | TYPE_LOCAL)
#define TAG_STRING_IDX                      ((7 << 2) | TYPE_LOCAL)
#define TAG_STRING_MIN                      ((8 << 2) | TYPE_LOCAL)
#define TAG_STRING_MAX                      ((9 << 2) | TYPE_LOCAL)
#define TAG_DELIMITER                       ((10 << 2) | TYPE_LOCAL)

/********************************************************************
 Main Data
********************************************************************/
#define DATA                                0x0000
#define CONSTANT                            0x0001
#define ARRAY                               0x0000
#define VARIABLE                            0x0002
#define ABSOLUTE                            0x0000
#define RELATIVE                            0x0004
#define NO_WRAP                             0x0000
#define WRAP                                0x0008
#define LINEAR                              0x0000
#define NON_LINEAR                          0x0010
#define PREFERRED_STATE                     0x0000
#define NO_PREFERRED                        0x0020
#define NULL_POSITION                       0x0000
#define NULL_STATE                          0x0040
#define BIT_FIELD                           0x0000
#define BUFFERED_BYTES                      0x0100
                                            
/********************************************************************
 Main Collection
********************************************************************/
#define PHYSICAL                            0x00
#define APPLICATION                         0x01
#define LOGICAL                             0x02
#define REPORT                              0x03
#define NAMED_ARRAY                         0x04
#define USAGE_SWITCH                        0x05
#define USAGE_MODIFIER                      0x06

/********************************************************************
 Usage Page Codes
********************************************************************/
enum
{
    UP_GENERIC_DESKTOP = 1,
    UP_SIMULATION,
    UP_VR,
    UP_SPORT,
    UP_GAME,
    UP_GENERIC_DEVICE,
    UP_KEYBOARD,
    UP_LED,
    UP_BUTTON,
    UP_ORDINAL,
    UP_CONSUMER,
    UP_DIGITIZER,
//  RESERVED,
    UP_PID_PAGE = 0x0F,
    UP_UNICODE,
//  RESERVED,
    UP_ALPANUMERIC_DISPLAY = 0x14,
//  RESERVED,
    UP_MEDICAL_INSTRUMENTS = 0x40,
//  RESERVED,
    UP_MONITOR_PAGES_0 = 0x80,
    UP_MONITOR_PAGES_1,
    UP_MONITOR_PAGES_2,
    UP_MONITOR_PAGES_3,
    UP_POWER_PAGE_0,
    UP_POWER_PAGE_1,
    UP_POWER_PAGE_2,
    UP_POWER_PAGE_3,
//  RESERVED,
    UP_BAR_CODE_SCANNER = 0x8C,
    UP_SCALE_PAGE,
    UP_MAGNETIC_STRIP_READING,
//  RESERVED,
    UP_CAMERA_CONTROL = 0x90,
    UP_ARCADE
};
/********************************************************************
Generic Desktop Page Usage 
********************************************************************/
enum
{
    POINTER     = 1,
    MOUSE,
//  RESERVED,
    JOYSTICK    = 4,
    GAME_PAD,
    KEYBOARD,
    KEYPAD,
    MULTI_AXIS_CONTROLLER,
//  RESERVED,
    X_DV        = 0x30,
    Y_DV,
    Z_DV,
    RX,
    RY,
    RZ,
    SLIDER,
    DIAL,
    WHEEL,
    HAT_SWITCH,
    COUNTED_BUFFER,
    BYTE_COUNT,
    MOTION_WAKEUP,
    START,
    SELECT,
//  RESERVED,
    VX          = 0x40,
    VY,
    VZ,
    VBRX,
    VBRY,    //VBRX,  //incorrect definition????
    VBRZ,
    VNO,
    FEATURE_NOTIFICATION,
//  RESERVED,
    SYSTEM_CONTROL  = 0x80,
    SYSTEM_POWER_DOWN,
    SYSTEM_SLEEP,
    SYSTEM_WAKE_UP,
    SYSTEM_CONTEXT_MENU,
    SYSTEM_MAIN_MENU,
    SYSTEM_APP_MENU,
    SYSTEM_MENU_HELP,
    SYSTEM_MENU_EXIT,
    SYSTEM_MENU_SELECT,
    SYSTEM_MENU_RIGHT,
    SYSTEM_MENU_LEFT,
    SYSTEM_MENU_UP,
    SYSTEM_MENU_DOWN,
    SYSTEM_COLD_RESTART,
    SYSTEM_WARM_RESTART,
    D_PAD_UP,
    D_PAD_DOWN,
    D_PAD_RIGHT,
    D_PAD_LEFT,
//  RESERVED,
    SYSTEM_DOCK     = 0xA0,
    SYSTEM_UNLOCK,
    SYSTEM_SETUP,
    SYSTEM_BREAK,
    SYSTEM_DEBUGGER_BREAK,
    APPLICATION_BREAK,
    APPLICATION_DEBUGGER_BREAK,
    SYSTEM_SPEAKER_MUTE,
    SYSTEM_HIBERNATE,
//  RESERVED,
    SYSTEM_DISPLAY_INVERT   = 0xB0,
    SYSTEM_DISPLAY_INTERNAL,
    SYSTEM_DISPLAY_EXTERNAL,
    SYSTEM_DISPLAY_BOTH,
    SYSTEM_DISPLAY_DUAL,
    SYSTEM_DISPLAY_TOGGLE_INT,
    SYSTEM_DISPLAY_SWAP,
    SYSTEM_DISPLAY_LCD_AUTOSCALE
};


typedef union 
{
    struct
    {
        BYTE    bSize:  2;
        BYTE    bType:  2;
        BYTE    bTag:   4;
    };
    BYTE    _byte;
}HID_ITEM_PREFIX;

typedef union
{
    BYTE    _byte[4];
    WORD    _uint16[2];
    DWORD   _uint32;
}HID_SHORT_DATA;

typedef struct
{
    HID_ITEM_PREFIX     prefix;
    HID_SHORT_DATA      data;
}HID_SHORT_ITEM;

typedef struct
{
    HID_ITEM_PREFIX     prefix;
    BYTE                bDataSize;
    BYTE                bLongItemTag;
    BYTE                data[255];
}HID_LONG_ITEM;
#endif
