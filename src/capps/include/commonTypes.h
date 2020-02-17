#ifndef __COMMON_TYPES_H__
#define __COMMON_TYPES_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include <stddef.h>
#include <time.h>
#include <wchar.h>
#include <sys/types.h>

typedef unsigned int uint32; 
typedef signed int int32; 
typedef unsigned char uint8; 
typedef signed char int8; 
typedef unsigned long uint64; 
typedef signed long int64; 


#define error(msg, ...) printf("%s\n", msg)


#endif
