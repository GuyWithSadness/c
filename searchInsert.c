#include <stdio.h>

int BinSearch(int* nums, int start, int end, int target, int numsSize){
	int i = (start + end)/2;
	printf("Start = %d End = %d Midpoint = %d\n", start, end ,i);
	if (nums[i] == target){
		return (i);
	}
    else if (start == end){
        if (nums[end] > target)
		    return (end);
        else
            return (end + 1);
	}
	else if (nums[i] > target){
		BinSearch(nums, 0, (i - 1), target, numsSize);
	}
	else if (nums[i] < target){
		BinSearch(nums, (i + 1), end, target, numsSize);
	}
    return ;
}

int searchInsert(int* nums, int numsSize, int target){
	if (nums[0] > target)
		return (0);
	int ans = BinSearch(nums, 0, (numsSize - 1), target, numsSize);
	return ans;
}

int main()
{
	int nums[] = {1,3,5,6};
	int numsSize = sizeof(nums)/sizeof(nums[0]);
	int target = 2;
	int a = searchInsert(nums, numsSize, target);
	printf("%d", a);
}
