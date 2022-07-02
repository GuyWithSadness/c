// 13 bits
// 11 bits for numbers, 1 bit for sign, 1 bit for terminate
// there are only 12 actual bits

#include <stdio.h>
#include <stdlib.h>

void rev(char *bits)
{
	int start = 1, end = 11;
	int temp;
	for (int count = 0; count <= 5; count++, start++, end--)
	{
		temp = bits[start];
		bits[start] = bits[end];
		bits[end] = temp;
	}
}

char *bits(int num)
{
	int i = 0;
	char *bits;
	bits = (char *) malloc (13 * sizeof(char));

	// if num is negative, -, if positive +;
	(num < 0) ? (bits[i] = '-', num *= -1) : (bits[i] = '+');

	for (i = 1; i < 12; i++, num /= 2){
		bits[i] = (num % 2) + '0';
	}

	rev(bits);
	bits[12] = '\0';
	return(bits);
}

int ReadBits(char *bits)
{
	int result = 0, negative = 1;
	int i = 0;
	if (bits[0] == '-')
		negative *= -1;

	for (i = 1; i < 12 ; i++)
		result = (result * 2) + bits[i] - '0';

	return (result * negative);
}

char *Add(char *bita, char *bitb, char *ansbit){
	int carry = 0, value, futurecarry = 0;
	for (int i = 11; i != 0; i--)
	{
		value = 0;
		carry = futurecarry;

		futurecarry = 0;
		if (bita[i] == bitb[i]) {
			if (bita[i] == '1' && bitb[i] == '1'){
				futurecarry = 1;
			}
		}
		else
			value = 1;

		if (carry == 1){
			if (value == 1 && !(--carry)){
				value = 0;
				futurecarry = 1;
			}
			else if (value == 0 && !(--carry))
				value = 1;
		}

		ansbit[i] = value + '0';
	}
	return ansbit;
}

int getSum(int a, int b) {
	char *bita = bits(a);
	char *bitb = bits(b);
	char *negative, *positive;

	printf("%s\n", bita);
	printf("%s\n", bitb);

	char *ansbit = (char *) malloc (13 * sizeof(char));
	for (int i = 0; i < 12; i++)
		ansbit[i] = '0';
	ansbit[12] = '\0';

	if (bita[0] == bitb[0]){
		ansbit[0] = bita[0];
		Add(bita, bitb, ansbit);
	}
	else {
		// do subtract here (eventually)
	}
	printf("%s\n", ansbit);
	int ans = ReadBits(ansbit);
	return (ans);
}

int main()
{
	int ans = getSum(999,111);
	printf("\n%d", ans);
}
