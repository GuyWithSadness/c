#include <stdlib.h>
#include <stdio.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int x = 0;
    int y = 1;

    while (x < numsSize)
    {
        while (y < numsSize)
        {
            if ((nums[x] + nums[y]) == target)
            {
                returnSize = (int *) malloc (sizeof(int) * 2);
                returnSize[0] = x;
                returnSize[1] = y;

                return (returnSize);
            }
            y++;
        }
        y = 1;
        x++;
    }
}
