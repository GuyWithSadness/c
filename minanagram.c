#define ABS(x) (-x)
#include <stdio.h>

int minSteps(char * s, char * t){
	int charfound[26] = {0};

	for (int i = 0; s[i] != '\0'; i++)
	{
		charfound[s[i] - 'a']++;
		charfound[t[i] - 'a']--;
	}
	int steps = 0;
	for (int i = 0; i < 26; i++)
	{
		printf("needed %c = %d\n", i+'a', charfound[i]);
		if (charfound[i] != 0)
		{
			if (charfound[i] < 0)
				ABS(charfound[i]);
			steps += charfound[i];
		}
	}

	return steps;
}

int main()
{
	printf("%d\n", minSteps("bob", "obo"));
}
