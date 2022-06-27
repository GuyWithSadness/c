	list *fulllist = mergeTwoLists(listlist, listlist2);
	current = &fulllist[0];
	while (current != NULL)
	{
		printf("%d ", current->val);
		current = current->next;
	}