#include "../include/graph.h"








void parseTheGraph(Graph *graph)
{
	


}



Graph *graphInit(uint32 noVertices)
{
	if(noVertices == 0)
		return NULL; 

	Graph *graph = NULL;  
			
	graph = (Graph *)malloc(sizeof(Graph)); 
	if(graph == NULL) {
		perror("Failed to allocate memory.\n"); 
		return NULL; 
	}

	graph->vertices = noVertices; 
	
	graph->list = (adjList *)malloc(sizeof(adjList) * graph->vertices); 
	if(graph->list) {
		perror("Failed to allocate memory.\n"); 
		return NULL; 
	}

	for(uint32 i = 0; i < graph->vertices; i++)
	{
		graph->list[i].head = NULL; 
	}

	return graph; 
}

void insertToGraph(Graph *graph, uint32 from, uint32 to)
{
	adjNode *node = NULL; 

	node = (adjNode *)malloc(sizeof(adjNode)); 
	if(node == NULL)
	{
		perror("Failed to allocate memory.\n");
		return; 
	}

	node->vertex = to; 
	node->visited = false; 
	
	if(graph->list[from].head == NULL) 
	{
		graph->list[from].head = node;
	   	node->edge = NULL; 
		return; 
	}
	
	node->edge = graph->list[from].head;
   	graph->list[from].head = node; 

	return; 	
}

/* 
 * Need a 
 * Stack: 
 * Set: 
 *
*/ 

uint32 *topological_sort(Graph *graph)
{
	
		
	return NULL; 

}

void push(stack *st, uint32 var)
	if(st->top == st->size) 
	{
		perror("stack is full\n"); 
		return; 	
	}

	st->arr[st->top++] = var; 
	return; 
}

uint32 pop(stack *st) {
	if(st->top == 0) {
		perror("Stack is Empty.")	
		return; 
	}

	return st->arr[--st->top]; 
}


stack *stackInit(uint32 vertices)
{
	stack *st = NULL; 

	st = (stack *)malloc(sizeof(stack)); 
	if(st == NULL) {
		return NULL; 
	}

	st->arr = (uint32 *)calloc(0, sizeof(uint32) * vertices); 
	if(st->err == NULL)
		return NULL; 

	st->size = vertices; 
	st->top = 0; 

	return st; 
}


int main(int argc, char **argv)
{
	if(argc < 2) {
		perror("Insuffient arguments.\n"); 
		return -1; 
	}
	Graph *graph = NULL;
	stack *stack = NULL; 

	uint32 nVertices = atoi(argv[1]); 

	graph = graphInit(nVertices); 
	if(graph == NULL) {
		perror("Failed to init Graph.\n"); 
		exit(-1); 
	}

	stack = stackInit(nVertices); 
	if(stack == NULL) 
	{
		perror("Failed to allocate memory.\n"); 
		return -1; 	
	}	



	return 0; 
}



