typedef struct singlelinkedlist_t_ {
	struct singlelinkedlist_t_ *next;
	unsigned int value;
}singlelinkedlist;

singlelinkedlist *removeKthElemFromLast(singlelinkedlist *head, unsigned int k)
{
	singlelinkedlist *p = head;
	singlelinkedlist *q = head;
	singlelinkedlist *t = NULL;

	while(k--) {
		if(q == NULL)
		{
			printf("k is longer then the length of list. \n");
			return head;
		}

		q = q->next;
	}

	while(q != NULL)
	{
		t = p;
		p = p->next;
		q = q->next;
	}

	t->next = p->next;

	free(p);

	return head;
}

