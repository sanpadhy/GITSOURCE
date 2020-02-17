/*
 * LinkedList.h
 *
 *  Created on: 28-Dec-2019
 *      Author: santosh
 */

#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

#include "commonTypes.h"

#define MAX 10

#define ISNUMERIC(var) (var >= '0' && var <= '9')?true:false
#define ISCHAR(var) ((var >= 'a' && var < 'z') || (var >= 'A' && var < 'Z'))?true:false
#define max(var1, var2) (var1 >= var2?var1:var2)

/************************************************************************************
 * ********************                                 *****************************
 * ********************    STRUCTURE DEFINITION         *****************************
 * ********************                                 *****************************
 * *********************************************************************************/

typedef struct singlelinkedlist_t_ {
	uint32 key;
	struct singlelinkedlist_t_ *next;

}singlelinkedlist;

typedef struct polynomiallist_t_ {
	uint32 coeff;
	uint32 power;
	struct polynomiallist_t_ *next;
}polynomiallist;

typedef struct doublelinkedlist_t_ {
	uint32 key;
	struct doublelinkedlist_t_ *next;
	struct doublelinkedlist_t_ *prev;
}doublelinkedlist;

typedef struct xorlinkedlistnode_t_ {
	unsigned int value;
	struct xorlinkedlistnode_t_ *both;
}xorlinkedlistnode;

typedef struct charList_t_ {
	uint8 key;
	struct charList_t_ *next;
}charList;

/************************************************************************************
 * ********************                                 *****************************
 * ********************    LOCAL FUNCTION DEFINITION    *****************************
 * ********************                                 *****************************
 * *********************************************************************************/

static singlelinkedlist *createNewNode(uint32 newVar)
{
	singlelinkedlist *newNode = NULL;
	newNode = (singlelinkedlist *)malloc(sizeof(singlelinkedlist));
	if(newNode == NULL)
		return NULL;

	newNode->key = newVar;
	newNode->next = NULL;

	return newNode;
}

static void parseTheList(singlelinkedlist *head)
{
	if(head == NULL) {
		perror("Empty List.\n");
		return;
	}

	singlelinkedlist *p = head;
	while(p->next) {
		printf("%d", p->key);
		p = p->next;
		printf("->");
	}

	printf("%d\n", p->key);
	return;
}


/************************************************************************************
 * ********************                                 *****************************
 * ********************  EXTERN FUNCTION DECLARATION    *****************************
 * ********************                                 *****************************
 * *********************************************************************************/

extern void insertNewNodeInSorted(
		singlelinkedlist **head,
		singlelinkedlist **tail,
		uint32 newVar);

void deleteExistingNode(
		singlelinkedlist **head,
		singlelinkedlist **tail,
		unsigned int dvar);

void rearrangeList(
		singlelinkedlist **head,
		unsigned int dc,
		unsigned int group);

bool subListWithGivenSum(singlelinkedlist *head, uint32 sum);
static void insertToCircularLinkedList(
		singlelinkedlist **head,
		singlelinkedlist **tail,
		uint32 var);
singlelinkedlist *insertToCircularLinkedListAtRandom(singlelinkedlist *random, uint32 var);
void partitionListWrtPivot(singlelinkedlist *head, unsigned int pivot);
void rotateListToRight(
		singlelinkedlist **head,
		singlelinkedlist **tail,
		uint32 rotateBy);
singlelinkedlist *mergeSortLinkedList(singlelinkedlist *head);
singlelinkedlist *sortLinkedList(singlelinkedlist *head);
bool isPolindrom(singlelinkedlist *head,
		singlelinkedlist *tail);
void swapEveryTwoNodes(singlelinkedlist *head);
singlelinkedlist *sortListof012(singlelinkedlist *head);
singlelinkedlist *sumOfNumberWithListFormat(singlelinkedlist *list1, singlelinkedlist *list2);
void printListInreverse(singlelinkedlist *head);
bool loopInLinkedList(singlelinkedlist *head);
uint32 intersectionPointList_option1(singlelinkedlist *list1, singlelinkedlist *list2);
void intersectionPointList_option2(singlelinkedlist *list1, singlelinkedlist *list2);
void intersectionPointList_option3(singlelinkedlist *list1, singlelinkedlist *list2);
bool countPairsInListwithSum(singlelinkedlist *head, unsigned int givenSum);
void rearrangeListInPlace(singlelinkedlist *head);
void reversekAlternateNode(singlelinkedlist **head,
		singlelinkedlist **tail,
		uint32 k);
charList *runLengthDecodingList(charList *head,
		singlelinkedlist *tail);
bool findBalancedNodeOfList(singlelinkedlist *head);
void countDuplicateNodesList(singlelinkedlist *head);
#endif /* _LINKEDLIST_H_ */
