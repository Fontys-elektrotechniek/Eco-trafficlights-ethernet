/******************************************************************************

    USB Human Interface Device (HID) Function Driver
    
This file implements the USB device abstraction.

 * Filename:        hid.c
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
#define _HID_PRIVATE_HEADER_FILE
#include <string.h>
#include "HardwareProfile.h"
#include <plib.h>
#include "GenericTypeDefs.h"
#include "USB/usb.h"
#include "USB/usb_device_hid.h"
#include "hidpri.h"


#ifndef SYS_CLOCK
#error "Please define SYS_CLOCK as the clock freq"
/* Example:
 * If you are running at 10MHz
 * SYS_CLOCK = 10000000
 */
#endif


PRIVATE HID_REPORT_DATA _HidReportTx;
PRIVATE HID_REPORT_DATA _HidGetReport;
PRIVATE HID_IDLE_TIME   _HidIdleTime[HID_NUM_REPORTS];
PRIVATE BYTE            _HidProtocol;
PRIVATE WORD            _HIDIdlePeriod;
PRIVATE BYTE            _HIDIdlePreScale;
PRIVATE BOOL            _HidReady = FALSE;
PRIVATE BOOL			_HidInit = FALSE;
const HID_REPORT_HANDLER _HidReportHandler[] =
{

};

#define HID_REPORT_HANDLER_SIZE     (sizeof(_HidReportHandler) / sizeof(HID_REPORT_HANDLER))

const BYTE _HidIdleTimeInfin = 0xFF;


UINT HIDDefaultHandler(void *data)
{
    return 0;
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
PUBLIC BOOL HIDInit(unsigned long flags)
{
    UINT i;

    _HidProtocol            = HID_REPORT_PROTOCOL;

    for(i = 0; i < (UINT)HID_NUM_REPORTS; i++)
    {
        _HidIdleTime[i].idle_time       = 0;
        _HidIdleTime[i].time_remaining  = 0;
        _HidIdleTime[i].report_id       = (BYTE)_HidReportHandler[i].id;
        _HidIdleTime[i].no_report       = FALSE;
    }

    _HIDIdlePeriod = HIDIdlePeriodValue(SYS_CLOCK, &_HIDIdlePreScale);

    mHIDConfigIntTimer(HID_INT_CONFIG);

    _HidReady 	= FALSE;
    _HidInit	= TRUE;

    HID_APP_EVENT_HANDLING_FUNC(EVENT_ATTACH, NULL, 0);

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
PUBLIC BOOL HIDEventHandler(USB_EVENT event, void *data, UINT size)
{
    if(!_HidInit)
    	return FALSE;
    	
    switch(event)
    {
        case EVENT_TRANSFER:
        	return TRUE;
        
        case EVENT_SUSPEND:
			_HidReady 	= FALSE;
            HID_APP_EVENT_HANDLING_FUNC(EVENT_SUSPEND, data, size);
			return TRUE;

        case EVENT_DETACH:
        	_HidInit 	= FALSE;
			_HidReady 	= FALSE;        		
            HID_APP_EVENT_HANDLING_FUNC(EVENT_DETACH, NULL, 0);
			return TRUE;
        
        case EVENT_RESUME:
			_HidReady 	= TRUE;        		
            HID_APP_EVENT_HANDLING_FUNC(EVENT_RESUME, data, size);
			return TRUE;    		    	
        
        case EVENT_SETUP:
            return HIDHandleRequests((SETUP_PKT *)data);

        case EVENT_SET_WAKE_UP:
            HID_APP_EVENT_HANDLING_FUNC(EVENT_SET_WAKE_UP, NULL, 0);
            return TRUE;
    
        case EVENT_CLEAR_WAKE_UP:
            HID_APP_EVENT_HANDLING_FUNC(EVENT_CLEAR_WAKE_UP, NULL, 0);
            return TRUE;
    
        case EVENT_BUS_ERROR:
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
PUBLIC BOOL HIDSendReport(BYTE id, void *data, UINT size, BOOL change)
{
    void    *ptr;
    UINT    i;

    
    if(!_HidReady)
        return FALSE;

    // check to see if the host has put the report in an idle state
    // first find the report id
    for(i = 0; i < (UINT)HID_NUM_REPORTS; i++)
    {
        if(_HidIdleTime[i].report_id == id)
            break;
    }

    if(i < (UINT)HID_NUM_REPORTS)
    {
        // second, if found see if we are in idle
        // if we are in idle, send only if something has changed
        if((_HidIdleTime[i].no_report) || (_HidIdleTime[i].time_remaining))
            if(!change)
                return FALSE;
    }


    if(size > (UINT)HID_MAX_REPORT_SIZE)
        return FALSE;

    ptr = (void *)&_HidReportTx.data[0];

    memcpy(ptr, data, size);

    if(id)
    {
        _HidReportTx.id = (BYTE)id;
        size++;
        ptr = (void *)&_HidReportTx.id;
    }

    // NOTE: this API call will be to the USB Device layer
    return USBDEVTransferData(XFLAGS(HID_EP_IN | USB_TRANSMIT), ptr, size);
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
PUBLIC BYTE *HIDGetIdleTime(BYTE report_id)
{
    UINT i;

    if(!report_id)
    {
        if(_HidIdleTime[0].no_report)
            return (BYTE *)&_HidIdleTimeInfin;
        else
            return &_HidIdleTime[0].idle_time;
    }

    for(i = 0; i < (UINT)HID_NUM_REPORTS; i++)
    {
        if(_HidIdleTime[i].report_id == report_id)
        {
            if(_HidIdleTime[i].no_report)
                return (BYTE *)&_HidIdleTimeInfin;
            else
                return &_HidIdleTime[i].idle_time;
        }
    }

    return (BYTE *)&_HidIdleTimeInfin;
}

PUBLIC void HIDSetReady(BOOL ready)
{
    _HidReady = ready;
}
PUBLIC BOOL HIDIsReady(void)
{
    return _HidReady;
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
PRIVATE WORD HIDIdlePeriodValue(DWORD sys_clk, BYTE *pre_scale)
{
    
    sys_clk     >>= OSCCONbits.PBDIV;       // get the periphal bus clock
    sys_clk     /= 250;                     // 4 ms period is 250
    *pre_scale   = 0;

    while(sys_clk > 0xFFFF)
    {
        sys_clk >>= 1;
        *pre_scale++;
    }

    if(*pre_scale > (BYTE)7)
        sys_clk = 0;

    return (WORD)sys_clk;
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
PRIVATE BOOL HIDHandleRequests(SETUP_PKT *setup)
{
    HID_STANDARD_REQ    *req;
    BYTE                *ptr;
    UINT                size;
    BOOL                status = FALSE;

    req = (HID_STANDARD_REQ *)setup;

    if(req->requestType.requestBits.recipient != HID_RECIPIENT)
        return FALSE;

    // class requests
    if(req->requestType.requestBits.type != (USB_SETUP_TYPE_CLASS >> 5))
        return FALSE;

    switch(req->bRequest)
    {
    case HID_REQ_GET_REPORT:
        ptr = HIDGetReport(req->ch9Packets.reportRequest.reportType, req->ch9Packets.reportRequest.reportID, &size);

        if(ptr)
            USBDEVTransferData(XFLAGS(USB_SETUP_DATA | USB_TRANSMIT), ptr, size);
        break;
    case HID_REQ_GET_IDLE:
        ptr = HIDGetIdleTime(req->ch9Packets.reportRequest.reportID);

        if(ptr)
            USBDEVTransferData(XFLAGS(USB_SETUP_DATA | USB_TRANSMIT), ptr, 1);
        break;
    case HID_REQ_GET_PROTOCOL:
        ptr = HIDGetProtocol();

        if(ptr)
            USBDEVTransferData(XFLAGS(USB_SETUP_DATA | USB_TRANSMIT), ptr, 1);
        break;
    case HID_REQ_SET_REPORT:
        HIDSetReport(req->ch9Packets.reportRequest.reportType, req->ch9Packets.reportRequest.reportID);
        status = TRUE;
        break;
    case HID_REQ_SET_IDLE:
        HIDSetIdleTime(req->ch9Packets.reportRequest.reportID, req->ch9Packets.idleRequest.duration);
        status = TRUE;
        break;
    case HID_REQ_SET_PROTOCOL:
        HIDSetProtocol((BYTE)req->ch9Packets.protocolRequest.protocol);
        status = TRUE;
        break;

    default:
        return FALSE;
    }

    if(status)
        USBHALTransferData(XFLAGS(USB_SETUP_STATUS|USB_TRANSMIT), NULL, 0);

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
PRIVATE BYTE *HIDGetProtocol(void)
{
    DESC_ID                 id;
    unsigned int            length;
    const HID_DESCRIPTOR   *hid;

    // Get the HID descriptor
    id.index    = 0;
    id.type     = HID_DSC_TYPE;
    id.lang_id  = 0;
    hid = USBDEVGetDescriptor(&id, &length);

    // Test the descriptor to see make sure we're not a boot class device.
    if (hid != NULL && length == sizeof(HID_DESCRIPTOR))
    {
        if(hid->bDescriptorType != HID_SUBCLASS_BOOT)
            return NULL;
    }

    return &_HidProtocol;
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
PRIVATE BOOL HIDSetProtocol(BYTE protocol)
{
    DESC_ID                 id;
    unsigned int            length;
    const HID_DESCRIPTOR   *hid;

    // Get the HID descriptor
    id.index    = 0;
    id.type     = HID_DSC_TYPE;
    id.lang_id  = 0;
    hid = USBDEVGetDescriptor(&id, &length);

    // Test the descriptor to see make sure we're not a boot class device.
    if (hid != NULL && length == sizeof(HID_DESCRIPTOR))
    {
        if(hid->bDescriptorType != HID_SUBCLASS_BOOT)
            return FALSE;
    }
 
    _HidProtocol = protocol;

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
PRIVATE BYTE *HIDGetReport(BYTE report_type, BYTE report_id, UINT *size)
{
    UINT    i;
    
    for(i = 0; i < HID_REPORT_HANDLER_SIZE; i++)
    {
        if(report_id == _HidReportHandler[i].id)
        {
            if(_HidReportHandler[i].reportHandler(_HidGetReport.data, size))
            {
                _HidGetReport.id = report_id;
                return (BYTE *)&_HidGetReport.id;
            }
        }
    }

    return NULL;
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
PRIVATE void HIDSetReport(BYTE report_type, BYTE report_id)
{
    // TODO: add a callback function to set the report
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
PRIVATE void HIDSetIdleTime(BYTE report_Id, BYTE idle_time)
{
    UINT    i;
    BOOL    set_timer;

    // if report id and idle time are zero, then hold off ALL
    // reports indefinately
    if((!report_Id) && (!idle_time))
    {
        for(i = 0; i < HID_NUM_REPORTS; i++)
        {
            _HidIdleTime[i].no_report = TRUE;
        }
        
        return;

    }else
    {

        set_timer = TRUE;

        for(i = 0; i < HID_NUM_REPORTS; i++)
        {
            
            if((_HidIdleTime[i].idle_time) && (!idle_time))
                set_timer = FALSE;

            // if report id is zero, then all reports are set
            // to the idle time (idle time * 4 ms)
            if(!report_Id)
            {
                _HidIdleTime[i].idle_time       = idle_time;
                _HidIdleTime[i].time_remaining  = idle_time;
                _HidIdleTime[i].no_report       = FALSE;
            }else
            {
                if(report_Id == _HidIdleTime[i].report_id)
                {
                    _HidIdleTime[i].idle_time       = idle_time;
                    _HidIdleTime[i].time_remaining  = idle_time;
                    
                    // if idle time is zero, then that report is
                    // suspended for idefinately
                    if(!idle_time)
                        _HidIdleTime[i].no_report   = TRUE;
                    else
                        _HidIdleTime[i].no_report   = FALSE;

                    break;
                }
            }
        }
    }

    if(set_timer)
    {
        WORD    config;

        config = _HIDIdlePreScale << 4;
        config |= HID_TIMER_CONFIG;

        // set up the timer
        mHIDOpenTimer(config, _HIDIdlePeriod);

        mHIDEnableTimerInt();
    }

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
//#pragma interrupt _HIDTimerIntHandler ipl2 vector 4
//void _HIDTimerIntHandler(void)
void __ISR( _HID_TIMER_VECTOR_, ipl2 ) _HIDTimerIntHandler(void)
{
    UINT    i;
    BOOL    disable = TRUE;

    mHIDClearInt();

    for(i = 0; i < HID_NUM_REPORTS; i++)
    {
        if(_HidIdleTime[i].idle_time)
        {
            if(_HidIdleTime[i].time_remaining)
            {
                _HidIdleTime[i].time_remaining--;
                disable = FALSE;
            }
            else
            {
                _HidIdleTime[i].time_remaining = _HidIdleTime[i].idle_time;
            }
        }

    }

    if(disable)
        mHIDDisableTimerInt();
}


