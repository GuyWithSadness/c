struct ListNode {
     int val;
     struct ListNode *next;
};

typedef struct ListNode list;

#include <stdio.h>
#include <stdlib.h>

void swap(list *a, list *b)
{
	int temp;

	temp = a->val;
	a->val = b->val;
	b->val = temp;
}

list *sort(list *list1)
{
	list *current, *current2;

	for (current = list1; current != NULL; current = current->next)
		for(current2 = current->next; current2 != NULL; current2 = current2->next)
			if (current->val > current2->val)
				swap(current, current2);

    return (list1);
}

int countList(list *list1)
{
	list * current;
	int count = 0;
	for (current = &list1[0]; current != NULL; current = current->next)
		count++;
	return (count);
}

struct ListNode* CopyList(struct ListNode* fulllist, struct ListNode* list1, int status)
{
	list *listcurrent = list1, *fullcurrent = fulllist;

	printf(" copying ");
	for (; status == 1; fullcurrent = fullcurrent->next)
	{
		printf("1");
		if (fullcurrent->next == NULL){
			printf("2");
			fullcurrent->next = (list*) malloc (sizeof(list));
			fullcurrent = fullcurrent->next;
			status = 0;
			break;
		}
	}

	while (1){
		printf("3");
		fullcurrent->val = listcurrent->val;
		if (listcurrent->next == NULL){
			printf("5");
			fullcurrent->next = NULL;
			break;
		}
		else {
			printf("4");
			fullcurrent->next = (list*) malloc (sizeof(list));
			fullcurrent = fullcurrent->next;
		}
		listcurrent = listcurrent->next;
	}

	return (fulllist);
}

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
	list* full;
	int list1len, list2len, totallen;
	list1len = countList(list1);
	list2len = countList(list2);
	totallen = list1len + list2len;
	printf("\nlength of list 1 = %d, length of list 2 = %d\n", list1len, list2len);

	int status = 0;
	list *fullcurrent = full;

	if (totallen != 0){
		full = (list*) malloc (sizeof(list));
		printf("4");
		if (list1len != 0){
			printf("\n5");
			CopyList(full, list1, status);
			status = 1;
		}
		if (list2len != 0){
			printf("\n6");
			CopyList(full, list2, status);
		}
		sort(full);
	return (full);
	} else
		return (NULL);
}


struct ListNode* makeList(int *numlist, int size) {
	list *list1 = (list *) malloc (sizeof(list)), *current = list1;
	int i;

	if (size != 0) {
		for (i = 0; i < (size - 1); i++)
		{
			current->val = numlist[i];
			current->next = (list *) malloc (sizeof(list));
			current = current->next;
		}
		current->val = numlist[i];
		current->next = NULL;
		return (list1);
	} else
		return NULL;
}

void PrintList(list *list1)
{
	for(list *current = list1; current != NULL; current = current->next)
	{
		printf("%d ", current->val);
		if (current->next != NULL)
			printf("-> ");
	}
}

int main()
{
	list * current;
	int numlist[] = {222, 103, 127, 85, 175, 141, 121, 53, 145, 194, 247, 228, 183, 44, 59, 47};
	int numlist2[] = {180, 50, 240, 104, 116, 163, 124, 188, 0, 142, 254, 251, 182, 206, 77, 241};
	list *list1;
	list *list2;

	list1 = makeList(numlist, 16);
	list2 = makeList(numlist2, 16);

	printf("first list ");
	PrintList(list1);

	printf("\nsecond list ");
	PrintList(list2);

	printf("\nmerging: ");
	list *fulllist = mergeTwoLists(list1, list2);
	printf("\n");
	printf("full list: ");
	PrintList(fulllist);
}
