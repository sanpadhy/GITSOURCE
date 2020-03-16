
#include "../include/Queue.h"

bool isEmpty(queue *Queue)
{
	if(Queue->size == 0)
		return true;

	return false;
}

bool isFull(queue *Queue)
{
	if(Queue->size == MAX)
		return true;

	return false;
}


void enqueue(queue *Queue, unsigned int var)
{
	if (isFull(Queue))
		return;

	if(Queue->rear == MAX)
		Queue->rear = 0;

	Queue->queue[Queue->rear++] = var;
	Queue->size++;

	return;
}

int dequeue(queue *Queue)
{
	if(isEmpty(Queue))
		return -1;


	Queue->size--;
	return Queue->queue[Queue->top++];
}


queue *initQueue()
{
	queue *qObject = (queue *)malloc(sizeof(queue));
	if(qObject == NULL)
	{
		printf("Failed to allocate memory.\n");
		return NULL;
	}

	qObject->rear = 0;
	qObject->top = 0;
	qObject->size = 0;

	return qObject;

}




