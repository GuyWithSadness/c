#include <stdio.h>
#include <stdlib.h>

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

    for (start; start < end; start++)
    {
        if (tab[start] > pivot)
        {
            swap(tab[start], tab[end - 1]);
            swap(tab[end], tab[end - 1]);
            end--;
        }
    }
    return end;
}

void sort(int* tab, int start, int end, int size)
{
    int pivotindex;
    // Attempt to quicksort, Part 1;
    pivotindex = partition(tab, start, end);
    if (start < end)
    {
        sort(tab, (pivot + 1), end);
        sort(tab, start, (pivot - 1));
    }
    
}

double findMedianSortedArrays(int* num1, int num1size, int* num2, int num2size)
{
    int median, totalsize;
    int *all;

    totalsize = num2size + num1size;
    all = (int *) malloc (totalsize * sizeof(int));

    for (int i = 0; i < num1size; i++)
        all[i] = num1[i];

    for (int i = 0; i < num2size; i++)
        all[i] = num2[i];

    sort(all, totalsize);

    if (totalsize % 2 == 0)
        median = (all[totalsize / 2] + all[(totalsize / 2) + 1]) / 2;
    else if (totalsize % 2 == 1)
        all[(totalsize / 2) + 1]; 

    return median;
}