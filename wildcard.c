/*
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial)
*/

#include <stdbool.h>
#include <stdio.h>

bool isMatch(char * s, char * p){
	int x = 0;
    if (s[0] == '\0')
        if (s[0] == p[0] || p[0] == '*')
            return 1;
        else
            return 0;

	for (int i = 0, j = 0; ; ){
		printf("s string = %d = %c\n", i, s[i]);
		printf("p string = %d = %c\n\n", j, p[j]);
		if (s[i] != p[j]){
			if (p[j] == '*'){
				if (p[j+1] == '\0'){
					printf("end *\n");
					return 1;
				}
				else if (p[j+1] == '*'){
					j++;
					continue;
				}
				else{
					for (x; s[x] != '\0'; x++){};
					for (x; ; x--){
						if (x == -1)
							return 0;
						if (s[x] == p[j+1]){
							printf("found em %d\n", x);
							i = x - 1;
							break;
						}
					}
				}
			}
			else if (p[j] == '?'){
                if(s[i] == '\0'){
                    return 0;
                }
            }
            else
				return 0;
		}
		i++;
		j++;
		if (s[i] == p[j] && s[i] == '\0')
			break;
	}
	return 1;
}

int main()
{
	/*
	"adceb"
	"*a*b"
	*/
	char *s = "awhda";
	char *p = "*a";
	bool a = isMatch(s,p);
	printf("%d\n", a);
}
