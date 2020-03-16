/*
 * threadPoolApi.c
 *
 *  Created on: 22-Oct-2019
 *      Author: santosh
 */

#include "threadpool.h"

static tpool_work *tpool_work_get(tpool *tm)
{
	tpool_work *work;

	if(tm == NULL)
		return NULL;

	work = tm->work_first;
	if(work == NULL)
		return NULL;

	if(work->next == NULL) {
		tm->work_first = NULL;
		tm->work_last = NULL;
	}
	else {
		tm->work_first = work->next;
	}

	return work;
}

static void *tpool_worker(void *arg)
{
	tpool *tm = arg;
	tpool_work *work;

	while(1) {
		pthread_mutex_lock(&(tm->work_mutex));
		if(tm->stop)
			break;

		if(tm->work_first == NULL)
			pthread_cond_wait(&(tm->work_cond), &(tm->work_mutex));

		work = tpool_work_get(tm);

		tm->working_count++;
		pthread_mutex_unlock(&(tm->work_mutex));

		if(work != NULL) {
			work->func(work->arg);
			tpool_work_destroy(work);
		}

		pthread_mutex_lock(&(tm->work_mutex));
		tm->working_count--;
		if(!tm->stop && tm->working_count == 0 && tm->work_first == NULL)
			pthread_cond_signal(&(tm->working_cond));
		pthread_mutex_unlock(&(tm->work_mutex));
	}

	tm->thread_count--;
	pthread_cond_signal(&(tm->working_cond));

	pthread_mutex_unlock(&(tm->work_mutex));
	return NULL;
}

void tpool_wait(tpool *tm)
{
	if(tm == NULL)
		return;

	pthread_mutex_lock(&(tm->work_mutex));
	while (1) {
		if((!tm->stop && tm->working_count != 0) || (tm->stop && tm->thread_count != 0)) {
			pthread_cond_wait(&(tm->working_count), &(tm->work_mutex));
		}
		else {
			break;
		}
	}
	pthread_mutex_unlock(&(tm->work_mutex));
}


tpool tpool_create(int num_threads)
{
	tpool *tm;
	pthread_t thread;
	size_t i;

	tm = calloc(1, sizeof(*tm));

	tm->thread_count = num_threads;

	pthread_mutex_init(&(tm->work_mutex), NULL);
	pthread_cond_init(&(tm->working_cond), NULL);
	pthread_cond_init(&(tm->work_cond), NULL);

	tm->work_first = NULL;
	tm->work_last = NULL;

	for(i = 0; i < tm->thread_count; i++)
	{
		pthread_create(&thread, NULL, tpool_worker, tm);
		pthread_detach(thread);
	}

	return tm;
}

bool tpool_add_work(tpool *tm, thread_func_t func, void *arg)
{
	tpool_work *work;

	if(tm == NULL)
		return false;

	work = tpool_work_create(func, arg);
	if(work == NULL)
		return false;

	pthread_mutex_lock(&(tm->work_mutex));
	if(tm->work_first == NULL)
	{
		tm->work_first = work;
		tm->work_last = tm->work_first;
	}
	else {
		tm->work_last->next = work;
		tm->work_last = work;
	}

	pthread_cond_broadcast(&(tm->work_cond));
	pthread_mutex_unlock(&(tm->work_mutex));

	return true;
}


tpool_work *tpool_work_create(thread_func_t func, void *arg)
{
	tpool_work *work;

	if(func == NULL)
		return NULL;

	work = malloc(sizeof(*work));
	work->func = func;
	work->arg = arg;
	work->next = NULL;

	return work;
}

void tpool_work_destroy(tpool_work *work)
{
	if(work == NULL)
		return;

	free(work);
}

void tpool_destroy(tpool *tp)
{
	tpool_work *work;
	tpool_work *work1;

	if(tp == NULL)
		return;

	pthread_mutex_lock(&(tp->work_mutex));
	work = tp->work_first;

	while(work != NULL)
	{
		work1 = work->next;
		tpool_work_destroy(work);
		work = work1;
	}

	tp->stop = true;
	pthread_cond_broadcast(&(tp->working_cond));
	pthread_mutex_unlock(&(tp->work_mutex));

	tpool_wait(tp);

	pthread_mutex_destroy(&(tp->work_mutex));
	pthread_cond_destroy(&(tp->work_cond));
	pthread_cond_destroy(&(tp->working_cond));

	free(tp);
}

