bool isPolindrom(singlelinkedlist *head)
{
	singlelinkedlist *fast = head;
	singlelinkedlist * slow = head;

	while(fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	/* NOTE: Here the slow pointer will change based on no. of elements in list. */
	unsigned int nNodes = countTotalNodesInList(head);

	if (nNodes%2 == 0)
		slow = reverseLinkedList(slow);
	else
		slow = reverseLinkedList(slow->next);

	fast = head;

	while(slow != NULL)
	{
		if (slow->value != fast->value)
			return false;

		slow = slow->next;
		fast = fast->next;
	}

	return true;
}
