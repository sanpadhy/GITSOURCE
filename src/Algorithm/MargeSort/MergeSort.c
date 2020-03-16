
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
