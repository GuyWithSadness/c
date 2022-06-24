#include <stdlib.h>

// HOHOHOH the quicksort worked
// im pretty sure this is quicksort

void swap(int *num1, int *num2)
{
    int temp;

    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int partition(int *tab, int start, int end)
{
    int pivot = tab[end];
	while (start < end)
    {
        if (tab[start] > pivot)
        {
            swap(&tab[start], &tab[end - 1]);
            swap(&tab[end], &tab[end - 1]);
            end--;
        } else
		start++;
    }
    return end;
}

void sort(int* tab, int start, int end, int totalsize)
{
    int pivotindex;
    if (start < end)
    {
		pivotindex = partition(tab, start, end);

        sort(tab, (pivotindex + 1), end, totalsize);
        sort(tab, start, (pivotindex - 1), totalsize);
    }
}


// this is another thingy
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int totalsize, i;
	double median;
    int *all;

    totalsize = nums2Size + nums1Size;
    all = (int *) malloc (totalsize * sizeof(int));

    for (i = 0; i < nums1Size; i++)
        all[i] = nums1[i];

    for (int j = 0; j < nums2Size; i++, j++)
        all[i] = nums2[j];

    sort(all, 0, totalsize - 1, totalsize);

    if (totalsize % 2 == 0)
        median = ((double) (all[totalsize / 2]) + (double) (all[(totalsize / 2) - 1])) / 2;
    else if (totalsize % 2 == 1)
        median = (double) (all[(totalsize / 2)]);

    return (median);
}

#include <stdio.h>
int main()
{
	int num1[] = {0,0,0,0,0};
	int num2[] = {-1,0,0,0,0,0,1};
	int size1 = (sizeof(num1)/sizeof(num1[0]));
	int size2 = (sizeof(num2)/sizeof(num2[0]));
	double median = findMedianSortedArrays(num1, size1, num2, size2);
	printf("The median is %f", median);
}
