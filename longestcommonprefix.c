#include <stdio.h>
#include <stdlib.h>

int ftstrcmp(char *str1, char *str2)
{
	int count;
	for (count = 0; str1[count] == str2[count] && str1[count] != '\0' &&str2[count] != '\0'; count++){};
	return count;
}

char * longestCommonPrefix(char ** strs, int strsSize){
	char *prefix;
	prefix = (char *) malloc (sizeof(char));
	prefix[0] = '\0';
	if (strsSize == 0)
		return (prefix);
	if (strsSize == 1)
		return (strs[0]);
	for (int i = 0; i < (strsSize - 1); i++)
	{
		if (strs[i][0] != strs[i+1][0] || strs[i][0] == '\0'){
			return (prefix);
		}
	}
	free(prefix);

	int smallest = 200, count = 0;

	for (int i = 0; i < (strsSize - 1); i++)
		for (int j = i+1, count = 0; j < (strsSize); j++)
		{
			count = ftstrcmp(strs[i], strs[j]);
			if (count < smallest)
				smallest = count;
		}
	prefix = (char *) malloc ((smallest + 1) * sizeof(char));

	for (int i = 0; i < (smallest); i++)
		prefix[i] = strs[0][i];
	prefix[smallest] = '\0';

	return (prefix);
}

int main()
{
	char *test[] = {
		"acc",
		"aaa",
		"aaba"
	};
	printf("%s", longestCommonPrefix(test,3));
}
