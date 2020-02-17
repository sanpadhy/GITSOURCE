/*
 * common.h
 *
 *  Created on: 28-Dec-2019
 *      Author: santosh
 */

#ifndef _COMMON_H_
#define _COMMON_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include<sys/socket.h>
#include<arpa/inet.h>


typedef unsigned int uint32;
typedef signed int int32;
typedef unsigned char uint8;
typedef signed char int8;
typedef unsigned long uint64;
typedef signed long int64;


#define error(msg, ...) printf("%s\n", msg)

#define MAX_LIMIT 10
#define MAX_CHAR 26


#ifndef _SWAPVAR_
#define _SWAPVAR_

static inline void swapVar(unsigned int *var1, unsigned int *var2)
{
	unsigned int temp;
	temp = *var1;
	*var1 = *var2;
	*var2 = temp;
	return;
}
#else 

#endif

#endif /* _COMMON_H_ */
