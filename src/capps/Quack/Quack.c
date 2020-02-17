#include "../include/quack.h"

void pushstack(stack *st, uint32 x) {
	if(st->top == st->size) {
		perror("stack is full.\n"); 
		return; 
	}

	st->arr[st->top++] = x; 
	return; 
}

/*
uint32 pop(stack *st) 
{

		
		
}



uint32 pull(stack *st)
{

}
*/ 


void push(quack *qk, uint32 Item)
{
	pushstack(qk->stck[0], Item); 	
}



stack *initStack(uint32 cap)
{
	stack *ST = (stack *)malloc(sizeof(stack));
   	if(ST == NULL) {
		perror("Failed to allocate Memory.\n"); 
		return NULL; 	
	}	
	ST->size = cap; 
	ST->top = 0; 
	ST->arr = (uint32 *)malloc(sizeof(uint32) * ST->size); 
	if(ST->arr == NULL) {
		perror("Failed To allocate memory.\n"); 
		return NULL; 
	}	
	return ST; 
}

quack *initQuack(uint32 cap) {

	quack *QK = (quack *)malloc(sizeof(quack)); 
	if(QK == NULL) {
		perror("Failed to allocate memory.\n"); 
		return NULL; 
	}	
	QK->stackCount = 3; 

	for (uint32 i = 0; i < QK->stackCount; i++) {
		printf("stack %d\n", i); 
		QK->stck[i] = initStack(cap); 
		if(QK->stck[i] == NULL) {
			perror("Failed\n"); 
			return NULL; 
		}
	}

	return QK; 
}



int main(int argc, char **argv) {

	uint32 item = 0; 
	
	if(argc < 2) {
		perror("Insufficient number of argument.\n"); 
		return -1; 
	}

	uint32 size = atoi(argv[1]);

	quack *QUACK = NULL; 

	QUACK = initQuack(size); 
	if(QUACK == NULL) {
		return -1; 
	}	

	printf("Item to push: "); 
	scanf("%d\n", &item); 

	push(QUACK, item); 

	return 0; 	
}
