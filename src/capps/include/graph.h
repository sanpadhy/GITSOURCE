#ifndef __GRAPH_H__ 
#define __GRAPH_H__
#include "../include/common.h"


typedef struct adjNode_t_ {
	struct adjNode_t_ *edge; 
	uint32 vertex; 
	bool visited; 
}adjNode; 

typedef struct adjList_t_ {
	adjNode *head; 
}adjList; 

typedef struct graph_t_ {
	adjList *list; 
	uint32 vertices; 
}Graph; 

typedef stuct stack_t_ {
	uint32 *arr; 
	uint32 size; 
	uint32 top; 
}stack; 




#endif


