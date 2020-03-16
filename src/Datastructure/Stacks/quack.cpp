
/*******************************************************************************
*
* File: quack.cpp
* Name:
*
* Description: Quack is a data structure with Queue and Stack. 3 main functions:
*              push: add a new item x to the left end of the list
*              pop: remove and return the item on the left end of the list
*              pull: remove the item on the right end of the list.
*
* Copyright
*
******************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include <stddef.h>
#include <time.h>
#include <wchar.h>
#include <sys/types.h>

#define MAXSIZE 10

unsigned int firstStack[MAXSIZE];
unsigned int secondStack[MAXSIZE];
unsigned int thirdStack[MAXSIZE];


/*
 * There are 3 stack and O(1) additional memory.
 * Time taken will be O(1).
 * Push() -- push item to stack1.
 * pop() -- Remove and return the item on the left end of the list. pop() operation to be in stack3.
 *          -- if tos3 != 0, pop from stack 3.
 *          -- if tos3 == 0, pop from stack 2 and push into stack3 .
 *             -- check for tos2. If tos2 != 0, pop from stack 2 and push into stack3.
 *             -- if tos2 == 0
 *                    -- if tos1 != 0, pop from stack1 and push into stack2. Pop from stack2 and push into stack3.
 *                    -- if tos1 == 0, then all stacks are empty. Empty quack.

 *
 * pull(): remove the item on the right end of the list. First in First Out. Items to be removed from stack2.
 * 		-- if tos2 != 0, remove from stack2.
 * 		-- if tos2 == 0,
 * 		    -- Check tos3, if tos3 != 0, remove from stack3 with tos3, and push into stack2 and update tos2.
 *      -- 2.              if tos3 is 0, check tos1.
 *                              if tos1 != 0, Pull from stack 1  and push into stack 2.
 *                              else no items left in either of stack. Empty quack.
 *
 *  Note: tos -- Top of stack
 *
 */


#if 0
typedef struct _quack_t_ {
	unsigned int firstStack[MAXSIZE];
	unsigned int secondStack[MAXSIZE];
	unsigned int thirdStack[MAXSIZE];
	unsigned int tos1;
	unsigned int tos2;
	unsigned int tos3;
};
#endif

unsigned int tos1 = 0;
unsigned int tos2 = 0;
unsigned int tos3 = 0;


unsigned int pushStack(unsigned int *stack, unsigned int tos, unsigned int newVar)
{
	if(tos >= MAXSIZE)
	{
		printf("Stack is Full\n");
		return tos;
	}

	stack[tos++] = newVar;
	return tos;
}

int popStack(unsigned int *stack, unsigned int *tos)
{
	if(*tos == 0)
	{
		printf("stack is empty");
		return -1;
	}

	return stack[--(*tos)];
}


void push(unsigned int newVar)
{
	printf("Called Enqueue.\n");
	tos1 = pushStack(firstStack, tos1, newVar);
}
/*
* pull(): remove the item on the right end of the list. First in First Out. Items to be removed from stack2.
 * 		-- if tos2 != 0, remove from stack2.
 * 		-- if tos2 == 0,
 * 		    -- Check tos3, if tos3 != 0, remove from stack3 with tos3, and push into stack2 and update tos2.
 *      -- 2.              if tos3 is 0, check tos1.
 *                              if tos1 != 0, Pull from stack 1  and push into stack 2.
 *                              else no items left in either of stack. Empty quack.
*/

int pull()
{
	int  popped = -1;

	printf("tos1 = %d, tos2 = %d\n", tos1, tos2);

	if(tos2 == 0)
	{
		if(tos3 == 0) {
			if(tos1 == 0) {
				printf("Empty Quack");
				return -1;
			}
			else {
				while(tos1) {
					popped = popStack(firstStack, &tos1);
					printf("tos1 = %d, tos2=%d, ts3 = %d\n", tos1, tos2, tos3);
					tos2 = pushStack(secondStack, tos2, popped);
				}
			}
		}
		else {
			while(tos3) {
				popped = popStack(firstStack, &tos3);
				tos2 = pushStack(secondStack, tos2, popped);
			}
		}
	}

	popped = popStack(secondStack, &tos2);
	printf("Popped: %d\n", popped);

	return popped;
}

/*
 * pop() -- Remove and return the item on the left end of the list. pop() operation to be in stack3.
 *          -- if tos3 != 0, pop from stack 3.
 *          -- if tos3 == 0, pop from stack 2 and push into stack3 .
 *             -- check for tos2. If tos2 != 0, pop from stack 2 and push into stack3.
 *             -- if tos2 == 0
 *                    -- if tos1 != 0, pop from stack1 and push into stack2. Pop from stack2 and push into stack3.
 *                    -- if tos1 == 0, then all stacks are empty. Empty quack.
*/

int pop()
{
	int  popped = -1;

	printf("tos1 = %d, tos2 = %d\n", tos1, tos2);

	if(tos3 == 0) {
		if(tos2 == 0)
		{
			if(tos1 != 0) {
				while(tos1) {
					popped = popStack(firstStack, &tos1);
					tos2 = pushStack(secondStack, tos2, popped);
				}
			}
			else {
				printf("Empty Quack.\n");
				return -1;
			}
		}
		else {
			while(tos2) {
				popped = popStack(secondStack, &tos2);
				tos3 = pushStack(secondStack, tos3, popped);
			}
		}
	}
	popped = popStack(secondStack, &tos2);
	printf("Popped: %d\n", popped);

	return popped;
}

void traverseThroughStack(unsigned int *stack, unsigned int tos)
{
	if(tos == 0)
		return;

	for (unsigned int i=0; i < tos; i++)
	{
		printf("%d\n", stack[i]);
	}
}

void traverseThroughQueue()
{
	traverseThroughStack(firstStack, tos1);
	traverseThroughStack(secondStack, tos2);
	traverseThroughStack(secondStack, tos3);
}

int main(int argc, char **argv) {

	unsigned int popped = -1;

	push(10);
	push(12);
	push(8);
	push(5);
	push(11);
	push(15);
	push(14);
	push(3);
	push(6);
	push(1);

	traverseThroughQueue();

	popped = pop();
#if 0
	popped = popStack();
	popped = popStack();
	popped = popStack();
	popped = popStack();
	popped = popStack();
	popped = popStack();
	popped = popStack();
	popped = popStack();

	popped = popStack();
	popped = popStack();
	popped = popStack();
#endif

	if(popped == -1)
		exit(-1);

	printf("popped: %d, tos1 = %d, tos2 = %d\n", popped, tos1, tos2);


	traverseThroughQueue();


	return 0;
}
