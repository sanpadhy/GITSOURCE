/*
 * threadpool.h
 *
 *  Created on: 22-Oct-2019
 *      Author: santosh
 */

#ifndef THREADPOOL_H_
#define THREADPOOL_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

typedef void (*thread_func_t)(void *arg);

/*
OBJECT DATA
*/
typedef struct tpool_work_t_ {
	thread_func_t func;
	void *arg;
	struct tpool_work_t_ *next;
}tpool_work;

typedef struct tpool_t {
	tpool_work *work_first;
	tpool_work *work_last;
	pthread_mutex_t work_mutex;
	pthread_cond_t work_cond;
	pthread_cond_t working_cond;
	size_t working_count;
	size_t thread_count;
	bool stop;
}tpool;


tpool *tpool_create(size_t num);
void tpool_destroy(tpool *tm);
bool tpool_add_work(tpool *tm, thread_func_t func, void *arg);
void tpool_wait(tpool *tm);

#endif /* THREADPOOL_H_ */
