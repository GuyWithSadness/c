// easy version
#include <stdio.h>
int getSum(int a, int b)
{
	int total = 0, sum = 0;
	printf("a = %d, b = %d\n",a,b);

	for (total = 0; total < a; total++);
	for (sum = 0; sum < b; sum++, total++);
	return (total);
}

int main()
{
	printf("%d", getSum(5,9));
}
