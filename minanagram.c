#include <stdio.h>

int minSteps(char * s, char * t){
	int charfound[26] = {0};

	for (int i = 0; s[i] != '\0'; i++)
	{
		charfound[s[i] - 'a']++;
		charfound[t[i] - 'a']--;
	}
	int missing = 0;
	int extra = 0;
	for (int i = 0; i < 26; i++)
	{
		if (charfound[i] != 0)
		{
			if (charfound[i] < 0)
				extra += -(charfound[i]);
			else
				missing += charfound[i];
		}
	}
	if (extra == missing)
		return (extra);
}

int main()
{
	printf("%d\n", minSteps("bobkkkkk", "obokkokok"));
}
