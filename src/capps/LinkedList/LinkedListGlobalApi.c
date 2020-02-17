/*
 * LinkedListGlobalApi.c
 *
 *  Created on: 28-Dec-2019
 *      Author: santosh
 */

#include "../include/common.h"
#include "../include/LinkedList.h"
#include "../include/map.h"

/************************************************************************************
 * ********************                                 *****************************
 * ********************    LOCAL FUNCTION DEFINITION    *****************************
 * ********************                                 *****************************
 * *********************************************************************************/

bool isEqual(singlelinkedlist *head, singlelinkedlist *rvlist) {
	if(head == NULL && rvlist == NULL)
		return true; 

	singlelinkedlist *p = head; 
	singlelinkedlist *q = rvlist; 

	while (p != NULL && q != NULL) {
		if(p != q) {
			return false;
		}	
		p = p->next; 
		q = q->next; 
	}

	if(p == NULL || q == NULL) {
		return false; 
	}

	return true; 
}
		

static unsigned int countTotalNodesInList(singlelinkedlist *head)
{
	unsigned int cnt = 0;

	while(head != NULL){
		cnt++;
		head = head->next;
	}

	return cnt;
}

static void reverseLinkedList (
		singlelinkedlist **head,
		singlelinkedlist **tail)
{
	if(*head == NULL && (*head)->next == NULL)
		return;

	singlelinkedlist *p = *head;
	singlelinkedlist *pv = NULL;
	singlelinkedlist *nx = p->next;

	while(nx) {
		p->next = pv;
		pv = p;
		p = nx;
		nx = nx->next;
	}

	p->next = pv;

	*tail = *head;
	*head = p;

	return;
}

static void partitionListInHalf(singlelinkedlist *head,
		singlelinkedlist **first,
		singlelinkedlist **second)
{
	if(!head || !head->next)
		return;

	singlelinkedlist *slPtr = head;
	singlelinkedlist *fstPtr = head->next;

	while(fstPtr != NULL)
	{
		fstPtr = fstPtr->next;
		if(fstPtr != NULL)
		{
			slPtr = slPtr->next;
			fstPtr = fstPtr->next;
		}
	}

	*second = slPtr->next;

	slPtr->next = NULL;

	*first = head;

	return;
}

static singlelinkedlist *mergeLists(singlelinkedlist *list1,
		singlelinkedlist *list2)
{
	singlelinkedlist *newList = NULL;

	if(list1 == NULL && list2 == NULL) 
		return NULL; 
	else if(list1 == NULL && list2)
		return list2;
	else if(list1 && list2 == NULL)
		return list1;
	else {
		if(list1->key < list2->key) {
			newList = list1;
			newList->next = mergeLists(list1->next, list2);
		}
		else {
			newList = list2;
			newList->next = mergeLists(list1, list2->next);
		}
	}

	return newList;
}

static uint32 getTotalSumList(singlelinkedlist *head)
{
	uint32 sum = 0;
	singlelinkedlist *p = head;

	while(p) {
		sum += p->key;
		p = p->next;
	}

	return sum;
}


/************************************************************************************
 * ********************                                 *****************************
 * ********************    GLOBAL FUNCTION DEFINITION   *****************************
 * ********************                                 *****************************
 * *********************************************************************************/

/*
 *  1.1
 *  insertNewNodeInSorted: Insert a new variable to list in sorted order.
 *  Input:
 *       **head 	--> Pointer to head;
 *       **Tail 	--> Pointer to tail.
 *       var 		--> New Variable to be added.
 *
 *  Output:
 *        Head, Tail
 */

void insertNewNodeInSorted(
		singlelinkedlist **head,
		singlelinkedlist **tail,
		uint32 newVar)
{
	singlelinkedlist *newNode = createNewNode(newVar);
	if(!newNode) {
		perror("Failed to create New Node. \n");
		return;
	}

	/* Empty List. */
	if(head == NULL) {
		*head = newNode;
		*tail = newNode;
		return;
	}

	singlelinkedlist *p = *head;
	singlelinkedlist *pv = NULL;
	while(p)
	{
		if(p->key <= newVar) {
			pv = p;
			p = p->next;
		}
		else
		{
			if(pv == NULL) {
				newNode->next = p;
				*head = newNode;
				break;
			}
			else {
				pv->next = newNode;
				newNode->next = p;
				break;
			}
		}
	}

	if(p == NULL) {
	    pv->next = newNode;
	    *tail = newNode;
	}

	parseTheList(*head);
	return;
}

/*  1.2
 *  deleteExistingNode(): Delete a node from list.
 *  Input:
 *       **head --> Pointer to head;
 *       **Tail --> Pointer to tail.
 *       dvar 	--> variable to be deleted.
 *
 *  Output:
 *        Head, Tail
 */

void deleteExistingNode(
		singlelinkedlist **head,
		singlelinkedlist **tail,
		unsigned int dvar)
{
	if(*head == NULL)
	{
		perror("Empty list. \n");
		return;
	}

	singlelinkedlist *p = *head;
	singlelinkedlist *pv = NULL;
	singlelinkedlist *tmp = NULL;

	while(p)
	{
		if(p->key == dvar)
		{
			tmp = p;
			if(pv == NULL)
			{
				*head = p->next;
			}
			else
			{
				if(p == *tail) {
					pv->next = NULL;
					*tail = pv;
				}
				else {
					pv->next = p->next;
				}
			}
			p = p->next;
			free(tmp);
		}
		else if (p->key > dvar)
		{
			pv = p;
			p = p->next;
		}
		else
			break;
	}

	return;
}

/*
 *  1.3
 *  rearrangeList: Given the group of nodes in which first m nodes will
 *  be deleted and rest node will be skipped in that group and repeat
 *  the same for next group.
 *  List might have infinite number of nodes.
 *
 *  Input:
 *       **head 	--> Pointer to head;
 *       **Tail 	--> Pointer to tail. (Not Given at the moment)
 *       dc 		--> Delete count
 *       group      --> Group of nodes.
 *
 *  Output:
 *        Head
 */

void rearrangeList(
		singlelinkedlist **head,
		unsigned int dc,
		unsigned int group)
{
	if(!*head || (group < dc))
		return;

	if(group == dc) {
		*head = NULL;
		return;
	}

	unsigned int dcount = dc;
	unsigned int scount = group - dc;

	singlelinkedlist *p = *head;
	singlelinkedlist *newHead = NULL;
	singlelinkedlist *tmp = NULL;

	while(p)
	{
		while(p && dcount)
		{
			tmp = p;
			p = p->next;
			dcount--;
			free(tmp);
		}

		if(newHead == NULL)
		{
			newHead = p;
		}

		while(p && scount)
		{
			p = p->next;
			scount--;
		}

		p = p->next;
		dcount = dc;
		scount = group - dc;
	}

	*head = newHead;
	return;
}


/*
 *  1.4
 *  subListWithGivenSum: Find the sublist with given sum.
 *
 *  Input:
 *       *head 	--> Pointer to head;
 *		 sum    --> Sum of sublist
 *  Output:
 *       Bool   --> If the sublist present.
 */

bool subListWithGivenSum(singlelinkedlist *head, uint32 sum)
{
	if(head == NULL)
		return false;

	singlelinkedlist *p = head;
	singlelinkedlist *q = p->next;
	uint32 currentSum = p->key;

	while(p->next != q) {
		while(q->next) {
			currentSum = currentSum + q->key;

			if(currentSum == sum)
			{
				printf("Node from %d to %d has sum of %d\n", p->key, q->key, sum);
				return true;
			}
			else if(currentSum < sum)
			{
				q = q->next;
			}
			else {
				currentSum -= p->key;
				currentSum -= q->key;
				p = p->next;
				break;
			}
		}

		if(q->next == NULL && currentSum < sum)
		{
			printf("Failed to find the subarray\n");
			break;
		}
	}

	return false;
}

/*
 *  1.5
 *  insertToCircularLinkedList: Insert to circular Linkedlist.
 *  Input:
 *       **head --> Pointer to head;
 *       **Tail --> Pointer to tail.
 *       var --> New Var to be added to circular linkedlist.
 *
 *  Return:
 *        Void
 */

static void insertToCircularLinkedList(
		singlelinkedlist **head,
		singlelinkedlist **tail,
		uint32 var)
{
	singlelinkedlist *newNode = createNewNode(var);
	if(newNode == NULL)
		return;

	if(*head == NULL)
	{
		*head = newNode;
		*tail = newNode;
		return;
	}

	singlelinkedlist *p = *head;

	if(var < (*head)->key) {
		while(p->next != *head)
		{
			p = p->next;
		}
		p->next = newNode;
		newNode->next = *head;
		(*tail)->next = newNode;
		*head = newNode;
	}
	else {
		singlelinkedlist *pv = NULL;
		while((p->key < var) && (p->next != *head))
		{
			pv = p;
			p = p->next;
		}

		if(p->next == *head) {
			p->next = newNode;
			*tail = newNode;
			return;
		}

		pv->next = newNode;
		newNode->next = p;
	}

	return;
}

/*
 *  1.6
 *  insertToCircularLinkedListAtRandom: Insert to circular linkedlist with Random Pointer.
 *
 *  Input:
 *       Random --> Pointer to Random Node;
 *		 Var    --> New Variable to be inserted.
 *  return:
 *       Head   --> Pointer to head.
 */

singlelinkedlist *insertToCircularLinkedListAtRandom(singlelinkedlist *random, uint32 var)
{
	singlelinkedlist *p = random;
	singlelinkedlist *Head = NULL;
	singlelinkedlist *Tail = NULL;

	/* Find the head of the node. */
	while((p->key > p->next->key) || (p->next != random))
	{
		p = p->next;
	}

	Tail = p;
	Head = p->next;

	insertToCircularLinkedList(&Head, &Tail, var);

	return Head;
}

/*
 *  1.7
 *  partitionListWrtPivot(): Partition a list with respect to pivot value, where as
 *  value less then pivot will be part of list1, value equals to pivot is part of
 *  list2 and value more then pivot is part of list3.
 *
 *  Note: 1. There might be multiple nodes with equals to pivot.
 *  2. The node equals to pivot isnot present in list. so list will be divided
 *  into two.
 *
 *  Input:
 *       **head --> Pointer to head;
 *       **Tail --> Pointer to tail.
 *       var --> New Var to be added.
 *
 *  Output:
 *        void
 */

void partitionListWrtPivot(singlelinkedlist *head, unsigned int pivot)
{
	if(!head)
		return;

	bool flag = false;
	singlelinkedlist *first = NULL;
	singlelinkedlist *second = NULL;
	singlelinkedlist *third = NULL;

	singlelinkedlist *p = head;
	singlelinkedlist *pv = NULL;

	while(p) {
		if(p->key < pivot) {
			pv = p;
			p = p->next;
		}
		else if (p->key == pivot) {
			if(flag == false) {
				second = p;
				pv->next = NULL;
				first = head;
				flag = true;
			}
			pv = p;
			p = p->next;
			continue;
		}
		else {
			first = head;
			pv->next = NULL;
			second = NULL; 
			third = p;
			break;
		}
	}

	parseTheList(first);
	parseTheList(second);
	parseTheList(third);

	return;
}

/*
 *  1.8
 *  rotateListToRight(): Rotate the list by n nodes. Last n Nodes should be moved to first.
 *  Input:
 *       **head --> Pointer to head;
 *       **Tail --> Pointer to tail.
 *       rotateBy 	--> Rotate by nodes.
 *
 *  Output:
 *        Head, Tail
 */
void rotateListToRight(
		singlelinkedlist **head,
		singlelinkedlist **tail,
		uint32 rotateBy)
{

	if(head == NULL || rotateBy == 0)
		return;

	uint32 len = countTotalNodesInList(*head);

	if(len <= rotateBy)
		return;

	rotateBy = len - rotateBy;

	singlelinkedlist *p = *head;
	singlelinkedlist *pv = NULL;

	while(p && rotateBy--) {
		pv = p;
		p = p->next;
	}

	pv->next = NULL;
	(*tail)->next = *head;
	*head = p;
	*tail = pv;

	return;
}

/*
 *  1.9
 *  mergeSortLinkedList(): Sorting  linkedlist with mergesort.
 *  Input:
 *       **head --> Pointer to head;
 *       **Tail --> Pointer to tail.
 *       var --> New Var to be added.
 *
 *  Output:
 *        Head, Tail
 */

singlelinkedlist *mergeSortLinkedList(singlelinkedlist *head)
{

	if(head == NULL || head->next == NULL)
		return NULL;

	singlelinkedlist *nodePtr = head;
	singlelinkedlist *list1 = NULL;
	singlelinkedlist *list2 = NULL;

	partitionListInHalf(head, &list1, &list2);

	list1 = mergeSortLinkedList(list1);
	list2 = mergeSortLinkedList(list2);

	head = mergeLists(list1, list2);
	return head;
}


/*
 *  1.10
 *  sortLinkedList():
 *  Input:
 *       *head --> Pointer to head;
 *       var --> New Var to be added.
 *
 *  Output:
 *        Head, Tail
 */
singlelinkedlist *sortLinkedList(singlelinkedlist *head)
{
	if(head == NULL)
	{
		error("Empty List");
		return head;
	}

	head = mergeSortLinkedList(head);

	return head;
}


/*  1.11
 *  isPolindrom():
 *  Input:
 *       *head --> Pointer to head;
 *  Output:
 *        bool
 */
bool isPolindrom(singlelinkedlist *head,
		singlelinkedlist *tail)
{
	singlelinkedlist *fast = head;
	singlelinkedlist * slow = head;

	while(fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	unsigned int nNodes = countTotalNodesInList(head);

	if (nNodes%2 == 0)
		reverseLinkedList(&slow, &tail);
	else
		reverseLinkedList(&slow->next, &tail);

	fast = head;

	while(slow != NULL)
	{
		if (slow->key != fast->key)
			return false;

		slow = slow->next;
		fast = fast->next;
	}

	return true;
}

/* 
bool isPalindrom_1(singlelinkedlist *head, singlelinkedlist *tail)
{
	if(head == NULL) 
		return true; 

	singlelinkedlist *rvlist = NULL; 

	rvlist = reverseLinkedList(&head, &tail); 
	if(rvlist == NULL) {
		perror("Failed to revrse a list.\n"); 
	}	

	return isEqual(head, rvlist); 
}
*/ 

/*
 *  1.12
 *  swapEveryTwoNodes():
 *  Input:
 *       **head --> Pointer to head;
 *       **Tail --> Pointer to tail.
 *
 *  Output:
 *        Head, Tail
 */

void swapEveryTwoNodes(singlelinkedlist *head)
{
	if(head != NULL && head->next != NULL)
	{
		printf("head->value: %d, head->next->value: %d\n", head->key, head->next->key);
		swapVar(&(head->key), &(head->next->key));
		printf("head->value: %d, head->next->value: %d\n", head->key, head->next->key);

		swapEveryTwoNodes(head->next->next);
	}
	return;
}


/*
 *  1.13
 *  sortListof012():
 *  Input:
 *       **head --> Pointer to head;
 *       **Tail --> Pointer to tail.
 *
 *  Output:
 *        Head, Tail
 */
singlelinkedlist *sortListof012(singlelinkedlist *head)
{
	singlelinkedlist *q = NULL;
	singlelinkedlist *p = head->next;


	while(p != NULL)
	{
		q = head;
		while(p != q) {
			if (q->key > p->key)
			{
				swapVar(&(p->key), &(q->key));
			}
			q = q->next;
		}

		p = p->next;
	}
	return head;
}

/*
 *  1.14
 *  sumOfNumberWithListFormat():
 *  Input:
 *       **head --> Pointer to head;
 *       **Tail --> Pointer to tail.
 *
 *  Output:
 *        Head, Tail
 */
singlelinkedlist *sumOfNumberWithListFormat(singlelinkedlist *list1, singlelinkedlist *list2)
{
	unsigned int sum = 0;
	unsigned int firstNum = 0;
	unsigned int secNum = 0;

	singlelinkedlist *final = NULL;

	singlelinkedlist *temp = list1;

	while(temp) {
		firstNum = firstNum*10 + temp->key;
		temp = temp->next;
	}

	temp = list2;
	while(temp) {
		secNum = secNum*10 + temp->key;
		temp = temp->next;
	}

	sum = firstNum + secNum;

	while(sum != 0) {
		unsigned int nodeVal = sum % 10;
//		final = push(final, nodeVal);
		sum /= 10;
	}

	return final;
}

/*
 *  1.15
 *  sumOfNumberWithListFormat():
 *  Input:
 *       **head --> Pointer to head;
 *       **Tail --> Pointer to tail.
 *
 *  Output:
 *        Head, Tail
 */
void printListInreverse(singlelinkedlist *head)
{
	if(!head)
		return;

	printListInreverse(head->next);
	printf("%d\n", head->key);

	return;
}

/*
 *  1.16
 *  loopInLinkedList():
 *  Input:
 *       *head --> Pointer to head;
 *
 *  Output:
 *        Bool.
 */

bool loopInLinkedList(singlelinkedlist *head)
{
	singlelinkedlist *fast = head;
	singlelinkedlist *slow = head;
	bool foundLoop = false;

	while (fast->next != NULL)
	{
		fast = fast->next;
		if (fast->next != NULL)
		{
			fast = fast->next;
			slow = slow->next;

		}

		if(fast == slow) {
			printf("Loop in the list.\n");
			foundLoop = true;
			break;
		}
	}

	if(foundLoop == true)
	{
		slow = head;
		while(fast->next != slow)
		{
			fast = fast->next;
			slow = slow->next;
		}

		fast->next = NULL;
		printf("Intended loop being removed. \n");
	}

	return foundLoop;
}

/*
 *  1.17
 *  intersectionPointList(): Higher complexity, but work with all options.
 *  Whether both the list intersects or not.
 *  Input:
 *       *list1 --> First List;
 *       *list2 --> Second List.
 *
 *  Output:
 *        Intersect point.
 */

uint32 intersectionPointList_option1(singlelinkedlist *list1, singlelinkedlist *list2)
{
	unsigned int iPoint = 0;
	unsigned int list1Len = 0;
	unsigned int list2Len = 0;
	unsigned int diffInCount = 0;

	list1Len = countTotalNodesInList(list1);
	list1Len = countTotalNodesInList(list2);

	singlelinkedlist *p = list1;
	singlelinkedlist *q = list2;

	if(list1Len > list2Len)
	{
		diffInCount = list1Len - list2Len;

		while(diffInCount--) {
			 p = p->next;
		}

	}
	else if(list2Len > list1Len)
	{
		diffInCount = list2Len - list1Len;

		while(diffInCount--) {
			 q = q->next;
		}
	}
	else {
		printf("Both list of same length.\n");
	}

	while(p) {
		if(p == q) {
			printf("Intersection point: %d\n", p->key);
			return p->key;
		}
		p = p->next;
		q = q->next;
	}


	return p->key;
}

/*
 *  1.18
 *  intersectionPointList_option2():
 *  Lesser complexity, but doesn't work in case both the list doesn't intersect.
 *
 *  Input:
 *       *list1 --> First List;
 *       *list2 --> Second List.
 *
 *  Output:
 *        Intersect point.
 */

void intersectionPointList_option2(singlelinkedlist *list1, singlelinkedlist *list2)
{
	if(!list1 || !list2)
		return;

	singlelinkedlist *p = list1;
	singlelinkedlist *q = list2;

	while (p != q) {
		if(!p) {
			p = list2;
		}


		if(!q) {
			q = list1;
		}

		p = p->next;
		q = q->next;
	}

	printf("The intersection point is: %d\n", p->key);
	return;
}


/*
 *  1.19
 *  intersectionPointList_option3():
 *  Lesser complexity, but doesn't work in case both the list doesn't intersect.
 *
 *  Input:
 *       *list1 --> First List;
 *       *list2 --> Second List.
 *
 *  Output:
 *        Intersect point.
 */

void intersectionPointList_option3(singlelinkedlist *list1, singlelinkedlist *list2)
{
	if(!list1 || !list2)
		return;

	bool intersectionFlag = false;
	bool found = false;

	intersectionPointList_option3(list1->next, list2);
	intersectionPointList_option3(list1, list2->next);

	if(list1 != list2) {
		if((intersectionFlag == true) && (found == false)) {
			printf("Intersection Point is: %d\n", list1->next->key);
			intersectionFlag = false;
			found = true;
		}
	}
	return;
}

/*
 *  1.20
 *  countPairsInListwithSum():
 *  Input:
 *       *head --> Pointer to head;
 *       givenSum --> Sum of the pair.
 *
 *  Output:
 *        Pair of Nodes which sum is equals to input sum.
 */

#if 0
bool countPairsInListwithSum(singlelinkedlist *head, unsigned int givenSum)
{
	if(head == NULL)
		return false;

	uint32 set[] = {0};
	singlelinkedlist *p = head;

	while(p) {
		if(isPresent(set, (givenSum-p->key))) {
			printf("The var %d and %d has the sum %d\n", p->key, (givenSum - p->key), givenSum);
			return true;
		}

		setadd(set, p->key);
		p = p->next;
	}

	printf("Couldn't find the Pair");
	return false;
}
#endif


// Given a linked list, rearrange the node values such that they appear in alternating low -> high -> low -> high ...
// form. For example, given 1 -> 2 -> 3 -> 4 -> 5, you should return 1 -> 3 -> 2 -> 5 -> 4.

/*
 *  1.21
 *  rearrangeListInPlace():
 *  Input:
 *       *head --> Pointer to head;
 *
 *  Output:
 *        Head, Tail
 */

void rearrangeListInPlace(singlelinkedlist *head)
{
	if(head == NULL || head->next == NULL || head->next->next == NULL)
		return;

	singlelinkedlist *p = NULL;
	singlelinkedlist *q = NULL;

	p = head;

	swapVar(&(p->next->key), &(p->next->next->key));

	rearrangeListInPlace(p->next->next);

	return;
}

/*
 *  1.22
 *  reversekAlternateNode():
 *  Input:
 *       **head --> Pointer to head;
 *       **Tail --> Pointer to tail.
 *       k      --> Reverse Count.
 *
 *  Output:
 *        Head, Tail
 */

void reversekAlternateNode(singlelinkedlist **head,
		singlelinkedlist **tail,
		uint32 k)
{
	if(*head == NULL or (*head)->next == NULL)
		return;

	if(k == 0)
		return;

	unsigned int len = countTotalNodesInList(*head);

	if(len < k)
		return reverseLinkedList(head, tail);

	singlelinkedlist *p = *head;
	singlelinkedlist *q = *head;
	singlelinkedlist *pv = NULL;
	singlelinkedlist *nxt = p->next;
	singlelinkedlist *newHead = NULL;
	singlelinkedlist *newTail = NULL;

	unsigned int count = k;

	while(nxt) {
		newTail = p;
		while(nxt || count--)
		{
			p->next = pv;
			pv = p;
			p = nxt;
			nxt = nxt->next;
		}

		if(newHead == NULL)
		{
			newHead = pv;
		}
	}

	*tail = newTail;

	return;
}

/*
 *  1.23
 *  runLengthDecodingList(): Reconstruct the linked list based on repeatitive nodes.
 *  AAAABBCDDD --> 4A2B1C3D
 *
 *  Input:
 *       **head --> Pointer to head;
 *       **Tail --> Pointer to tail.
 *
 *  Output:
 *        Head, Tail
 */
#if 0

charList *runLengthDecodingList(charList *head,
		singlelinkedlist *tail)
{
	if(!head)
		return NULL;

	charList *newList = NULL;
	charList *p = head->next; ;
	uint8 initChr = head->key;
	uint32 count = 1;
	charList *newHead = NULL;

	while(p) {
		if(p->key == initChr) {
			count++;
			p = p->next;
		}
		else {
//			push(&newList, count);
//			push(&newList, initChr);
			initChr = p->key;
			count = 1;
			p = p->next;
		}
	}

	return newList;

}
#endif


/*
 *  1.24
 *  findBalancedNodeOfList(): Find the balancing factor in a linkedlist.
 *
 *  Input:
 *       *head --> Pointer to head;
 *
 *  Output:
 *        Node whose sum of left side is equals to sum of right side.
 */

bool findBalancedNodeOfList(singlelinkedlist *head)
{
	uint32 var = 0;
	singlelinkedlist *p = head;
	uint32 totalSum = getTotalSumList(head);
	uint32 remainSum = 0;
	uint32 currentSum = 0;

	while(p)
	{
		currentSum += p->key;
		remainSum = totalSum - currentSum;
		if(currentSum == remainSum - p->next->key)
		{
			printf("Balanced Node: %d\n", p->next->key);
			return true;
		}

		p = p->next;
	}

	return false;
}

/*
 *  1.25
 *  countDuplicateNodesList(): Find the balancing factor in a linkedlist.
 *
 *  Input:
 *       *head --> Pointer to head;
 *
 *  Output:
 *        Node whose sum of left side is equals to sum of right side.
 */

#if 0
void countDuplicateNodesList(singlelinkedlist *head)
{
	if(head == NULL)
		return;

	singlelinkedlist *p = head;
	mapper *mapEntries = NULL;
	uint32 len = countTotalNodesInList(head);

	mapEntries = initMapper(len);
	if(mapEntries == NULL) {
		printf("Failed to get the lookup table.\n");
		return;
	}

	while(p) {
		createNewEntry(mapEntries, p->key);
		p = p->next;
	}

	printTable(mapEntries);

	return;
}
#endif


/********************************************************** 
 * 1.26
 * Given a singly linked list and an integer k, remove the kth last element 
 * from the list. k is guaranteed to be smaller than the length of the list.
 *
 * The list is very long, so making more than one pass is prohibitively expensive.
 *
 * Do this in constant space and in one pass.
*************************************************************/

void removekthElementFromList(singlelinkedlist *head, uint32 kth) {
	if( !head || !kth)
		return; 	

	if(countTotalNodesInList(head) < kth)
		return; 

	singlelinkedlist *p = head; 
	singlelinkedlist *q = head;
   	singlelinkedlist *pv = NULL; 	

	while(kth--) {
		p = p->next; 
	}

	while(p) {
		pv = q; 
		q = q->next; 
		p = p->next; 
	}

	pv->next = q->next; 
	free(q); 
	return; 
}	

/************************************************************************************
 * ********************                                 *****************************
 * ********************      XOR LINKED LIST            *****************************
 * ********************                                 *****************************
 * *********************************************************************************/

xorlinkedlistnode *getNodeXOR(unsigned int var)
{
	xorlinkedlistnode *node = NULL;

	node = (xorlinkedlistnode *)malloc(sizeof(xorlinkedlistnode));
	if(node == NULL)
		return NULL;

	node->value = var;
	node->both = NULL;

	return node;
}


xorlinkedlistnode *XOR(xorlinkedlistnode *node1, xorlinkedlistnode *node2)
{
//	return (xorlinkedlistnode *) ((uint32 *)node1 ^ (uint32 *)node2);
	return NULL;
}


xorlinkedlistnode *insertNewNodeXOR(
		xorlinkedlistnode *head,
		unsigned int newVar)
{
	xorlinkedlistnode *newHead = NULL;
	xorlinkedlistnode *node = getNodeXOR(newVar);

	if(node == NULL)
	{
		printf("Failed to allocate memory. \n");
		return NULL;
	}

	node->both = XOR(head->both, NULL);

	if(head != NULL)
	{
		xorlinkedlistnode *next = XOR(head->both, NULL);
		head->both = XOR(node, next);
	}

	head = node;
	return head;
}


void printlistXOR(xorlinkedlistnode *head)
{
	xorlinkedlistnode *curr = head;
	xorlinkedlistnode *prev = NULL;
	xorlinkedlistnode *next;

	while(curr)
	{
		printf("%d --> ", curr->value);

		next = XOR(prev, curr->both);
		prev = curr;
		curr = next;
	}

	return;

}

doublelinkedlist *insertNewNode(
		doublelinkedlist *head,
		unsigned int newVar)
{
	doublelinkedlist *newHead = NULL;
	return newHead;
}

doublelinkedlist *deleteExVar(
		doublelinkedlist *head,
		unsigned int dVar)
{
	doublelinkedlist *newHead = NULL;
	return newHead;
}

xorlinkedlistnode *xorLinkedlist (xorlinkedlistnode *head)
{
	xorlinkedlistnode *newNode = NULL;
	return newNode;
}

/************************************************************************************
 * ********************                                 *****************************
 * ********************      DOUBLED LINKED LIST            *****************************
 * ********************                                 *****************************
 * *********************************************************************************/
