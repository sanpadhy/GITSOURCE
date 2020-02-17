/*
 * Queue.h
 *
 *  Created on: 29-Dec-2019
 *      Author: santosh
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include "common.h"

#define MAX 10

typedef struct _queue_t_{
	unsigned int queue[MAX];
	unsigned int top;
	unsigned int rear;
	unsigned int size;
}queue;

bool isEmpty(queue *Queue);
bool isFull(queue *Queue);
void enqueue(queue *Queue, unsigned int var);
int dequeue(queue *Queue);
queue *initQueue();



#endif /* QUEUE_H_ */
