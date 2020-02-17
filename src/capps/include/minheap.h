/*
 * minheap.h
 *
 *  Created on: 08-Jan-2020
 *      Author: santosh
 */

#ifndef MINHEAP_H_
#define MINHEAP_H_

#include "common.h"

/*
 * MACROS DEFINITION
 */
#define PARENT(idx)  (idx -1)/2
#define LEFTCHILD(idx) (2*idx + 1)
#define RIGHTCHILD(idx) (2*idx + 2)


/* 
 * STRUCTURE DEFINITION 
 */  

typedef struct _minHeap_t_
{
	unsigned int *heapArr;
	unsigned int Capacity;
	unsigned int heapSize;
}minHeap;

/*
 *  FUNCTION DECLARATION. 
 */  

extern minHeap *initminHeap(int cap);
extern int extractMinHeap(minHeap *mheap);
extern int rekeyMinHeap(minHeap *mheap, uint32 idx, uint32 newKey);
extern int deleteKeyHeap(minHeap *mheap, uint32 idx, uint32 nkey);
extern int insertKeyHeap(minHeap *mHeap, int newVar);

#endif /* MINHEAP_H_ */
