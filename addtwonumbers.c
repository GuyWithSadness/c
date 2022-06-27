
struct ListNode {
     int val;
     struct ListNode *next;
};

typedef struct ListNode LinkedList;

#include <stdio.h>
#include <stdlib.h>

void PrintList(LinkedList *list)
{
	LinkedList *current = list;
	int count = 0;
	printf("\n");
	for (current; current != NULL; current = current->next){
		printf("%d ", current->val);
		count++;
	}
	printf("\nprinted %d letters\n", count);
	printf("\n");
}

LinkedList *MakeList(int *num, int size)
{
	LinkedList *list, *current;
	int i;

	if (size == 0)
		return NULL;

	list = (LinkedList *) malloc (sizeof(LinkedList));
	for (i = 0, current = list; i < size; i++, current = current->next)
	{
		current->val = num[i];
		if (i == (size - 1)){
			current->next = NULL;}
		else
			current->next = (LinkedList *) malloc (sizeof(LinkedList));
	}

	return (list);
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
	// int l1len = CountNode(l1), l2len = CountNode(l2);
	// printf("list 1 = %d, list 2 = %d\n", l1len, l2len);
	// int size = (l1len > l2len) ? (l1len) : (l2len);
	// printf("%d\n", size);
	LinkedList *ans;
	ans = (LinkedList *) malloc (sizeof(LinkedList));

	LinkedList *l1ptr = l1, *l2ptr = l2, *ansptr = ans;
	int carry = 0, value;

	while (!(l1ptr == NULL && l2ptr == NULL && carry == 0))
	{
		value = 0;

		if (carry == 1 && !(--carry))
			value++;

		if (l1ptr != NULL) {
			value += l1ptr->val;
			l1ptr = l1ptr->next;
		}

		if (l2ptr != NULL) {
			value += l2ptr->val;
			l2ptr = l2ptr->next;
		}

		if (value >= 10 && ++carry)
			value -= 10;

		ansptr->val = value;
		if (l2ptr == NULL && l1ptr == NULL && carry == 0)
			ansptr->next = NULL;
		else
			ansptr->next = (LinkedList *) malloc (sizeof(LinkedList));
		ansptr = ansptr->next;
	}
	return ans;
}


int main()
{
	int num1[] = {2,4,3};
	int num2[] = {5,6,4};
	LinkedList *list1 = MakeList(num1, 3);
	LinkedList *list2 = MakeList(num2, 3);
	PrintList(list1);
	PrintList(list2);
	LinkedList *ans;
	ans = addTwoNumbers(list1, list2);
	PrintList(ans);
}
