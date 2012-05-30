/*********************************************************************
 *
 *                  Simple local heap implementation file
 *
 *********************************************************************
 * FileName:        heap.c
 * Dependencies:	None
 * 					    
 * Processor:       Daytona
 * 					
 * Complier:        MPLAB C30 v1.31.00 or higher
 *                  MPLAB IDE v7.10.00 or higher
 * Company:         Microchip Technology, Inc.
 *
 * Software License Agreement
 *
 * The software supplied herewith by Microchip Technology Incorporated
 * (the “Company”) for its Daytona Microcontroller is intended
 * and supplied to you, the Company’s customer, for use solely and
 * exclusively on Microchip Daytona Microcontroller products.
 * The software is owned by the Company and/or its supplier, and is
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
 *
 * Author               Date        Comment
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * $Id: Heap.c,v 1.4 2006/08/24 21:48:28 C12878 Exp $
 *
 ********************************************************************/

// Note: needs the symbol _HEAPSIZE_ to be defined at compile time
 
#ifdef _HEAPSIZE_

#include <heap.h>

// definitions
typedef double	Align;		// align on 8 bytes boundary



typedef union _header
{
	Align	x;
	struct	
	{
		size_t			size;
		union _header*	next;
	}h;
}_head;


#define	_MIN_HEAPSIZE_	1024ul


#if	_HEAPSIZE_ < _MIN_HEAPSIZE_
	#define	_LOCAL_HEAPSIZE_	_MIN_HEAPSIZE_
#else
	#define _LOCAL_HEAPSIZE_	_HEAPSIZE_	
#endif		



// extern data

// the heap itself
static _head _local_heap_[(_LOCAL_HEAPSIZE_ + sizeof(_head) - 1) / sizeof(_head)];

// local data
static _head*	_heap_freep=0;





// functions

void HeapInit(void)
{
	_heap_freep=_local_heap_;
	_heap_freep->h.size=(_LOCAL_HEAPSIZE_+sizeof(_head) - 1) / sizeof(_head);
	_heap_freep->h.next=_heap_freep;
}



void* HeapAlloc(size_t nbytes)
{
	if(!_heap_freep)
	{
		HeapInit();
	}
	     
	_head	*p,*prev;
	size_t	nunits;

	if(!nbytes)
	{
		return 0;
	}
	
	nunits=(nbytes+sizeof(_head)-1)/sizeof(_head)+1;	// always allocate sizeof(_head) bytes units   
	prev=_heap_freep;
	for(p=prev->h.next;;prev=p,p=p->h.next)
	{
		if(p->h.size>=nunits)
		{
			if(p->h.size==nunits)
			{
				if(prev->h.next==p->h.next)
				{
					return 0;
				}
				else
				{
					prev->h.next=p->h.next;
				}
			}
			else
			{
				p->h.size-=nunits;
				p+=p->h.size;
				p->h.size=nunits;
			}
			_heap_freep=prev;
			return (void*)(p+1);
		}
		if(p==_heap_freep)
		{
			return 0;
		}
	}
}

void HeapFree(void* ptr)
{  
	if(ptr && _heap_freep)
	{
		_head	*head,*p;
	
		head=(_head*)ptr-1;
		
		for(p=_heap_freep;!(head>p && head<p->h.next);p=p->h.next)
		{
			if(p>=p->h.next && (head>p || head<p->h.next))
			{
				break;
			}
		}
		if(head+head->h.size==p->h.next)
		{
			head->h.size+=p->h.next->h.size;
			head->h.next=p->h.next->h.next;
		}
		else
		{
			head->h.next=p->h.next;
		}
		if(p+p->h.size==head)
		{
			p->h.size+=head->h.size;
			p->h.next=head->h.next;
		}
		else
		{
			p->h.next=head;
		}
		_heap_freep=p;
	}
}

size_t HeapSize(void)
{
	if(!_heap_freep)
	{
		HeapInit();
	}
	
	_head	*p;
	size_t	size;

	size=0;
	p=_heap_freep;
	do
	{
		size+=p->h.size;
		p=p->h.next;
	}while (p!= _heap_freep);

	return size>2?(size-2)*sizeof(_head):0;
}

size_t	HeapMax(void)
{
	if(!_heap_freep)
	{
		HeapInit();
	}

	_head*	p;
	size_t	size;

	size=0;
	p=_heap_freep;
	do
	{
		if(p->h.size>size)
		{
			size=p->h.size;
		}
		p=p->h.next;
	}while(p!=_heap_freep);

	return size>2?(size-2)*sizeof(_head):0;
}



#endif // _HEAPSIZE_
