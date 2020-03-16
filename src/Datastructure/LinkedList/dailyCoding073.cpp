typedef struct singlelinkedlist_t_ {
	struct singlelinkedlist_t_ *next;
	unsigned int value;
}singlelinkedlist;

singlelinkedlist *reverseLinkedList (
		singlelinkedlist *head)
{
	if(head == NULL && head->next == NULL)
		return head;

	singlelinkedlist *p = head;
	singlelinkedlist *pv = NULL;
	singlelinkedlist *nx = p->next;

	while(nx)
	{
		printf("%d\n", p->value);
		p->next = pv;
		pv = p;
		p = nx;
		nx = nx->next;
	}

	p->next = pv;

	return p;
}
