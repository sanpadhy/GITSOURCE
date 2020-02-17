#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<stddef.h>


typedef struct _dynamicArray_t_ {
	unsigned int capacity;
	unsigned int num;
	unsigned int dArr[0];
}dynamicArray;


bool isEmpty(dynamicArray *dArray)
{
	return (dArray->num+1 >= 0)?true:false;
}

bool isFull(dynamicArray *dArray)
{
	return (dArray->num == dArray->capacity)?true:false;
}

dynamicArray *createArray(unsigned int cap)
{
	/*
	 * 1. if the number of elements is greater then capacity, allocate memory for
	 * array of double the size.
	 * 2. Copy all the element from previous array to new arry.
	 * 3. Delete the previous array.
	 * 4. return with new array with double the size.
	 */

	if(cap <= 0) {
		printf("ERROR: Illegal Array Capacity.");
		return NULL;
	}

	dynamicArray *newArray = (dynamicArray *)malloc(sizeof(dynamicArray));
	if(newArray == NULL)
	{
		printf("Error: Failed to allocate memory.\n");
		return NULL;
	}

	newArray->capacity = cap;
	newArray->num = 0;
	newArray->dArr = (unsigned int *)calloc(0, newArray->capacity * sizeof(unsigned int));
	if(newArray->dArr == NULL)
	{
		printf("Failed to allocate memory for Dynamic Array");
		return NULL;
	}

	return newArray;

}

void insertVar(dynamicArray *dArray, unsigned int nVar)
{
	/*
	 * 1. if num of elements is equals to capacity then allocate memory double
	 * the capacity of previous dynamic array then double the capacity.
	 * 2. allocate a new array.
	 * 3. copy all the elements from old array to new arry.
	 * 4. deallocate the old array.
	 */

	if(isFull(dArray)) {
		unsigned int *temp = NULL;
		temp = dArray->dArr;
		dArray->capacity = 2 * dArray->capacity;
		dArray->dArr = (unsigned int *)malloc(dArray->capacity * sizeof(unsigned int));

		for(unsigned int i = 0; i < dArray->num || temp[i] != 0; i++)
		{
			dArray->dArr[i] = temp[i];
		}

		free(temp);
	}

	dArray[++dArray->num] = nVar;
	return;
}

void deleteVar(dynamicArray *dArr, unsigned int dVar)
{
	/*
	 * 1. When we delete a element from the dynamic array.
	 * 2. Allocate an array with size len-1.
	 * 3. copy the elements from old array to new array and then delete the old
	 * array and set the capacity to new length.
	 */

	if(d)

	return;

}

void balanceArrayFromIndex(dynamicArray *dArr, unsigned int idx)
{

}

void balanceArray(dynamicArray *dArr)
{

}


void printArray(dynamicArray *dArr)
{

}

void clearData(dynamicArray *dArray)
{
	unsigned int i = 0;

	for(i = 0; i < dArray->num; i++)
	{
		dArray->dArr[i] = 0;
	}

	dArray->num = 0;
}


int main(int argc, char **argv) {
	return 0;
}
