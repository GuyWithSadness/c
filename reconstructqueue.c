#include <stdio.h>
#include <stdlib.h>

void swap(int **num1, int **num2)
{
    int  *temp;

    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int ftintcmp(int *num1, int *num2)
{
	for(int i = 0; i < 2; i++)
		if (num1[i] != num2[i])
			return (num1[i] - num2[i]);
	return 0;
}

int **sort(int **tab, int length)
{
	for (int i = 0; i < (length - 1); i++)
		for (int j = i+1; j < length; j++)
			if (ftintcmp(tab[i], tab[j]) > 0)
				swap(&tab[i], &tab[j]);

	return (tab);
}

int** reconstructQueue(int** people, int peopleSize, int* peopleColSize, int* returnSize, int** returnColumnSizes){
	int **queue;
	queue = (int **) malloc (peopleSize * sizeof(int *));
	for (int i = 0; i < peopleSize; i++){
		queue[i] = (int *) malloc (2 * sizeof(int));
		queue[i][0] = 0;
	}

	printf("Queue -\n");
	for (int i = 0; i < 6; i++)
		printf("[ %d, %d ]", queue[i][0], queue[i][1]);
	printf("\n");
    // int n = peopleSize;
    // *returnSize = n;
    // *returnColumnSizes = (int*) malloc (sizeof(int) * n);
    // for(int i=0;  i < n ; i++) {
	// 	(*returnColumnSizes)[i] = 2;
	// }

	sort(people, peopleSize);

	printf("Sorted peoples -\n");

	for (int i = 0; i < peopleSize; i++)
		printf("[ %d, %d ]", people[i][0], people[i][1]);
	printf("\n");

	int j, x;

	for (int i = 0; i < peopleSize; i++){

		// printf("Queue -\n");
		// for (int i = 0; i < 6; i++)
		// 	printf("[ %d, %d ]", queue[i][0], queue[i][1]);
		// printf("\n");
	}
	return (queue);

}


int **peopleplacer(char *string)
{
	int **peopleplacer;
	int people;
	for (people = 0; string[people] != '\0'; people++){};
	people /= 2;
	peopleplacer = (int **) malloc (people * sizeof(int *));
	for (int i = 0; i < people; i++)
		peopleplacer[i] = (int *) malloc (2 * sizeof(int));
	for (int i = 0, j = 0, z = 0; string[i] != '\0'; i++)
	{
		if (z == 2){
			j++;
			z = 0;
		}
		peopleplacer[j][z] = string[i] - '0';
		z++;
	}
	return (peopleplacer);
}


int main(){
	int **people;
	char *a = "704471506152";
	people = peopleplacer(a);
	printf("Peoples -\n");
	for (int i = 0; i < 6; i++)
		printf("[ %d, %d ]", people[i][0], people[i][1]);
	printf("\n");
	int* returnSize;
	int** returnColumnSizes;
	int* peopleColSize;
	int **queue;
	queue = reconstructQueue(people, 6, peopleColSize, peopleColSize, returnColumnSizes);
	printf("Queue -\n");
	for (int i = 0; i < 6; i++)
		printf("[ %d, %d ]", queue[i][0], queue[i][1]);
	printf("\n");
}
