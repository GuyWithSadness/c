#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct ListNode{
    int val;
    struct ListNode *next;
};

struct ListNode* makeList(int *numlist, int size)
{
    struct ListNode *list1 = (struct ListNode *) malloc (sizeof(struct ListNode) * size);
    for (int i = 0; i < size; i++)
        list1[i].val = numlist[i];
    int i;

    for (i = 0; i < (size - 1); i++)
        list1[i].next = &list1[i + 1];
    list1[i].next = NULL;

    return (list1);
}

void insertFirst(struct ListNode** head, int val)
{
    struct ListNode *link = (struct ListNode*) malloc(sizeof(struct ListNode));

    link -> val = val;
    link -> next = *head;
    *head = link;
}

void insertAfter(struct ListNode* node, int val, int find)
{
	struct ListNode *current;
	struct ListNode *link;

	for (current = &node[0]; current != NULL; current = current->next){
		if (current->val == find) {
			link = (struct ListNode*) malloc(sizeof(struct ListNode));
			link -> val = val;
			link -> next = current -> next;
			current -> next = link;
		}
	}
}

void printList(struct ListNode* head) {
    struct ListNode* current = head;

    while (current != NULL) {
        printf("%d", current->val);
        printf(" -> ");
        current = current->next;
    }
}

int main()
{
    int numlist[] = {1,2,3,4,5,6,7};
    struct ListNode *listlist;
    listlist = makeList(numlist, 7);
    insertFirst(&listlist, 1);
    insertAfter(listlist, 10, 5);
    printList(listlist);
}
