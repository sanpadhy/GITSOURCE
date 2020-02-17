/*******************************************************************************
*
* File: Linkedlist.c
* Name: Santosh Kumar Padhy
*
* Description: Single Linked list Server function.
*
* Copyright
*
******************************************************************************/

#include "../include/LinkedList.h"


/************************************************************************************
 * ********************                                 *****************************
 * ********************    LOCAL FUNCTION DEFINITION    *****************************
 * ********************                                 *****************************
 * *********************************************************************************/

/*
 *  1.1
 *  Push: Insert a new variable to list.
 *  Input:
 *       **head 	--> Pointer to head;
 *       **Tail 	--> Pointer to tail.
 *       var 		--> New Variable to be added.
 *
 *  Output:
 *        Head, Tail
 */

static void push(singlelinkedlist **head,
		singlelinkedlist **tail,
		uint32 var)
{
	singlelinkedlist *newNode = createNewNode(var);
	if(!newNode) {
		perror("Failed to allocate memory for new Node\n");
		return;
	}

	if(*head == NULL)
	{
		*head = newNode;
		*tail = newNode;
		return;
	}

	newNode->next = *head;
	*head = newNode;

	parseTheList(*head);

	return;
}

/*
 *  1.2
 *  pop: Remove the first node of a linkedlist.
 *  Input:
 *       **head 	--> Pointer to head;
 *       **Tail 	--> Pointer to tail.
 *
 *  Return:
 *        Head of the node. Update the head.
 */

static int32 pop(singlelinkedlist **head,
		singlelinkedlist **tail)
{
	uint32 returnVar = -1;
	if((*head)->next == NULL) {
		returnVar = (*head)->key;
		free(head);
		*head = NULL;
		*tail = NULL;
		return returnVar;
	}

	singlelinkedlist *tmp = NULL;

	tmp = *head;
	returnVar = (*head)->key;

	*head = (*head)->next;

	free(tmp);
	return returnVar;
}

/*
 * createListWithLoops() -- Stub function to create a linkedlist with
 * Loops.
 *
 * Input:
 * 		head 		-- Head Node;
 * 		loopNode	-- Point to where Loop will be created.
 *
 */
static void createListWithLoops(
		singlelinkedlist **head,
		uint32 loopNode)
{
	singlelinkedlist *p = *head;
	singlelinkedlist *tmp = NULL;

	while(p || loopNode--) {
		p = p->next;
	}

	tmp = p;
	printf("%d\n", tmp->key);

	while(p->next) {
		p = p->next;
	}

	p->next = tmp;

	return;
}

/*
 * CreatePolynomialLists():
 * Input:
 *      **head:
 *      **tail:
 *      coeff:
 *      Power:
 *
 * Output:
 *      *head:
 *      *tail:
 *
 */

void CreatePolynomialLists(
		polynomiallist **head,
		polynomiallist *tail,
		uint32 coeff,
		uint32 power)
{



}


/**********************************************************************************************
 * ********************                                           *****************************
 * ********************    MAIN FUNCTION FOR LINKEDLIST SERVER    *****************************
 * ********************                                           *****************************
 * ********************************************************************************************/


int main()
{
	singlelinkedlist *head = NULL;
	singlelinkedlist *tail = NULL;
	uint32 i;

	uint32 listedItems[] = {24, 32, 4, 7, 34, 15, 57};


	for(i = 0; i < sizeof(&listedItems)/sizeof(listedItems[0]); i++)
	{
		push(&head, &tail, listedItems[i]);
	}

	singlelinkedlist *p = head;

	while(p) {
		printf("%d\n", pop(&p, &tail));
	}

	head = NULL;
	tail = NULL;

	for(i = 0; i < sizeof(&listedItems)/sizeof(listedItems[0]); i++)
	{
		insertNewNodeInSorted(&head, &tail, listedItems[i]);
	}

	uint32 listedItems1[] = {14, 72, 40, 74, 54, 65, 87};

	for(i = 0; i < sizeof(&listedItems1)/sizeof(listedItems1[0]); i++)
	{
		push(&head, &tail, listedItems1[i]);
	}

	rearrangeList(&head, 3, 5);

	// subListWithGivenSum(head, 119);

	// void partitionListWrtPivot(head, pivot);


	parseTheList(head);

	createListWithLoops(&head, 5);


	return 0;
}
