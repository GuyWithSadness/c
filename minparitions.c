#define MAX(x, y) (x > y) ? (x) : (y)

int minPartitions(char * n){
	int sus = 0;
	for (int i = 0; n[i] != '\0'; i++)
		sus = MAX(sus, (n[i] - '0'));
	return (sus);
}

#include <stdio.h>
int main()
{
	char n[] = "2131231235123981208";
	int a = minPartitions(n);
	printf("%d\n", a);
}
