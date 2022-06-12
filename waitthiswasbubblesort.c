#include <stdio.h>

int *in_sort(int *a, int size);
void printarray(int *a, int size);
void swap(int *a, int *b);

int main()
{
	int a[8] = {4,3,2,10,12,1,5,6};
	int size;
	size = 8;
	printf("Before = ");
	printarray(a, size);
	in_sort(a, size);
	printf("After = ");
	printarray(a, size);
}

void printarray(int *a, int size)
{
	for (int i = 0; i < size; i++)
		printf("%d ",a[i]);
	printf("\n");
}

int *in_sort(int *a, int size)
{
	int count;
	int compare;

	count = 1;
	for (count = 1; count < size; count++)
		for (compare = count - 1; compare >= 0; compare--)
			if (a[count] < a[compare])
			{
				swap(&a[count], &a[compare]);
				count = compare;
				compare = count - 1;
			}
	return(a);
}

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
