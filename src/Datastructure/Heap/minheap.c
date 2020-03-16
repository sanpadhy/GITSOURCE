
#include "../include/minheap.h"

/*
 ***********************************************************************
 ***********************************************************************
 ***************** STATIC LOCAL FUNCTION *******************************
 ***************** *****************************************************
 ***************** *****************************************************
 */
static void swap(uint32 *var1, uint32 *var2)
{
	int tmp;
	tmp = *var1;
	*var1 = *var2;
	*var2 = tmp;
}

static int decreaseKeyHeap(minHeap *mheap, uint32 index, int newVal)
{
	mheap->heapArr[index] = newVal;
	while(index != 0 && mheap->heapArr[PARENT(index)] > mheap->heapArr[index])
	{
		swap(&mheap->heapArr[index], &mheap->heapArr[PARENT(index)]);
		index = PARENT(index);
	}
	return 0;
}

void minHeapify(minHeap *mHeap, uint32 refIdx)
{
	unsigned int lchld = LEFTCHILD(refIdx);
	unsigned int rchld = RIGHTCHILD(refIdx);

	int smallestVar = refIdx;

	if(lchld < mHeap->heapSize && mHeap->heapArr[lchld] < mHeap->heapArr[refIdx])
	{
		smallestVar = lchld;
	}

	if(rchld < mHeap->heapSize && mHeap->heapArr[rchld] < mHeap->heapArr[smallestVar])
		smallestVar = rchld;

	if (smallestVar != refIdx)
	{
		swap(&mHeap->heapArr[refIdx], &mHeap->heapArr[smallestVar]);
		minHeapify(mHeap, smallestVar);
	}
}

/*
 ***********************************************************************
 ***********************************************************************
 ***************** GLOBAL FUNCTION DEFINITION **************************
 ***************** *****************************************************
 ***************** *****************************************************
 */

minHeap *initminHeap(int cap)
{
	minHeap *mHeap = NULL;
	mHeap = (minHeap *)malloc(sizeof(minHeap));
	if(mHeap == NULL)
	{
		perror("Failed to allocate memory. \n");
		return NULL;
	}

	mHeap->Capacity = cap;
	mHeap->heapArr = (unsigned int *)malloc((mHeap->Capacity) * sizeof(int));
	mHeap->heapSize = 0;

	return mHeap;
}

int insertKeyHeap(minHeap *mHeap, int newVar)
{
	if(mHeap->heapSize == mHeap->Capacity)
	{
		error("Overflow: Failed to insert new key\n");
		return -1;
	}

	uint32 idx = mHeap->heapSize++;

	mHeap->heapArr[idx] = newVar;

	while(idx != 0 && mHeap->heapArr[PARENT(idx)] > mHeap->heapArr[idx])
	{
		swap(&mHeap->heapArr[idx], &mHeap->heapArr[PARENT(idx)]);
		idx = PARENT(idx);
	}

	return 0;
}

int deleteKeyHeap(minHeap *mheap, uint32 idx, uint32 nkey)
{
	int retCode = -1;

	swap(&mheap->heapArr[idx],  &mheap->heapArr[mheap->heapSize-1]);

	minHeapify(mheap, idx);

	mheap->heapArr[mheap->heapSize-1] = 0;
	mheap->heapSize--;

	retCode = 0;

	return retCode;
}

int rekeyMinHeap(minHeap *mheap, uint32 idx, uint32 newKey)
{
	int retCode = -1;
	bool DFlag = false;

	if(mheap->heapArr[idx] > newKey) {
		DFlag = true;
	}
	// The new key has the lower value compared to earlier key.
	if(DFlag == true) {
		retCode = decreaseKeyHeap(mheap, idx, newKey);
		if(retCode == -1)
		{
			error("Failed to decrease Key from minheap\n");
			return -1;
		}
	}
	else {
		minHeapify(mheap, idx);
	}
	return 0;
}

int extractMinHeap(minHeap *mheap)
{
	uint32 minVal = -1;
	if(mheap->heapSize == 0) {
		perror("Empty heap.\n");
		return false;
	} else {
		minVal = mheap->heapArr[0];
		swap(&mheap->heapArr[0], &mheap->heapArr[mheap->heapSize-1]);
		mheap->heapArr[mheap->heapSize-1] = 0;
		mheap->heapSize--;

		minHeapify(mheap, 0);
	}

	return minVal;
}


