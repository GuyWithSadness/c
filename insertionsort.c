#include <stdio.h>

int *in_sort(int *a, int size);
void printarray(int *a, int size);
void swap(int *a, int *b);

int main()
{
	int a[8] = {4,3,2,10,12,1,5,6};
	int size;
	size = 8;
	printf("Before =");
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

/* Insertion sort

Pretty cool sort
Basically, we will compare the current one (key) with the previous one
if the previous one is larger than the key, shift the previous ne to the right
repeat until you find a value which is smaller than the key
then place the key in front of the smaller value

example

() means compared
-- means placed
2 5 1 6 3

1st Rotation
key = 5
2 is smaller than 5
no shifting needed
2 5 1 6 3


2nd rotation
key = 1
5 is larger than 1
shift 5 to the left
2 (5) -5- 6 3

compare with 2 now
2 is larger than 1
shift 2 to the left
(2) -2- 5 6 3

nothing to compare
place 1 at the end
1 2 5 6 3

3rd rotation
key = 6
5 is smaller than 6
no rotation needed
1 2 5 6 3

4th rotation
key = 3
6 is larger than 3
shift 6 to the left
1 2 5 (6) -6-

5 is larger than 3
shift 5 to the left
1 2 (5) -5- 6

2 is smaller than 3
place 3 in front of 2
1 (2) 3 5 6

done sorting
*/

int *in_sort(int *a, int size)
{
	int key, i, j;
	for (i = 0; i < size; i++){
		// key to compare with
		key = a[i];
		// compare with previous one
		j = i - 1;
		// keep checking until key is smaller than compared
		while (key < a[j] && j >= 0) {
			// shift the larger compared to the left
			a[j+1] = a[j];
			j--;
		}
		// place key in front of smaller value
		a[j+1] = key;
	}
}
