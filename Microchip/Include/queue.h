/* queue.h
 *************************************************************************
 * Filename:        queue.h
 * Dependancies:    generic.h
 * Processor:       Any
 * Hardware:        Any
 * Assembler:       NA
 * Linker:          Any
 * Company:         Microchip Technology, Inc.
 *************************************************************************
 * Software License Agreement:
 *
 * The software supplied herewith by Microchip Technology Incorporated
 * (the Company) for its PICmicro Microcontroller is intended and
 * supplied to you, the Company's customer, for use solely and
 * exclusively on Microchip PICmicro Microcontroller products. The
 * software is owned by the Company and/or its supplier, and is
 * protected under applicable copyright laws. All rights are reserved.
 * Any use in violation of the foregoing restrictions may subject the
 * user to criminal sanctions under applicable laws, as well as to
 * civil liability for the breach of the terms and conditions of this
 * license.
 *
 * THIS SOFTWARE IS PROVIDED IN AN "AS IS" CONDITION. NO WARRANTIES,
 * WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED
 * TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 * PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. THE COMPANY SHALL NOT,
 * IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL OR
 * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *************************************************************************
 * File Description:
 * 
 * This file defines primative operations and data structures that provide
 * a queue abstraction.
 *
 * Queue Operations:
 * 
 *      QueueInit       - Initializes a queue and makes it empty.
 *      QueueAdd        - Adds an item to a queue.
 *      QueueRemove     - Removes an item from a queue.
 *      QueuePeek       - "Peeks" at an item in a queue w/o removing it.
 *      QueueDrop       - Throws away a given number of items.
 *      QueueFlush      - Makes the queue empty.
 *      QueueIsFull     - Checks to see if a queue is full.
 *      QueueIsNotFull  - Checks to see if a queue is not full.
 *      QueueIsEmpty    - Checks to see if a queue is empty.
 *      QueueIsNotEmpty - Checks to see if a queue is not empty.
 *      QueueCount      - Provides the count of items a queue.
 *
 * Usage:
 *
 *      Code using the queue must allocate a queue structure and a
 *      queue buffer that is an array of the type of items to be held
 *      in the queue.  The array should be sized so that it can hold
 *      one more then the desired maximum number of items that the 
 *      queue will hold.
 *
 *      Before a queue can be used, it must be initialized using the 
 *      QueueInit operation.
 *
 *      Before peforming an operation that will change the state of a
 *      queue (such as QueueAdd, QueueRemove, and QueueDrop), it is 
 *      necessary to check the state of the queue to make sure it is 
 *      safe to perform the desired task.  
 *
 *      Example:
 *
 *          if (QueueIsNotFull(&my_queue))
 *              QueueAdd(&my_queue, my_new_item);
 *
 * Notes:
 *
 *      It is an error to enqueue an item into a full queue and it will 
 *      result in the queue becoming empty.  The before performing a
 *      QueueAdd operation, the caller must first use one or more of the
 *      other primatives to determine if the queue has room.
 *
 *      It is an error to dequeue an item from an empty queue and it will
 *      result in the queue becoming full of undefined or stale data.
 *      Before performing a QueueRemove operation, the caller must first
 *      perform one or more of the other primatives to ensure that the
 *      queue has an item to remove.
 *
 *      Buffer space for the array of queue items must be allocated 
 *      seperately.  A pointer to this buffer, along with information 
 *      about how many items it can contain, are passed to the QueueInit
 *      operation.
 *
 *      A particular type of queue may only contain one type of item.
 *      Queue data structures are pre-defined for queues of BYTE's,
 *      UINT16's, UINT32's, and void pointers.
 *
 *      New queue types can easily be defined by defining a new queue 
 *      structure that has the same members as the pre-defined structures
 *      (below).  All that is necessary is to create a structure with a 
 *      data buffer pointer to a different data type.  The queue primative
 *      operations are defined as typless macros.  Thus, they will behave
 *      the same for any type of buffer array as long as the queue 
 *      structure has the same member names.
 *
 *      The queue is implemented so that it can contain at most number - 1
 *      items at any time (i.e. one item in the array is used to prevent 
 *      overflow).
 *      
 * Change History:
 *
 * Author               Date        Comment
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Bud Caldwell         8/5/2007    Original Implementation.
 *************************************************************************/

#ifndef QUEUE_H
#define QUEUE_H


/* Queue Structures
 *************************************************************************
 * These structures contain the data needed to manage queues of several
 * pre-defined types.
 *
 * Members:
 *
 *      head    - Index of the next element in the buffer to receive an
 *                item
 *
 *      tail    - Index of the next element in the buffer to have an item 
 *                removed
 *
 *      number  - Number of elements in the buffer array
 *
 *      buffer  - Pointer to the buffer array
 *
 * Notes:
 *
 *      The buffer array must be allocated seperately.
 *************************************************************************/
 
typedef struct _BYTE_QUEUE      // Queue of BYTE's
{
    unsigned int    head;
    unsigned int    tail;
    unsigned int    number;
    BYTE           *buffer;
} BYTE_QUEUE;

typedef struct _UINT16_QUEUE    // Queue of UINT16's
{
    unsigned int    head;
    unsigned int    tail;
    unsigned int    number;
    UINT16         *buffer;
} UINT16_QUEUE;

typedef struct _UINT32_QUEUE    // Queue of UINT32's
{
    unsigned int    head;
    unsigned int    tail;
    unsigned int    number;
    UINT32         *buffer;
} UINT32_QUEUE;

typedef struct _POINTER_QUEUE   // Queue of void pointers
{
    unsigned int    head;
    unsigned int    tail;
    unsigned int    number;
    void           *buffer;
} POINTER_QUEUE;


/* QueueInit
 *************************************************************************
 * Precondition:    None
 *
 * Input:           q   - queue:    Pointer to the queue data structure
 *
 *                  n   - number:   Number of elements in the queue data 
 *                                  buffer array
 *
 *                  b   - buffer:   Pointer to the data buffer
 *
 * Output:          None
 *
 * Returns:         The pointer to the buffer.
 *
 * Side Effects:    The queue structure has been initialized and is ready 
 *                  to use.
 *
 * Overview:        This operation initializes a queue, makes it empty,
 *                  and associates it with a buffer.
 *
 * Note:            This operation is implemented with a macro that 
 *                  supports queues of any type of data items.
 *************************************************************************/

#define QueueInit(q,n,b) ( (q)->head=0,     \
                           (q)->tail=0,     \
                           (q)->number=(n), \
                           (q)->buffer=(b)  )


/* QueueAdd
 *************************************************************************
 * Precondition:    The queue must have been initialized and must not 
 *                  currently be full.
 *
 * Input:           q   - queue:    Pointer to the queue data structure
 *
 *                  i   - item:     Item to be added to the queue
 *
 * Output:          None
 *
 * Returns:         The index of the new head item.
 *
 * Side Effects:    The item has been added to the queue.
 *
 * Overview:        This operatoin adds (enqueues) a new item into the 
 *                  queue data buffer and updates the head index,
 *                  handling buffer wrap correctly.
 *
 * Notes:           The caller must first ensure that the queue is not 
 *                  full by performing one of the other operations (such 
 *                  as "QueueIsNotFull") before performing this operation.
 *                  Adding an item into a full queue will cause overflow,
 *                  making the queue empty.
 *
 *                  This operation is implemented with a macro that 
 *                  supports queues of any type of atomic 
 *                  (return-able/pass-able) data item.
 *************************************************************************/

#define QueueAdd(q,i) ( (q)->buffer[(q)->head]=(i),       \
                        ( (((q)->head+=1)==(q)->number) ? \
                             ((q)->head=0)              : \
                             ((q)->head  )              ) )


/* QueueRemove
 *************************************************************************
 * Precondition:    The queue must have been initialized and not currently
 *                  be empty.
 *
 * Input:           q   - queue:    Pointer to the queue data structure
 *
 * Output:          None
 *
 * Returns:         The item removed.
 *
 * Side Effects:    The item has been removed from the queue.
 *
 * Overview:        This routine removes (dequeues) an item from the 
 *                  queue data buffer and updates the tail index,
 *                  handling buffer wrap correctly.
 *
 * Note:            The caller must first ensure that the queue is not
 *                  empty by calling one or more of the other operations
 *                  (such as "QueueIsNotEmpty") before performing this
 *                  operation.  Dequeueing an item from an empty queue
 *                  will cause underflow, making the queue full of 
 *                  undefined or stale data.
 *
 *                  This operation is implemented with a macro that 
 *                  supports queues of any type of atomic 
 *                  (return-able/pass-able) data item.
 *************************************************************************/

#define QueueRemove(q) ( (((q)->tail+=1) == (q)->number) ?                \
                             ((q)->tail=0,  (q)->buffer[(q)->number-1]) : \
                             ((q)->buffer[(q)->tail-1]    )   )


/* QueuePeek
 *************************************************************************
 * Precondition:    The queue must have been initialized and not currently
 *                  be empty.
 *
 * Input:           q   - queue:    Pointer to the queue data structure
 *
 *                  i   - index:    Index to the desired element
 *
 * Output:          None
 *
 * Returns:         The item "peeked" at
 *
 * Side Effects:    None
 *
 * Overview:        This routine peeks at an entry in the queue without
 *                  changing the queue.
 *
 *                  The index given is used as if the queue were an 
 *                  array, based at the tail of the queue.  That is, 
 *                  item 0 is the tail item (the item that would be 
 *                  removed by the QueueRemove operation).  If the queue
 *                  has 'n' items in it (as identified by the QueueCount
 *                  operation), then the valid range of the index is 0 to
 *                  n-1.
 *
 *                  The operation handles buffer wrap correctly.
 *
 * Note:            The caller must first ensure that the queue is not
 *                  empty by calling one or more of the other operations
 *                  (such as "QueueIsNotEmpty") before performing this
 *                  operation.  Peeking at an item that is not currently
 *                  in the queue (that is i >= n if 'n' is the number of 
 *                  items currently in the queue will return invalid, 
 *                  stale, or duplicated data.
 *
 *                  This operation is implemented with a macro that 
 *                  supports queues of any type of atomic 
 *                  (return-able/pass-able) data item.
 *************************************************************************/

#define QueuePeek(q,n) ( ((q)->tail+(n) < (q)->number) ?                \
                             ((q)->buffer[(q)->tail+(n)]            ) : \
                             ((q)->buffer[(q)->tail+(n)-(q)->number])   )


/* QueueDrop
 *************************************************************************
 * Precondition:    The queue must have been initialized.
 *
 * Input:           q   - queue:    Pointer to the queue data structure
 *
 *                  n   - number:   Number of items to drop from the queue
 *
 * Output:          None
 *
 * Returns:         
 *
 * Side Effects:    The given number of items have been dropped from the 
 *                  queue.
 *
 * Overview:        This routine drops (removes without saving) a given 
 *                  number of items from the tail of the queue by updating
 *                  the tail index and handling buffer wrap correctly.
 *
 * Note:            It is an error to drop more items from the queue then
 *                  it currently contains.  The caller must determine how 
 *                  many items are in the queue (by performing the
 *                  QueueCount operation or some other method) before 
 *                  dropping any items from the queue.  Dropping items 
 *                  then the queue contains can have one of three possible
 *                  result.
 *
 *                  Posible Results:
 *
 *                  1. If (n <= QueueCount(q)), the items are dropped from
 *                     the queue.  This is the only valid case.
 *
 *                  2. If (n > QueueCount(q) && n < (q)->number), then 
 *                     underflow will occur and the queue will be filled 
 *                     with (q)->number - n stale or undefined items.
 *
 *                  3. If (n >= (q)->number), then the queue will be
 *                     broken and future operations may cause invalid 
 *                     data accesses.  In this case, the queue must be re-
 *                     initialized with the QueueInit or QueueFlush 
 *                     operations.
 *************************************************************************/

#define QueueDrop(q,n) ( (((q)->tail+=(n)) < (q)->number) ? \
                           ((q)->tail)                    : \
                           ((q)->tail-=(q)->number)         )


/* QueueFlush
 *************************************************************************
 * Precondition:    The queue must be initialized.
 *
 * Input:           q   - queue:    Pointer to the queue data structure
 *
 * Output:          None
 *
 * Returns:         0
 *
 * Side Effects:    The queue is made empty
 *
 * Overview:        This routine makes the queue empty, effectively 
 *                  "dropping" all items currently in the queue.
 *************************************************************************/

#define QueueFlush(q) ( (q)->head = (q)->tail = 0 )


/* QueueIsFull
 *************************************************************************
 * Precondition:    The queue must be initialized.
 *
 * Input:           q   - queue:    Pointer to the queue data structure
 *
 * Output:          None
 *
 * Returns:         TRUE if the queue is full, FALSE otherwise.
 *
 * Side Effects:    None
 *
 * Overview:        This routine checks to see if the queue is full.
 *************************************************************************/

#define QueueIsFull(q) ( (((q)->head+1) == (q)->number)                  ? \
                             (((q)->tail   == 0)         ? TRUE : FALSE) : \
                             (((q)->head+1 == (q)->tail) ? TRUE : FALSE)   )


/* QueueIsNotFull
 *************************************************************************
 * Precondition:    The queue must be initialized.
 *
 * Input:           q   - queue:    Pointer to the queue data structure
 *
 * Output:          None
 *
 * Returns:         FALSE if the queue is full, TRUE otherwise.
 *
 * Side Effects:    None
 *
 * Overview:        This routine checks to see if the queue not is full.
 *************************************************************************/

#define QueueIsNotFull(q) ( (((q)->head+1) == (q)->number)                    ? \
                                (((q)->tail     == 0        ) ? FALSE : TRUE) : \
                                ((((q)->head+1) == (q)->tail) ? FALSE : TRUE)   )


/* QueueIsEmpty
 *************************************************************************
 * Precondition:    The queue must be initialized.
 *
 * Input:           q   - queue:    Pointer to the queue data structure
 *
 * Output:          None
 *
 * Returns:         TRUE if the queue is empty, FALSE otherwise.
 *
 * Side Effects:    None
 *
 * Overview:        This routine checks to see if the queue is empty.
 *************************************************************************/

#define QueueIsEmpty(q) ( (q)->head == (q)->tail )


/* QueueIsNotEmpty
 *************************************************************************
 * Precondition:    The queue must be initialized.
 *
 * Input:           q   - queue:    Pointer to the queue data structure
 *
 * Output:          None
 *
 * Returns:         FALSE if the queue is empty, TRUE otherwise.
 *
 * Side Effects:    None
 *
 * Overview:        This routine checks to see if the queue is not empty.
 *************************************************************************/

#define QueueIsNotEmpty(q) ( (q)->head != (q)->tail )


/* QueueCount
 *************************************************************************
 * Precondition:    The queue must be initialized.
 *
 * Input:           q   - queue:    Pointer to the queue data structure
 *
 * Output:          None
 *
 * Returns:         The number of items in the queue.
 *
 * Side Effects:    None
 *
 * Overview:        This routine provides the number of items in the queue.
 *************************************************************************/

#define QueueCount(q) ( ((q)->tail > (q)->head)                   ? \
                            ((q)->number - (q)->tail + (q)->head) : \
                            ((q)->head - (q)->tail              )   )


#endif // QUEUE_H
/*************************************************************************
 * EOF queue.c
 */

