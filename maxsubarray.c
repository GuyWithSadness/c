#include <limits.h>

// brute force approach
// too slow d NANGIS

// int AddAll(int *nums, int start, int end);
// int maxSubArray(int* nums, int numsSize);

// int maxSubArray(int* nums, int numsSize)
// {
// 	int max = INT_MIN, start = 0, end = (numsSize - 1), result;
// 	for (start; start <= end; start++)
// 	{
// 		for (int i = end; i >= start; i--){
// 			result = AddAll(nums, start, i);
// 			if (result > max)
// 				max = result;
// 		}
// 	}
// 	return max;
// }

// int AddAll(int *nums, int start, int end)
// {
// 	int result = 0;
// 	for (start; start <= end; start++)
// 		result += nums[start];
// 	return (result);
// }

#include <stdio.h>

// Kandaes Algorithm
// if
// 1. array is filled with only positive numbers
// - the maxSubArray is the sum of all numbers

// 2. array is filled with negative numbers
// - the maxSubArray is the largest negative number

// 3. mixed
// - if -1, 2, 3, 4
// the maxSubArray is 2,3,4

// - if -1, 2, -3, 4
// maxSubarray is 4
// because -1 + 2 = -1;
// 2 + (-3) = -1;
// 2 + (-3) + 4 = 3;

// - if -1, 2, -3, -4
// maxSubarray is 2

// everytime the counter drops to negative, we can immediately reset the counter back to 0
// - if -1, 2;
// 0th index - counter would be 0 + index = -1, resetted back to 0, max is -1;
// 1st index - counter would be 0 + index = 2, max is 2;

// - if 5,4,-10, 7
// 0th index - counter would be 0 + index = 5, max is 5;
// 1st index - counter would be 5 + index = 9, max is 9;
// 2nd index - counter would be 9 + index = -1, resetted back to 0, max is 9;
// 3rd index - counter would be 0 + index = 7, max is 9;
// lessay if the last element (7), changed to 21;
// 3rd index - counter would be 0 + index = 21, max is 21;

// - if 5,4,-1, 7, -10
// 0th index - counter would be 0 + index = 5, max is 5;
// 1st index - counter would be 5 + index = 9, max is 9;
// 2nd index - counter would be 9 + index = 8, max is 9;
// 3rd index - counter would be 8 + index = 15, max is 15;
// 4th index - counte rwould be 15 + index = 5; max is 15;

int maxSubArray(int arr[], int n) {
	int maxSum = INT_MIN, currSum = 0;
	for (int i = 0; i <= n - 1; i++) {
		currSum += arr[i];
		if (currSum > maxSum)
			maxSum = currSum;
		if (currSum < 0)
			currSum = 0;
	}

	return maxSum;
}

int main() {
	int nums[] = { 5,4,-10, 21};
	int numsSize = sizeof(nums)/sizeof(nums[0]);
	printf("%d", maxSubArray(nums, numsSize));
}
