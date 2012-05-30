/********************************************************************
 * FileName:		MSD.c
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

#include <string.h>
#include "GenericTypeDefs.h"
#include "USB\usb_device_msd.h"
#define _MSD_USE_PRIVATE_HEADER_FILE
#include "msd_pri.h"


/*********************************************************************
 * Constant Data
 ********************************************************************/
MSD_INQUIRY_DATA _msdInquiryResponse = 
{
    0,                              // peripheralDeviceType
    0,                              // peripheralQualifier

    0,                              // reserved
    1,                              // rmb

    MSD_INQUIRY_VERSION,            // version
    
    MSD_INQUIRY_RESPONSE,           // responseDataFormat
    0,                              // hisup
    0,                              // normaca
    0,                              // obsolete
    
    MSD_INQUIRY_LENGTH,             // additionLength
    
    0,                              // protect
    0,                              // reserved2
    0,                              // _3pc
    0,                              // tpgs
    0,                              // acc
    0,                              // sccs

    0,                              // addr16
    0,                              // obsolete2
    0,                              // mchngr
    0,                              // multip
    0,                              // vs
    0,                              // encserv
    0,                              // bque

    0,                              // vs2
    0,                              // cmdQue
    0,                              // obsolete3
    0,                              // linked
    0,                              // sync
    0,                              // wusb16
    0,                              // obsolete4

    {                               // t10VendorId
        'M',
        'i',
        'c',
        'r',
        'o',
        'c',
        'h',
        'p'
    },
    {                               // productId
        'M',
        'a',
        's',
        's',
        ' ',
        'S',
        't',
        'o',
        'r',
        'a',
        'g',
        'e',
        ' ',
        ' ',
        ' ',
        ' '
    },
    {                               // productRev
        '0',
        '0',
        '0',
        '1'
    }

};
BYTE _msdModeSense[4] =
{
    3,
    0,
    0,
    0
};

BYTE _msdMaxLun = 0;

/*********************************************************************
 * Private Data
 ********************************************************************/
PRIVATE MSD_STATES      _msdState;
PRIVATE BYTE            _msdBuffer[MSD_BUFFER_SIZE];
PRIVATE MSD_CBW_DATA    _msdCBW;
PRIVATE MSD_CBW_DATA    _msdCBWCopy;
PRIVATE MSD_CSW_DATA    _msdCSW;
PRIVATE MSD_SENSE_DATA  _msdSense;
PRIVATE WORD            _msdCmdStage;
PRIVATE DWORD_VAL       _msdSectorAddr;
PRIVATE WORD_VAL        _msdNumSector;
PRIVATE DWORD_VAL       _msdSecSize;
PRIVATE DWORD_VAL       _msdTotalSec;
/*********************************************************************
 * Function:       
 *
 * PreCondition:    
 *
 * Input:           
 *
 * Output:          
 *
 * Side Effects:    
 *
 * Overview:        
 *
 * Note:           
 ********************************************************************/
PUBLIC BOOL MSDInit(unsigned long flags)
{

    _msdState           = MSD_WAIT;
    _msdCmdStage        = 0;
    _msdSectorAddr.Val  = 0xFFFFFFFFL;
    _msdNumSector.Val   = 0xFFFF;
    _msdSecSize.Val     = 0xFFFFFFFF;
    _msdTotalSec.Val    = 0xFFFFFFFF;

    return USBDEVTransferData(MSD_USB_RX, &_msdCBW, sizeof(MSD_CBW_DATA));
        
}
/*********************************************************************
 * Function:       
 *
 * PreCondition:    
 *
 * Input:           
 *
 * Output:          
 *
 * Side Effects:    
 *
 * Overview:        
 *
 * Note:           
 ********************************************************************/
PUBLIC BOOL MSDEventhandler(USB_EVENT event, void *event_data, UINT size)
{
    
    switch(event)
    {
    case EVENT_TRANSFER:
        {
            USB_TRANSFER_EVENT_DATA   *data;

            if(size != sizeof(USB_TRANSFER_EVENT_DATA))
                return FALSE;
        
            data = (USB_TRANSFER_EVENT_DATA *)event_data;

            if(!data->flags.field.direction)
                return _MSDHandleDataOut(data);
            else
                return _MSDHandleDataIn(data);
        }
        case EVENT_SETUP:
            return _MSDHandleRequest((SETUP_PKT *)event_data);                        
    }
   
    return FALSE;
}
/*********************************************************************
 * Function:       
 *
 * PreCondition:    
 *
 * Input:           
 *
 * Output:          
 *
 * Side Effects:    
 *
 * Overview:        
 *
 * Note:           
 ********************************************************************/
PRIVATE BOOL _MSDHandleRequest(SETUP_PKT *setup)
{
    switch(setup->bRequest)
    {
    case MSD_RESET:
        break;

    case MSD_GET_MAX_LUN:
        USBDEVTransferData(XFLAGS(USB_SETUP_DATA | USB_TRANSMIT), &_msdMaxLun, 1);
        return TRUE;            
    }

    return FALSE;
}
/*********************************************************************
 * Function:       
 *
 * PreCondition:    
 *
 * Input:           
 *
 * Output:          
 *
 * Side Effects:    
 *
 * Overview:        
 *
 * Note:           
 ********************************************************************/
PRIVATE BOOL _MSDHandleDataOut(USB_TRANSFER_EVENT_DATA *event_data)
{
    if(!event_data)
        return FALSE;

    // make a scratch pad copy
    memcpy(&_msdCBWCopy, &_msdCBW, sizeof(MSD_CBW_DATA));
        
    if(_CheckCBW(&_msdCBWCopy))
        return _ServiceCommand();
    
    return FALSE;
    
}
/*********************************************************************
 * Function:       
 *
 * PreCondition:    
 *
 * Input:           
 *
 * Output:          
 *
 * Side Effects:    
 *
 * Overview:        
 *
 * Note:           
 ********************************************************************/
PRIVATE BOOL _MSDHandleDataIn(USB_TRANSFER_EVENT_DATA *event_data)
{
    switch(_msdCBWCopy.CBWCB[0])
    {
    case MSD_INQUIRY:
        _SendCSW(sizeof(MSD_INQUIRY_DATA), _msdCBWCopy.dCBWDataTransferLength, MSD_CSW_STATUS_PASSED);
        break;

    case MSD_READ_CAPACITY:
        _SendCSW(8, _msdCBWCopy.dCBWDataTransferLength, MSD_CSW_STATUS_PASSED);
        break;

    case MSD_READ_10:
        if(!_HandleRead10(USB_TRANSMIT))
            return TRUE;

        _SendCSW(0, _msdCBWCopy.dCBWDataTransferLength, MSD_CSW_STATUS_PASSED);
        break;

    case MSD_REQUEST_SENSE:
        _SendCSW(sizeof(MSD_SENSE_DATA), _msdCBWCopy.dCBWDataTransferLength, MSD_CSW_STATUS_PASSED);
        break;

    case MSD_MODE_SENSE:
        _SendCSW(sizeof(_msdModeSense), _msdCBWCopy.dCBWDataTransferLength, MSD_CSW_STATUS_PASSED);
        break;

    case MSD_WRITE_10:
    case MSD_PREVENT_ALLOW_MEDIUM_REMOVAL:
    case MSD_TEST_UNIT_READY:
    case MSD_VERIFY:
    case MSD_STOP_START:
        break;

    case 0xFF:
        break;

    default:
        _SendCSW(_msdCBWCopy.dCBWDataTransferLength, _msdCBWCopy.dCBWDataTransferLength, MSD_CSW_STATUS_FAILED);
        break;
    }

    _msdCBWCopy.CBWCB[0] = 0xFF;

    return TRUE;
}

/*********************************************************************
 * Function:       
 *
 * PreCondition:    
 *
 * Input:           
 *
 * Output:          
 *
 * Side Effects:    
 *
 * Overview:        
 *
 * Note:           
 ********************************************************************/
PRIVATE BOOL _ServiceCommand(void)
{
    static BOOL first = TRUE;
    BOOL        done  = TRUE;

    switch(_msdCBWCopy.CBWCB[0])
    {
    case MSD_INQUIRY:
        done = USBDEVTransferData(MSD_USB_TX, &_msdInquiryResponse, sizeof(MSD_INQUIRY_DATA));
        break; 

    case MSD_READ_CAPACITY:
        _HandleReadCapacity();
        break;

    case MSD_READ_10:
        done = _HandleRead10(USB_RECEIVE);
        break;

    case MSD_WRITE_10:
        first = _HandleWrite10(first);

        if(!first)
            return TRUE;

        break;

    case MSD_REQUEST_SENSE:
        done = USBDEVTransferData(MSD_USB_TX, &_msdSense, sizeof(MSD_SENSE_DATA));
        break;

    case MSD_MODE_SENSE:
        done = USBDEVTransferData(MSD_USB_TX, &_msdModeSense, sizeof(_msdModeSense));
        break;

    case MSD_PREVENT_ALLOW_MEDIUM_REMOVAL:
        done = _HandleMediumRemoval();
        break;

    case MSD_TEST_UNIT_READY:
        done = _HandleTestUnitReady();
        break;

    case MSD_VERIFY:
    case MSD_STOP_START:
        done = _SendCSW(0, _msdCBW.dCBWDataTransferLength, MSD_CSW_STATUS_FAILED);
        break;

    default:
        done = _HandleInvalid();
        break;
    }

    // set up to rx next packet
    USBDEVTransferData(MSD_USB_RX, &_msdCBW, sizeof(MSD_CBW_DATA));

    return done;
}
/*********************************************************************
 * Function:       
 *
 * PreCondition:    
 *
 * Input:           
 *
 * Output:          
 *
 * Side Effects:    
 *
 * Overview:        
 *
 * Note:           
 ********************************************************************/
PRIVATE BOOL _HandleMediumRemoval(void)
{

    if(MediaIsPresent())
    {
        _SendCSW(0, _msdCBW.dCBWDataTransferLength, MSD_CSW_STATUS_PASSED);
    }else
    {
        _msdSense.senseKey          = MSD_S_KEY_ERR_NOT_READY;
        _msdSense.addSenseCode      = MSD_S_ASC_MEDIUM_NOT_PRESENT;
        _msdSense.addSenseCodeQual  = MSD_S_ASCQ_MEDIUM_NOT_PRESENT;

        _SendCSW(0, _msdCBWCopy.dCBWDataTransferLength, MSD_CSW_STATUS_FAILED);

    }

    return TRUE;

}
/*********************************************************************
 * Function:       
 *
 * PreCondition:    
 *
 * Input:           
 *
 * Output:          
 *
 * Side Effects:    
 *
 * Overview:        
 *
 * Note:           
 ********************************************************************/
PRIVATE BOOL _HandleTestUnitReady(void)
{
    _ResetSenseData();

    if(MediaIsPresent())
    {
        _SendCSW(0, _msdCBWCopy.dCBWDataTransferLength, MSD_CSW_STATUS_PASSED);
    }else
    {
        _msdSense.senseKey          = MSD_S_KEY_ERR_UNIT_ATTENTION;
        _msdSense.addSenseCode      = MSD_S_ASC_MEDIUM_NOT_PRESENT;
        _msdSense.addSenseCodeQual  = MSD_S_ASCQ_MEDIUM_NOT_PRESENT;

        _SendCSW(0, _msdCBWCopy.dCBWDataTransferLength, MSD_CSW_STATUS_FAILED);

    }

    return TRUE;

}
/*********************************************************************
 * Function:       
 *
 * PreCondition:    
 *
 * Input:           
 *
 * Output:          
 *
 * Side Effects:    
 *
 * Overview:        
 *
 * Note:           
 ********************************************************************/
PRIVATE BOOL _HandleInvalid(void)
{

    _ResetSenseData();

    _msdSense.senseKey          = MSD_S_KEY_ERR_ILLEGAL_REQUEST;
    _msdSense.addSenseCode      = MSD_S_ASC_INVALID_COMMAND_OPCODE;
    _msdSense.addSenseCodeQual  = MSD_S_ASCQ_INVALID_COMMAND_OPCODE;

    memset(_msdBuffer, 0, MSD_BUFFER_SIZE);
    
    return USBDEVTransferData(MSD_USB_TX, _msdBuffer, _msdCBWCopy.dCBWDataTransferLength);
}
/*********************************************************************
 * Function:       
 *
 * PreCondition:    
 *
 * Input:           
 *
 * Output:          
 *
 * Side Effects:    
 *
 * Overview:        
 *
 * Note:           
 ********************************************************************/
PRIVATE BOOL _HandleReadCapacity(void)
{
    BYTE    buffer[16];
    DWORD   size, mult;

    memset(_msdBuffer, 0, 8);

    if(!CSDRead(buffer))
    {
        _msdCBWCopy.CBWCB[0] = 0xFE;
        USBDEVTransferData(MSD_USB_TX, _msdBuffer, _msdCBWCopy.dCBWDataTransferLength);
        return FALSE;
    }

    // block length
    _msdSecSize.Val = 1 << (buffer[5] & 0x0F);
    
    size = (DWORD)(buffer[6] & 0x03);
    size <<= 8;
    size |= (DWORD)buffer[7];
    size <<= 2;
    size |= (DWORD)((buffer[8] & 0xC0) >> 6);
    size++;

    mult = (DWORD)(buffer[9] & 0x03);
    mult <<= 1;
    mult |= (DWORD)((buffer[10] & 0x80) >> 7);
    mult += 2;
    
    _msdTotalSec.Val = size << mult;
    _msdTotalSec.Val--;

    _msdBuffer[0] = _msdTotalSec.v[3];
    _msdBuffer[1] = _msdTotalSec.v[2];
    _msdBuffer[2] = _msdTotalSec.v[1];
    _msdBuffer[3] = _msdTotalSec.v[0];

    _msdBuffer[4] = _msdSecSize.v[3];
    _msdBuffer[5] = _msdSecSize.v[2];
    _msdBuffer[6] = _msdSecSize.v[1];
    _msdBuffer[7] = _msdSecSize.v[0];
    
    return USBDEVTransferData(MSD_USB_TX, _msdBuffer, 8);
}
/*********************************************************************
 * Function:       
 *
 * PreCondition:    
 *
 * Input:           
 *
 * Output:          
 *
 * Side Effects:    
 *
 * Overview:        
 *
 * Note:           
 ********************************************************************/
PRIVATE BOOL _HandleRead10(unsigned int direction)
{	
    if(direction == USB_RECEIVE)
    {
        _msdSectorAddr.v[3] = _msdCBWCopy.CBWCB[2]; 
        _msdSectorAddr.v[2] = _msdCBWCopy.CBWCB[3]; 
        _msdSectorAddr.v[1] = _msdCBWCopy.CBWCB[4]; 
        _msdSectorAddr.v[0] = _msdCBWCopy.CBWCB[5]; 

        _msdNumSector.v[1]  = _msdCBWCopy.CBWCB[7];
        _msdNumSector.v[0]  = _msdCBWCopy.CBWCB[8];

        if(!_CheckAddressRange(_msdSectorAddr.Val, _msdNumSector.Val))
        {
            _msdSense.senseKey          = MSD_S_KEY_ERR_ILLEGAL_REQUEST;
            _msdSense.addSenseCode      = MSD_S_ASC_LOGICAL_BLOCK_ADDRESS_OUT_OF_RANGE;
            _msdSense.addSenseCodeQual  = MSD_S_ASCQ_LOGICAL_BLOCK_ADDRESS_OUT_OF_RANGE;

            _msdNumSector.Val   = 0xFFFF;
            _msdSectorAddr.Val  = 0xFFFFFFFF;
            return TRUE;
        }

    }        

    
     if(!_msdNumSector.Val)
        return TRUE;
       
    if((_msdNumSector.Val == 0xFFFF) && (_msdSectorAddr.Val == 0xFFFFFFFF))
    {
        _SendCSW(0, _msdCBWCopy.dCBWDataTransferLength, MSD_CSW_STATUS_FAILED);
        return TRUE;
    }

    
    if(MediaReadSector(_msdSectorAddr.Val, _msdBuffer))
    {
        USBDEVTransferData(     MSD_USB_TX,
                                _msdBuffer,
                                MSD_BUFFER_SIZE);

        _msdSectorAddr.Val++;
        _msdNumSector.Val--;
        _msdCBWCopy.dCBWDataTransferLength -= (DWORD)MSD_BUFFER_SIZE;

    }else
    {
        memset(_msdBuffer, 0, MSD_BUFFER_SIZE);
        _msdNumSector.Val   = 0xFFFF;
        _msdSectorAddr.Val  = 0xFFFFFFFF;

        USBDEVTransferData(     MSD_USB_TX,
                                _msdBuffer,
                                MSD_BUFFER_SIZE);
    }



    return FALSE;
}
/*********************************************************************
 * Function:       
 *
 * PreCondition:    
 *
 * Input:           
 *
 * Output:          
 *
 * Side Effects:    
 *
 * Overview:        
 *
 * Note:           
 ********************************************************************/
PRIVATE BOOL _HandleWrite10(BOOL first)
{
    static BOOL     write_ok;
    static WORD     size;
    
    
    if(first)
    {
        _msdSectorAddr.v[3] = _msdCBWCopy.CBWCB[2]; 
        _msdSectorAddr.v[2] = _msdCBWCopy.CBWCB[3]; 
        _msdSectorAddr.v[1] = _msdCBWCopy.CBWCB[4]; 
        _msdSectorAddr.v[0] = _msdCBWCopy.CBWCB[5]; 

        _msdNumSector.v[1]  = _msdCBWCopy.CBWCB[7];
        _msdNumSector.v[0]  = _msdCBWCopy.CBWCB[8];

        USBDEVTransferData(MSD_USB_RX, _msdBuffer, MSD_BUFFER_SIZE);
        
        write_ok            = TRUE;
        size                = 0;
        

        return FALSE;
    }


    if(_msdNumSector.Val)
    {
        if((MediaIsWriteProtected()) || (!_CheckAddressRange(_msdSectorAddr.Val, _msdNumSector.Val)) || !MediaIsPresent())
        {
            _msdSense.senseKey          = MSD_S_KEY_ERR_NOT_READY;
            _msdSense.addSenseCode      = MSD_S_ASC_WRITE_PROTECTED;
            _msdSense.addSenseCodeQual  = MSD_S_ASCQ_WRITE_PROTECTED;
            write_ok                    = FALSE;
        }else
        {
            write_ok = MediaWriteSector(_msdSectorAddr.Val, _msdBuffer);
        }

        if(write_ok)
        {
            _msdSectorAddr.Val++;
            _msdNumSector.Val--;
            _msdCBWCopy.dCBWDataTransferLength -= (DWORD)MSD_BUFFER_SIZE;
            
            if(_msdNumSector.Val)
                USBDEVTransferData(MSD_USB_RX, _msdBuffer, MSD_BUFFER_SIZE);
            

        }else
        {
            _msdNumSector.Val   = 0xFFFF;
            _msdSectorAddr.Val  = 0xFFFFFFFF;
        }
    }
    
    if(!_msdNumSector.Val)
    {
        _SendCSW(0, _msdCBW.dCBWDataTransferLength, MSD_CSW_STATUS_PASSED);
        return TRUE;
    }
        
    if((_msdNumSector.Val == 0xFFFF) && (_msdSectorAddr.Val == 0xFFFFFFFF))
    {
        _SendCSW(0, _msdCBW.dCBWDataTransferLength, MSD_CSW_STATUS_FAILED);
        return TRUE;
    }

    return FALSE;
}
/*********************************************************************
 * Function:       
 *
 * PreCondition:    
 *
 * Input:           
 *
 * Output:          
 *
 * Side Effects:    
 *
 * Overview:        
 *
 * Note:           
 ********************************************************************/
PRIVATE BOOL _SendCSW(DWORD bytes_sent, DWORD transfer_length, MSD_CSW_STATUS status)
{

    _msdCSW.dCBWSignature   = MSD_CSW_SIGNATURE;
    _msdCSW.dCBWTag         = _msdCBW.dCBWTag;
    _msdCSW.dCSWDataResidue = transfer_length - bytes_sent;
    _msdCSW.bCSWStatus      = (BYTE)status;

    return USBDEVTransferData(MSD_USB_TX, &_msdCSW, sizeof(MSD_CSW_DATA));
}
/*********************************************************************
 * Function:       
 *
 * PreCondition:    
 *
 * Input:           
 *
 * Output:          
 *
 * Side Effects:    
 *
 * Overview:        
 *
 * Note:           
 ********************************************************************/
PRIVATE BOOL _CheckCBW(MSD_CBW_DATA *cbw)
{
    if(cbw->dCBWSignature != MSD_CBW_SIGNATURE)
        return FALSE;

    if((cbw->bCBWLUN > 0x0F) || (!cbw->bCBWLength) || (cbw->bCBWLength > 0x10) || (cbw->bmCBWFlags & 0x7F))
        return FALSE;

    return TRUE;
}
/*********************************************************************
 * Function:       
 *
 * PreCondition:    
 *
 * Input:           
 *
 * Output:          
 *
 * Side Effects:    
 *
 * Overview:        
 *
 * Note:           
 ********************************************************************/
PRIVATE void _ResetSenseData(void)
{
    _msdSense.responceCode              = MSD_S_RESPONSE_CURRENT;
    _msdSense.valid                     = 0;
    _msdSense.obsolete                  = 0;
    _msdSense.senseKey                  = MSD_S_KEY_ERR_NO_SENSE;
    _msdSense.reserved                  = 0;
    _msdSense.ILI                       = 0;
    _msdSense.EOM                       = 0;
    _msdSense.fileMark                  = 0;
    _msdSense.information               = 0;
    _msdSense.addLen                    = 10;
    _msdSense.cmdSpecificInfo           = 0;
    _msdSense.addSenseCode              = 0;
    _msdSense.addSenseCodeQual          = 0;
    _msdSense.fieldReplacementUnitCode  = 0;
    _msdSense.senseKeySpecific[0]       = 0;
    _msdSense.senseKeySpecific[1]       = 0;
    _msdSense.senseKeySpecific[2]       = 0;

}
/*********************************************************************
 * Function:       
 *
 * PreCondition:    
 *
 * Input:           
 *
 * Output:          
 *
 * Side Effects:    
 *
 * Overview:        
 *
 * Note:           
 ********************************************************************/
PRIVATE BOOL _CheckAddressRange(DWORD start_addr, WORD num_sec)
{
    DWORD end_addr;

    end_addr = start_addr + (DWORD)num_sec;
    end_addr--;

    if(end_addr > _msdTotalSec.Val)
        return FALSE;

    return TRUE;
}
