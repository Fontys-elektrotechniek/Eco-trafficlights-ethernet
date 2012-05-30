/******************************************************************************

    USB HID Descriptor Header File
    
This file defines data types for the USB HID descriptors.

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

*********************************************************************
File Description:

USB Device HID Class

Change History:
Name         Date            Changes
********************************************************************/
//DOM-IGNORE-END

//DOM-IGNORE-BEGIN
#ifndef _HID_DSC_HEADER_FILE
#define _HID_DSC_HEADER_FILE
//DOM-IGNORE-END

#define HID_RECIPIENT                       1

#define HID_INTERFACE                       3

#define HID_DSC_TYPE                        0x21
#define HID_REPORT_DSC_TYPE                 0x22
#define HID_PHY_DSC_TYPE                    0x23

#define HID_REPORT_TYPE_INPUT               0
#define HID_REPORT_TYPE_OUTPUT              1
#define HID_REPORT_TYPE_FEATURE             2

#define HID_NO_SUBCLASS                     0
#define HID_SUBCLASS_BOOT                   1

#define HID_PROTOCOL_NONE                   0
#define HID_PROTOCOL_KEYBOARD               1
#define HID_PROTOCOL_MOUSE                  2


typedef struct
{
    BYTE    bNumber;                        // Numeric experison specifying the number of Physical Descriptor sets.
    BYTE    bLength[2];                     // Numeric expression identifying the length of each Physical descriptor
}HID_PHY_HDR;

typedef struct
{
    union
    {
        struct
        {
            BYTE    Preference: 5;
            BYTE    Bias:       3;
        }physicalInfoBits;            //TODO: (DF) added member name
        BYTE    bPhysicalInfo;
    }physicalInfo;            //TODO: (DF) added member name

    BYTE    dPhysical[PHYSICAL_INFO_LENGH];       //TODO: (DF) changed the size here so that it was non-zero for C18
}HID_PHY_DSC;
/*********************************************************************
 Bias Values
 *********************************************************************/
enum
{
    NOT_APPLICABLE,
    RIGHT_HAND,
    LEFT_HAND,
    BOTH_HANDS,
    EITHER_HAND
};
/********************************************************************
 Qualifer Value
 ********************************************************************/
enum
{
    N_A,
    RIGHT,
    LEFT,
    BOTH,
    EITHER,
    CENTER
};

typedef struct
{
    BYTE    bDesignator;
    union
    {
        struct
        {
            BYTE    Effort:     5;
            BYTE    Qualifer:   3;
        } flagBits;           //TODO: (DF) added member name
        BYTE    bFlags;
    } flagInfo;           //TODO: (DF) added member name
}HID_PHY_DATA;


typedef struct
{
    BYTE    bDescriptorType;        // Constant name identifying type of class descriptor
    WORD    Length;
} __attribute__((packed)) HID_DSC_HDR;


typedef struct
{
    BYTE            bLength;                // Numeric experison of the total size of the HID desciptor
    BYTE            bDescriptorType;        // Constant name specifying type of HID descriptor
    WORD            bcdHID;                 // Numeric expression identifying the HID class specification release
    BYTE            bCountryCode;           // Numeric expression identifying country code of the localized hardware
    BYTE            bNumDescriptors;        // Numeric expression specifying the number of class descriptors
} __attribute__((packed)) HID_DESCRIPTOR;

/*********************************************************************
 Designator Values
 *********************************************************************/
enum
{
    NONE,
    HAND,
    EYEBALL,
    EYEBROW,
    EYELID,
    EAR,
    NOSE,
    MOUTH,
    UPPER_LIP,
    LOWER_LIP,
    JAW,
    NECK,
    UPPER_ARM,
    ELBOW,
    FOREARM,
    WRIST,
    PALM,
    THUMB,
    INDEX_FINGER,
    MIDDLE_FINGER,
    RING_FINGER,
    LITTLE_FINGER,
    HEAD,
    SHOULDER,
    HIP,
    WAIST,
    THIGH,
    KNEE,
    CALF,
    ANKLE,
    FOOT,
    HEEL,
    BALL_OF_FOOT,
    BIG_TOE,
    SECOND_TOE,
    THIRD_TOE,
    FOURTH_TOE,
    LITTLE_TOE,
    BROW,
    CHEEK
};

/********************************************************************
 Country Codes
 ********************************************************************/
enum
{
    NOT_SUPPORTED,
    ARABIC,
    BELGIAN,
    CANADIAN_BILINGUAL,
    CANADIAN_FRENCH,
    CZECH_REPUBLIC,
    DANISH,
    FINNISH,
    FRENCH,
    GERMAN,
    GREEK,
    HEBREW,
    HUNGARY,
    INTERNATIONAL_ISO,
    ITALIAN,
    JAPAN_KATAKANA,
    KOREAN,
    LATIN_AMERICAN,
    NETHERLANDS_DUTCH,
    NORWEGIAN,
    PERSIAN_FARSI,
    POLAND,
    PORTUGUESE,
    RUSSIA,
    SLOVAKIA,
    SPANISH,
    SWEDISH,
    SWISS_FRENCH,
    SWISS_GERMAN,
    SWITZERLAND,
    TAIWAN,
    TURKISH_Q,
    UK,
    US,
    YUGOSLAVIA,
    TURKISH_F
};

#endif
