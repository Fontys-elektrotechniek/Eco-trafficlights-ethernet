/*********************************************************************
 *
 *                  memory alloc helper
 *
 *********************************************************************
 * FileName:        mhook.c
 * Dependencies:
 * Processor:       PIC32
 *
 * Complier:        MPLAB Cxx
 *                  MPLAB IDE
 * Company:         Microchip Technology, Inc.
 *
 * Software License Agreement
 *
 * The software supplied herewith by Microchip Technology Incorporated
 * (the “Company”) for its PIC32 Microcontroller is intended
 * and supplied to you, the Company’s customer, for use solely and
 * exclusively on Microchip PIC32 Microcontroller products.
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
 *$Id: $
 ********************************************************************/

#include <stdlib.h>
#include <string.h>


#include "mhook.h"
#include <audio/audio.h>


#if MEM_PROFILING 

/////////////////////////////////////// memory hooks functions

// NOTE: these functions work in conjunction with a library containing the following functions:
// sys_malloc, sys_free, sys_calloc, sys_free.
// These are the normal memory allocation functions.
// One way to obtain these functions is to invoke objcopy upon a standard C library.
// For example:
// objcopy --redefine-sym malloc=sys_malloc --redefine-sym free=sys_free --redefine-sym realloc=sys_realloc libc.a mhook-libc.a
// and then using the mhook-libc.a in this project
//


extern void* sys_calloc(size_t nitems, size_t size); 

extern void sys_free(void *ptr); 

extern void* sys_malloc(size_t size); 

extern void* sys_realloc(void *ptr, size_t size); 

// local proto
// 

#if MEM_PROFILING_CALLER
void		HookAddNode(void* p, size_t nBytes, void* caller);
#define		callerAdd()	(__builtin_return_address(0)-8)


#else
void		HookAddNode(void* p, size_t nBytes);
#endif

int		HookRemoveNode(void* p);


// implementation



#ifndef	MEM_PROFILING_CHK_BUFF
void* malloc(size_t nBytes)
{
	void*	p;
	
	p=sys_malloc(nBytes);

#if MEM_PROFILING_CALLER
	HookAddNode(p, nBytes, callerAdd());
#else	
	HookAddNode(p, nBytes);
#endif	
	return p; 
}

#else	// MEM_PROFILING_CHK_BUFF
void* malloc(size_t nBytes)
{
	int*	pInt;
	int	nInts=(nBytes+3)/4;
	int	nSize=(nInts+2)*4;
	
	pInt=(int*)sys_malloc(nSize);
	if(pInt)
	{
		*pInt=*(pInt+nInts+1)=0xdeadbeef;
	}

#if MEM_PROFILING_CALLER
	HookAddNode(pInt, nSize, callerAdd());
#else	
	HookAddNode(pInt, nSize);
#endif	
	return pInt?pInt+1:0; 
}
#endif	//	MEM_PROFILING_CHK_BUFF


#ifndef	MEM_PROFILING_CHK_BUFF
void free(void* ptr)
{
	HookRemoveNode(ptr);
	sys_free(ptr);
}

#else	// MEM_PROFILING_CHK_BUFF
void free(void* ptr)
{
	int*	pInt=(int*)ptr;
	if(pInt)
	{
		pInt-=1;
	}
	
	HookRemoveNode(pInt);
	sys_free(pInt);
}

#endif	//MEM_PROFILING_CHK_BUFF

#ifndef	MEM_PROFILING_CHK_BUFF
void* realloc(void *ptr, size_t size)
{
	void* newPtr=sys_realloc(ptr, size);
	if(ptr)
	{
		HookRemoveNode(ptr);
	}
	
#if MEM_PROFILING_CALLER
	HookAddNode(newPtr, size, callerAdd());
#else	
	HookAddNode(newPtr, size);
#endif	

	return newPtr;
}
#else	// MEM_PROFILING_CHK_BUFF
void* realloc(void *ptr, size_t size)
{
	int*	pInt;
	int	nInts=(size+3)/4;
	int	nSize=(nInts+2)*4;

	void* newPtr=sys_realloc(ptr, nSize);
	if((pInt=(int*)ptr))
	{
		HookRemoveNode(pInt-1);
	}
	
	if((pInt=(int*)newPtr))
	{
		*pInt=*(pInt+nInts+1)=0xdeadbeef;
	}

#if MEM_PROFILING_CALLER
	HookAddNode(newPtr, nSize, callerAdd());
#else	
	HookAddNode(newPtr, nSize);
#endif	

	return pInt?pInt+1:0;
}

#endif	// MEM_PROFILING_CHK_BUFF

#ifndef	MEM_PROFILING_CHK_BUFF
void* calloc(size_t nitems, size_t size)
{
		
	void* p=sys_calloc(nitems, size);

	
#if MEM_PROFILING_CALLER
	HookAddNode(p,  nitems*size, callerAdd());
#else	
	HookAddNode(p,  nitems*size);
#endif	
	return p;
}

#else	// MEM_PROFILING_CHK_BUFF
void* calloc(size_t nitems, size_t size)
{
	int*	pInt;
	int	nInts=(size*nitems+3)/4;
	int	nSize=(nInts+2)*4;

		
	pInt=(int*)sys_malloc(nSize);

	if(pInt)
	{
		memset(pInt, 0, nSize);
		*pInt=*(pInt+nInts+1)=0xdeadbeef;
	}
	
#if MEM_PROFILING_CALLER
	HookAddNode(pInt,  nSize, callerAdd());
#else	
	HookAddNode(pInt,  nSize);
#endif	
	return pInt?pInt+1:0;
}

#endif	// MEM_PROFILING_CHK_BUFF


//////////////////////////////////////// statistics interface functions
//


//  definitions
//
typedef struct _tag_sMHookNode
{
	struct _tag_sMHookNode*	next;
	struct _tag_sMHookNode*	prev;
	unsigned int		bSize;		// requested size
	void*			bHndl;		// block pointer
#if MEM_PROFILING_CALLER
	void*			caller;		// who called it
#endif	
}sMHookNode;

	
typedef struct
{
	sMHookNode*	head;		// list head
	sMHookNode*	tail;		// list tail;
}sMHookList;	// double linked list


// static data

static sMHookList	mHkList={0, 0};		// root

static sMHookNode	mHkBuffer[MEM_PROFILING_DEPTH+1];	// create our list of malloc descriptors here
							// one extra struct created cause the pool itself
							// needs some storage

static void*		pmHkPool=0;			// initialized memory pool
static int		mHkPoolSlots;			// number of available slots


static sMPoolStat	mPoolStatistics= {0};		// local stat copy
static sMDynStat	mDynStatistics ={0};		// dyn statistics copy


// local proto
// 

void		HookClearAll(void);

int		MemHookStackInit(void);
int		MemHookStackDepth();


// implementation

int	MemHookStatReset(void)
{
	HookClearAll();	
	memset(&mPoolStatistics, 0, sizeof(mPoolStatistics));
	memset(&mDynStatistics, 0, sizeof(mDynStatistics));
	return MemHookStackInit();
	
}

void MemHookPoolStat(sMPoolStat* pStat)
{
	*pStat=mPoolStatistics;
}


void MemHookDynStat(sMDynStat* pStat)
{

	*pStat=mDynStatistics;
}

int MemHookPoolSlots(void)
{
	return mHkPoolSlots;
}


int MemHookStackAlloc(void)
{
	return MemHookStackDepth();
}



/////////////////////////////////// internal stuff

/////  double linked lists
typedef struct _tagDlNode
{
	struct _tagDlNode*	next;
	struct _tagDlNode*	prev;
	int			load[1];	// some load
}sDlNode;	// double linked node
	
typedef struct
{
	sDlNode*	head;		// list head
	sDlNode*	tail;		// list tail;
}sDlList;	// double linked list


/////  double linked lists manipulation ///////////
//

#define		DlIsEmpty(pL)		((pL)->head==0)

void		DlAddHead(sDlList* pL, sDlNode* pN);

void		DlAddTail(sDlList* pL, sDlNode* pN);

#define		DlAddMid(pL, pN, after)	do{	(pN)->next=(after)->next; \
       						(pN)->prev=(after); \
       						(after)->next->prev=(pN); \
						(after)->next=(pN); \
					}while(0)


sDlNode*	DlRemoveHead(sDlList* pL);

sDlNode*	DlRemoveTail(sDlList* pL);

// assume node is neither head, nor tail
#define		DlRemoveMid(pN)	do{(pN)->prev->next=(pN)->next; (pN)->next->prev=(pN)->prev;}while(0) 

void		DlRemoveNode(sDlList* pL, sDlNode* pN);



// 
// simple pool functions
// 

void*	PoolInit(unsigned long* pBuff, int buffSize, int blkSize, int* pNBlocks);

void*	PoolGetBlk(void* pPool);

void	PoolRetBlk(void* pPool, void* pBlock);



// helpers
//

#if MEM_PROFILING_CALLER
void HookAddNode(void* p, size_t nBytes, void* caller)
#else
void HookAddNode(void* p, size_t nBytes)
#endif
{

	sMHookNode* pNode;
	if(!p)
	{	// allocation failed
		mDynStatistics.dynMemFailCnt++;
		mDynStatistics.dynMemFailBytes+=nBytes;
		return;
	}

	mDynStatistics.dynCurrMem+=nBytes;
	if(mDynStatistics.dynCurrMem>mDynStatistics.dynMaxMem)
	{
		mDynStatistics.dynMaxMem=mDynStatistics.dynCurrMem;
	}
	
	if(pmHkPool==0)
	{
		pmHkPool=PoolInit((unsigned long*)mHkBuffer, sizeof(mHkBuffer), sizeof(sMHookNode), &mHkPoolSlots);
		MemHookStackInit();
	}

	pNode=PoolGetBlk(pmHkPool);
	if(pNode)
	{
		pNode->bSize=nBytes;
		pNode->bHndl=p;
	#if MEM_PROFILING_CALLER
		pNode->caller=caller;
	#endif

		DlAddTail((sDlList*)&mHkList, (sDlNode*)pNode);	
	}
	else
	{
		mPoolStatistics.mHkPoolFailCnt++;
		mPoolStatistics.mHkPoolFailBytes+=nBytes;
	}

	if(++mPoolStatistics.mHkPoolCurrDepth>mPoolStatistics.mHkPoolMaxDepth)
	{
		mPoolStatistics.mHkPoolMaxDepth=mPoolStatistics.mHkPoolCurrDepth;
	}
}


// returns 1 if succes
// 0 if no ptr found
// 2 if begining of buffer damaged
// 4 if end of buffer damaged
// 6 if both ends of buffer damaged
#ifndef	MEM_PROFILING_CHK_BUFF
int HookRemoveNode(void* p)
{
	if(p)
	{
		sMHookNode* pNode;
		sMHookNode* pHead;
		
		if((pNode=pHead=mHkList.head))
		{
			do
			{
				if(pNode->bHndl==p)
				{	// found node
					mDynStatistics.dynCurrMem-=pNode->bSize;
					DlRemoveNode((sDlList*)&mHkList, (sDlNode*)pNode);
					PoolRetBlk(pmHkPool, pNode);
					mPoolStatistics.mHkPoolCurrDepth--;
					return 1;
				}
				pNode=pNode->next;
			}while(pNode!=pHead);
		}

	}

	return 0;
}

#else	// MEM_PROFILING_CHK_BUFF
int HookRemoveNode(void* p)
{
	if(p)
	{
		sMHookNode* pNode;
		sMHookNode* pHead;
		
		if((pNode=pHead=mHkList.head))
		{
			do
			{
				if(pNode->bHndl==p)
				{	// found node
					int	fail, nInts, *pInt;					
					nInts=pNode->bSize/4-2;
					fail=0;
					pInt=(int*)p;
					if(*pInt!=0xdeadbeef)
					{
						fail|=2;
					}
					if(*(pInt+1+nInts)!=0xdeadbeef)
					{
						fail|=4;
					}
					mDynStatistics.dynCurrMem-=pNode->bSize;
					DlRemoveNode((sDlList*)&mHkList, (sDlNode*)pNode);
					PoolRetBlk(pmHkPool, pNode);
					mPoolStatistics.mHkPoolCurrDepth--;

					return fail?fail:1;
				}
				pNode=pNode->next;
			}while(pNode!=pHead);
		}

		pNode=pHead;	// just a bkpt
	}

	return 0;
}
#endif	// MEM_PROFILING_CHK_BUFF


void HookClearAll(void)
{
	sMHookNode* pNode;
		
	while((pNode=mHkList.head))
	{
		DlRemoveNode((sDlList*)&mHkList, (sDlNode*)pNode);
		PoolRetBlk(pmHkPool, pNode);
	}

}


// init the stack so that we can detect what depth we're running at
// returns true if success, false on error
int __attribute__((naked)) MemHookStackInit(void)
{
	__asm __volatile(".set noreorder;	# \n \
	.set noat;			# \n \
	la	$t0, _stack;		# $t0: _tos \n \
	sltu	$v0, $sp, $t0;		# \n \
	beq	$v0, $0, 2f;		# $sp >_tos? \n \
	nop;				# \n \
	la	$t1, _min_stack_size;	# \n \
	subu	$t0, $t0, $t1;		# $t0: _bos \n \
	addiu	$t1, $sp, -4;		# $t1: currSp; don't destroy current $sp location \n \
	sltu	$v0, $t0, $t1;		# \n \
	beq	$v0, $0, 2f;		# $sp < _bos ? \n \
	lui	$t2, 0xdead;		# \n \
	ori	$t2, $t2, 0xbeef;	# fill constant: 0xdeadbeef \n \
1:	#; fill				# \n \
	sw	$t2, 0($t0);		# \n \
	bne	$t0, $t1, 1b;		# \n \
	addiu	$t0, $t0, 4;		# \n \
2:	#; done				# \n \
	jr	$ra;			# \n \
	nop;				# \n \
	.set reorder;			# \n \
	.set at;");

	return 0;
}

// returns the depth of the used stack
int  __attribute__((naked)) MemHookStackDepth(void)
{
	__asm __volatile(".set noreorder;# \n \
	.set noat;			# \n \
	la	$t0, _stack;		# t0: _tos \n \
	la	$v0, _min_stack_size;	# v0: depth \n \
	subu	$t1, $t0, $v0;		# t1: _bos \n \
	li	$t2, 0xdeadbeef;	# t2: check constant \n \
1:					# \n \
	lw	$t3, 0($t1);		# \n \
	bne	$t3, $t2, 2f;		# done \n \
	addiu	$t1, $t1, 4;		# ptr--; \n \
	b	1b;			# \n \
	addiu	$v0, $v0, -4;		# depth--; \n \
2:	# done				# \n \
	jr	$ra;			# \n \
	nop;				# \n \
	.set reorder;			# \n \
	.set at;");

	return 0;	
}




/////  double linked lists manipulation ///////////
//


void DlAddHead(sDlList* pL, sDlNode* pN)
{
	if(pL->head==0)
	{ // empty list, first node
		pL->head=pL->tail=pN;
		pN->next=pN->prev=pN;
	}
	else
	{
		pN->next=pL->head;
		pN->prev=pL->tail;
		pL->tail->next=pN;
		pL->head->prev=pN;
		pL->head=pN;
	}		
}


void  DlAddTail(sDlList* pL, sDlNode* pN)
{
	if(pL->head==0)
	{ // empty list, first node
		pL->head=pL->tail=pN;
		pN->next=pN->prev=pN;
	}
	else
	{
		pN->next=pL->head;
		pN->prev=pL->tail;
		pL->head->prev=pN;
		pL->tail->next=pN;
		pL->tail=pN;		
	}		

}


sDlNode*  DlRemoveHead(sDlList* pL)
{
	sDlNode* pN;
	if(pL->head==pL->tail)
	{
		pN=pL->head;
		pL->head=pL->tail=0;
	}
	else
	{
		pN=pL->head;
		pL->tail->next=pL->head=pN->next;
		pL->head->prev=pL->tail;
	}
	return pN;
}

sDlNode*  DlRemoveTail(sDlList* pL)
{
	sDlNode* pN;
	if(pL->head==pL->tail)
	{
		pN=pL->head;
		pL->head=pL->tail=0;
	}
	else
	{
		pN=pL->tail;
		pL->tail=pN->prev;
		pL->tail->next=pL->head;
		pL->head->prev=pL->tail;
	}
	return pN;
}


void  DlRemoveNode(sDlList* pL, sDlNode* pN)
{
	if(pN==pL->head)
	{
		DlRemoveHead(pL);
	}
	else if(pN==pL->tail)
	{
		DlRemoveTail(pL);
	}
	else
	{
		DlRemoveMid(pN);
	}
}


////////// simple memory pool functions //////////////
//



typedef struct _tagPoolBlock
{
	struct _tagPoolBlock*	next;
}sPoolBlock;	// pool block

//
typedef struct
{
	unsigned long	freeBlocks;	// know if some blocks in use
	sPoolBlock*	freeList;	// list of blocks
					// proper double alignment needed!
}sPoolDcpt;		// pool descriptor


// specific pool init function
void* PoolInit(unsigned long* pBuff, int buffSize, int blkSize, int* pNBlocks)
{
	sPoolBlock*	pBlk;
	sPoolBlock*	pRoot;
	sPoolDcpt*	poolDcpt;
	unsigned long	nBlocks;
	int		blkIx;

	poolDcpt=(sPoolDcpt*)pBuff;
	
	pRoot=(sPoolBlock*)(poolDcpt+1);
	nBlocks=(buffSize-sizeof(sPoolDcpt))/blkSize;

	for(blkIx=0, pBlk=pRoot; blkIx<nBlocks-1; blkIx++, pBlk=pBlk->next)
	{
		pBlk->next=(sPoolBlock*)((char*)pBlk+blkSize);
	}
	pBlk->next=0;


	poolDcpt->freeBlocks=nBlocks;
	poolDcpt->freeList=pRoot;
	if(pNBlocks)
	{
		*pNBlocks=nBlocks;
	}
	
	return poolDcpt;
}


void* PoolGetBlk(void* pPool)
{
	sPoolDcpt*	pDcpt=(sPoolDcpt*)pPool;
	sPoolBlock*	pBlk=0;

	if(pDcpt->freeList)
	{
		pBlk=pDcpt->freeList;
		pDcpt->freeList=pBlk->next;
		pDcpt->freeBlocks--;
	}
	return pBlk;
}

void PoolRetBlk(void* pPool, void* pBlock)
{
	sPoolDcpt*	pDcpt=(sPoolDcpt*)pPool;	
	sPoolBlock*	pBlk=(sPoolBlock*)pBlock;
	
	pBlk->next=pDcpt->freeList;
	pDcpt->freeList=pBlk;
	pDcpt->freeBlocks++;

}


#endif // MEM_PROFILING



