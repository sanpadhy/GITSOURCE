#include "../include/common.h"

typedef struct stack_t_ {
	uint32 arr[0]; 
	uint32 top; 
	uint32 size; 
}stack; 

typedef struct quack_t_ {
	stack **stck; 
	uint32 stackCount; 
}quack; 




