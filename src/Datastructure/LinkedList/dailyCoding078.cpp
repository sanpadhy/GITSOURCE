typedef struct singlelinkedlist_t_ {
	struct singlelinkedlist_t_ *next;
	unsigned int value;
}singlelinkedlist;


singlelinkedlist *mergeLists(singlelinkedlist *list1, singlelinkedlist *list2)
{
	if(list1 == NULL)
		return list2;

	if(list2 == NULL)
		return list1;

	singlelinkedlist *newList = NULL;

	if(list1->value < list2->value)
	{
		newList = list1;
		newList->next = mergeLists(list1->next, list2);
	}
	else
	{
		newList = list2;
		newList->next = mergeLists(list1, list2->next);
	}

	return newList;

}

void mergeSortLinkedList(singlelinkedlist **head)
{
	singlelinkedlist *nodePtr = *head;
	singlelinkedlist *list1 = NULL;
	singlelinkedlist *list2 = NULL;

	if(nodePtr == NULL || nodePtr->next == NULL)
		return;

	partitionListInHalf(*head, &list1, &list2);

	mergeSortLinkedList(&list1);
	mergeSortLinkedList(&list2);

	*head = mergeLists(list1, list2);
}

