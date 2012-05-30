/********************************************************************
 * FileName:        linklist.c
 * Dependencies:    none
 * Processor:		PIC24FJ128G
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
 * Dymanically allocated linked list.  Single node
 *
 * HTTP Server Appilcation
 *
 * Change History:
 * Name         Date            Changes
 * S Justice    01/09/06        Initial Version
 ********************************************************************/

#ifdef _BORLAND_BUILD
#include <winsock.h>
#else
#include "generic.h"
#endif
#include <string.h>
#include "linklist.h"
#include "linklist_private.h"

 /*********************************************************************
 * Function:        LP_LINKLIST LINKLISTAddHead(LP_LINKLIST first, void *data, UINT size)
 *
 * PreCondition:    none
 *
 * Input:           first - pointer to the root link
 *                  data - pointer to the data to be put in the list
 *                  size - size of the data
 *
 * Output:          pointer to the start of the list
 *
 * Side Effects:    
 *
 * Overview:        
 *
 * Note:           
 ********************************************************************/
PUBLIC LP_LINKLIST LINKLISTAddHead(LP_LINKLIST first, void *data, UINT size)
{
    LP_LINKLIST     link;

    link = _CreateLink(data, size);

    if(!link)
        return NULL;

    if(first)
    {
        link->lpNext = first;
    }

    return link;

}
/*********************************************************************
 * Function:            LP_LINKLIST LINKLISTAddTail(LP_LINKLIST first, void *data, UINT size)
 *
 * PreCondition:        none
 *
 * Input:               first - pointer to the root link
 *                      data  - pointer to the data to be put into the list
 *                      size  - the size of the data to be put in the list
 *
 * Output:              pointer to the new link
 *
 * Side Effects:
 *
 * Overview:            Adds the data to the end of the list
 *
 * Note:
 ********************************************************************/
PUBLIC LP_LINKLIST LINKLISTAddTail(LP_LINKLIST first, void *data, UINT size)
{
    LP_LINKLIST     link;

    link = _CreateLink(data, size);

    if(!link)
        return NULL;

    if(first)
    {
        LP_LINKLIST curr;

        curr = first;

        while(curr->lpNext != NULL)
            curr = curr->lpNext;

        curr->lpNext = link;
    }

    return link;
}
/*********************************************************************
 * Function:            LP_LINKLIST LINKLISTAddIndex(LP_LINKLIST first, UINT index, void *data, UINT size)
 *
 * PreCondition:        none.
 *
 * Input:               first - pointer to the root link
 *                      index - where to put the data
 *                      data  - pointer to the data to be put into the list
 *                      size  - the size of the data to be put in the list
 *
 * Output:              pointer to the new link
 *
 * Side Effects:
 *
 * Overview:            Adds the data at an index in the list
 *
 * Note:
 ********************************************************************/
PUBLIC LP_LINKLIST LINKLISTAddIndex(LP_LINKLIST first, UINT index, void *data, UINT size)
{
    LP_LINKLIST     link;
    LP_LINKLIST curr;
    LP_LINKLIST prev;
    UINT        i;

    link = _CreateLink(data, size);

    if(!link)
        return NULL;

    curr    = first;
    prev    = NULL;
    i       = 0;

    while(curr)
    {
        if(i == index)
            break;

        prev = curr;
        curr = curr->lpNext;
        i++;
    }

    if(i != index)
    {
        _DeleteLink(link);
        return NULL;
    }

    if(prev)
    {
        prev->lpNext = link;
    }

    link->lpNext = curr;

    return link;
}
/*********************************************************************
 * Function:        void *LINKLISTGetAt(LP_LINKLIST first, UINT index)
 *
 * PreCondition:    none
 *
 * Input:           first - pointer to the root link
 *                  index - index of the list
 *
 * Output:          pointer of the data at the index
 *
 * Side Effects:    none
 *
 * Overview:        Get the data at an index of the list
 *
 * Note:           
 ********************************************************************/
PUBLIC void *LINKLISTGetAt(LP_LINKLIST first, UINT index)
{
    LP_LINKLIST curr;
    UINT        i;
    void        *data;

    if(!first)
        return NULL;

    curr = first;
    data = NULL;

    i = 0;

    while(curr)
    {
        if(i == index)
            break;

        curr = curr->lpNext;
        i++;
    }

    if(i == index)
    {
        data = curr->lpData;
    }

    return data;
}
/*********************************************************************
 * Function:        LP_LINKLIST LINKLISTDeleteFromPntr( LP_LINKLIST first,
 *                                                      void *data)
 *
 * PreCondition:    none
 *
 * Input:           first - pointer to the root link
 *                  data - pointer to the data
 *
 * Output:          pointer to the root link
 *
 * Side Effects:    deletes the link
 *
 * Overview:
 *
 * Note:
 ********************************************************************/
PUBLIC LP_LINKLIST LINKLISTDeleteFromPntr( LP_LINKLIST first, void *data)
{
    LP_LINKLIST curr;
    UINT        index;

    curr    = first;
    index   = 0;

    while(curr)
    {
        if(curr->lpData == data)
            break;

        index++;
        curr = curr->lpNext;
    }

    return LINKLISTDeleteAt(first, index);
}
/*********************************************************************
 * Function:            LP_LINKLIST LINKLISTDeleteAt(LP_LINKLIST first, UINT index)
 *
 * PreCondition:        none
 *
 * Input:               first - pointer to the root link
 *                      index - index of the list
 *
 * Output:              pointer to the root link
 *
 * Side Effects:        deletes the indexed link
 *
 * Overview:
 *
 * Note:
 ********************************************************************/
PUBLIC LP_LINKLIST LINKLISTDeleteAt(LP_LINKLIST first, UINT index)
{
    LP_LINKLIST curr;
    LP_LINKLIST prev;
    UINT        i;

    if(!first)
        return NULL;

    curr    = first;
    prev    = NULL;
    i       = 0;

    while(curr)
    {
        if(i == index)
            break;

        prev = curr;
        curr = curr->lpNext;
        i++;
    }

    if(i != index)
    {
        return NULL;
    }

    if(prev)
    {
        prev->lpNext = curr->lpNext;
    }else
    {
        first = first->lpNext;
    }

    _DeleteLink(curr);

    return first;
}
/*********************************************************************
 * Function:        void LINKLISTDeleteAll(LP_LINKLIST first)
 *
 * PreCondition:        none
 *
 * Input:               first - pointer to the root link
 *
 * Output:              list is destroyed
 *
 * Side Effects:        deletes the list
 *
 * Overview:
 *
 * Note:
 ********************************************************************/
PUBLIC void LINKLISTDeleteAll(LP_LINKLIST first)
{
    while(first)
        first = LINKLISTDeleteAt(first, 0);

}
/*********************************************************************
 * Function:        static LP_LINKLIST _CreateLink(void *data, UINT size)
 *
 * PreCondition:    none
 *
 * Input:           data - pointer to the data
 *                  size - size of the data
 *
 * Output:          pointer to the link
 *
 * Side Effects:    creates data on the heap
 *
 * Overview:        creates a link
 *
 * Note:
 ********************************************************************/
PRIVATE LP_LINKLIST _CreateLink(void *data, UINT size)
{
    void        *temp;
    LP_LINKLIST link;

    if((!data) || (!size))
        return NULL;

    temp = (void *)malloc(size);

    if(!temp)
        return NULL;

    link = (LP_LINKLIST)malloc(sizeof(LINKLIST));

    if(!link)
    {
        free(temp);
        return NULL;
    }

    memcpy(temp, data, size);

    link->lpData = temp;
    link->lpNext = NULL;

    return link;
}
/*********************************************************************
 * Function:        static void _DeleteLink(LP_LINKLIST link)
 *
 * PreCondition:    none
 *
 * Input:           link - pointer to the link to delete
 *
 * Output:          freed memory
 *
 * Side Effects:    releases data on the heap
 *
 * Overview:        deletes a link
 *
 * Note:
 ********************************************************************/
PRIVATE void _DeleteLink(LP_LINKLIST link)
{
    free(link->lpData);
    free(link);
}


