/********************************************************************
 * FileName:		MSD.h
 * Dependencies:
 * Processor:				
 * Hardware:		
 * Assembler:		
 * Linker:		
 * Company:		Microchip Technology, Inc.
 *
 * Software License Agreement:
 * The software supplied herewith by Microchip Technology Incorporated
 * (the “Company”) for its PICmicro® Microcontroller is intended and
 * supplied to you, the Company’s customer, for use solely and
 * exclusively on Microchip PICmicro Microcontroller products. The
 * software is owned by the Company and/or its supplier, and is
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
 * File Description:
 *
 * USB Mass Storage Device
 *
 * Change History:
 * Name				Date            Changes
 * Sean Justice		07/10/06		Initial Version
 ********************************************************************/

#ifdef _MSD_USE_PRIVATE_HEADER_FILE

#define MSD_USB_RX                          XFLAGS(MSD_USB_ENDPNT | USB_RECEIVE)
#define MSD_USB_TX                          XFLAGS(MSD_USB_ENDPNT | USB_TRANSMIT)
#define MSD_INQUIRY_VERSION                 4           // device complies to ANSI INCITS 351-2001 (SPC-2)
#define MSD_INQUIRY_RESPONSE                2
#define MSD_INQUIRY_LENGTH                  (36-4)      // (n - 4)

#define MSD_RESET                           0xFF
#define MSD_GET_MAX_LUN                     0xFE

/* SCSI Transparent Command Set Sub-class code */
#define MSD_INQUIRY 						0x12
#define MSD_READ_FORMAT_CAPACITY 			0x23			 
#define MSD_READ_CAPACITY 					0x25
#define MSD_READ_10 						0x28
#define MSD_WRITE_10 						0x2a
#define MSD_REQUEST_SENSE 					0x03
#define MSD_MODE_SENSE 						0x1a
#define MSD_PREVENT_ALLOW_MEDIUM_REMOVAL 	0x1e
#define MSD_TEST_UNIT_READY 				0x00
#define MSD_VERIFY 							0x2f
#define MSD_STOP_START 						0x1b

// Command Block Status Values
typedef enum
{
    MSD_CSW_STATUS_PASSED = 0,
    MSD_CSW_STATUS_FAILED,
    MSD_CSW_STATUS_PHASE_ERR
}MSD_CSW_STATUS;

/* Sense Key Error Codes */
enum
{
    MSD_S_KEY_ERR_NO_SENSE = 0,
    MSD_S_KEY_ERR_RECOVERED_ERROR,
    MSD_S_KEY_ERR_NOT_READY,
    MSD_S_KEY_ERR_MEDIUM_ERROR,
    MSD_S_KEY_ERR_HARDWARE_ERROR,
    MSD_S_KEY_ERR_ILLEGAL_REQUEST,
    MSD_S_KEY_ERR_UNIT_ATTENTION,
    MSD_S_KEY_ERR_DATA_PROTECT,
    MSD_S_KEY_ERR_BLANK_CHECK,
    MSD_S_KEY_ERR_VENDOR_SPECIFIC,
    MSD_S_KEY_ERR_COPY_ABORTED,
    MSD_S_KEY_ERR_ABORTED_COMMAND,
    MSD_S_KEY_ERR_OBSOLETE,
    MSD_S_KEY_ERR_VOLUME_OVERFLOW,
    MSD_S_KEY_ERR_MISCOMPARE
};

// Sense Response Code
#define MSD_S_RESPONSE_CURRENT                                  0x70
#define MSD_S_RESPONSE_DEFERRED                                 0x71

// ASC & ASCQ Codes for Sense Data (only those that we plan to use) 
// with sense key Illegal request for a command not supported
#define MSD_S_ASC_INVALID_COMMAND_OPCODE                        0x20
#define MSD_S_ASCQ_INVALID_COMMAND_OPCODE                       0x00

// from SPC-3 Table 185
// with sense key Illegal Request for test unit ready
#define MSD_S_ASC_LOGICAL_UNIT_NOT_SUPPORTED                    0x25
#define MSD_S_ASCQ_LOGICAL_UNIT_NOT_SUPPORTED                   0x00

// with sense key Not ready
#define MSD_S_ASC_LOGICAL_UNIT_DOES_NOT_RESPOND                 0x05
#define MSD_S_ASCQ_LOGICAL_UNIT_DOES_NOT_RESPOND                0x00

#define MSD_S_ASC_MEDIUM_NOT_PRESENT                            0x3a
#define MSD_S_ASCQ_MEDIUM_NOT_PRESENT                           0x00

#define MSD_S_ASC_LOGICAL_UNIT_NOT_READY_CAUSE_NOT_REPORTABLE   0x04
#define MSD_S_ASCQ_LOGICAL_UNIT_NOT_READY_CAUSE_NOT_REPORTABLE  0x00

#define MSD_S_ASC_LOGICAL_UNIT_IN_PROCESS                       0x04
#define MSD_S_ASCQ_LOGICAL_UNIT_IN_PROCESS                      0x01

#define MSD_S_ASC_LOGICAL_UNIT_NOT_READY_INIT_REQD              0x04
#define MSD_S_ASCQ_LOGICAL_UNIT_NOT_READY_INIT_REQD             0x02

#define MSD_S_ASC_LOGICAL_UNIT_NOT_READY_INTERVENTION_REQD      0x04
#define MSD_S_ASCQ_LOGICAL_UNIT_NOT_READY_INTERVENTION_REQD     0x03

#define MSD_S_ASC_LOGICAL_UNIT_NOT_READY_FORMATTING             0x04
#define MSD_S_ASCQ_LOGICAL_UNIT_NOT_READY_FORMATTING            0x04

#define MSD_S_ASC_LOGICAL_BLOCK_ADDRESS_OUT_OF_RANGE            0x21
#define MSD_S_ASCQ_LOGICAL_BLOCK_ADDRESS_OUT_OF_RANGE           0x00

#define MSD_S_ASC_WRITE_PROTECTED                               0x27
#define MSD_S_ASCQ_WRITE_PROTECTED                              0x00

typedef enum
{
    MSD_WAIT,
    MSD_SERVICE
}MSD_STATES;

typedef struct
{
    BYTE    peripheralDeviceType:   5;
    BYTE    peripheralQualifier:    3;
    
    BYTE    reserved:               7;
    BYTE    rmb:                    1;
    
    BYTE    version;
    
    BYTE    responseDataFormat:     4;
    BYTE    hisup:                  1;
    BYTE    normaca:                1;
    BYTE    obsolete:               2;
    
    BYTE    additionLength;
    
    BYTE    protect:                1;
    BYTE    reserved2:              2;
    BYTE    _3pc:                   1;
    BYTE    tpgs:                   2;
    BYTE    acc:                    1;
    BYTE    sccs:                   1;

    BYTE    addr16:                 1;
    BYTE    obsolete2:              2;
    BYTE    mchngr:                 1;
    BYTE    multip:                 1;
    BYTE    vs:                     1;
    BYTE    encserv:                1;
    BYTE    bque:                   1;

    BYTE    vs2:                    1;
    BYTE    cmdQue:                 1;
    BYTE    obsolete3:              1;
    BYTE    linked:                 1;
    BYTE    sync:                   1;
    BYTE    wusb16:                 1;
    BYTE    obsolete4:              2;

    BYTE    t10VendorId[8];
    BYTE    productId[16];
    BYTE    productRev[4];
} __attribute__((packed)) MSD_INQUIRY_DATA;

typedef struct
{
    BYTE    responceCode:   7;
    BYTE    valid:          1;

    BYTE    obsolete;
    
    BYTE    senseKey:       4;
    BYTE    reserved:       1;
    BYTE    ILI:            1;
    BYTE    EOM:            1;
    BYTE    fileMark:       1;

    DWORD   information;
    BYTE    addLen;
    DWORD   cmdSpecificInfo;
    BYTE    addSenseCode;
    BYTE    addSenseCodeQual;
    BYTE    fieldReplacementUnitCode;
    BYTE    senseKeySpecific[3];
} __attribute__((packed)) MSD_SENSE_DATA;

typedef struct
{
    DWORD   dCBWSignature;
    DWORD   dCBWTag;
    DWORD   dCBWDataTransferLength;
    BYTE    bmCBWFlags;
    
    BYTE    bCBWLUN:                    4;
    BYTE    reserved1:                  4;
    
    BYTE    bCBWLength:                 5;
    BYTE    reserved2:                  3;

    BYTE    CBWCB[16];
} __attribute__((packed)) MSD_CBW_DATA;

typedef struct
{
    DWORD   dCBWSignature;
    DWORD   dCBWTag;
    DWORD   dCSWDataResidue;
    BYTE    bCSWStatus;
} __attribute__((packed)) MSD_CSW_DATA;

PRIVATE BOOL _MSDHandleDataOut(USB_TRANSFER_EVENT_DATA *event_data);
PRIVATE BOOL _MSDHandleDataIn(USB_TRANSFER_EVENT_DATA *event_data);
PRIVATE BOOL _ServiceCommand(void);
PRIVATE BOOL _HandleMediumRemoval(void);
PRIVATE BOOL _HandleTestUnitReady(void);
PRIVATE BOOL _HandleInvalid(void);
PRIVATE BOOL _HandleReadCapacity(void);
PRIVATE BOOL _HandleRead10(unsigned int direction);
PRIVATE BOOL _HandleWrite10(BOOL first);
PRIVATE BOOL _SendCSW(DWORD bytes_sent, DWORD transfer_length, MSD_CSW_STATUS status);
PRIVATE BOOL _CheckCBW(MSD_CBW_DATA *cbw);
PRIVATE void _ResetSenseData(void);
PRIVATE BOOL _MSDHandleRequest(SETUP_PKT *setup);
PRIVATE BOOL _CheckAddressRange(DWORD start_addr, WORD num_sec);

#endif
