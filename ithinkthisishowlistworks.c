#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

typedef struct ListNode list;

struct ListNode* makeList(int *numlist, int size)
{
	list *list1 = (list *) malloc (sizeof(list) * size);
	for (int i = 0; i < size; i++)
		list1[i].val = numlist[i];
	int i;

	for (i = 0; i < (size - 1); i++)
		list1[i].next = &list1[i + 1];
	list1[i].next = NULL;

	return (list1);
}

void print_list(list * head) {
    list * current = head;

    while (current != NULL) {
        printf("%d\n", current->val);
        current = current->next;
    }
}

int main()
{
	int numlist[] = {1,2,3,4,5,6,7};
	list *listlist;
	listlist = makeList(numlist, 7);
	print_list(listlist);
}
