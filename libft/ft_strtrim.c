#include "libft.h"
#include "ft_substr.c"
#include "ft_strdup.c"

int	ft_inset(char c, char const *set){
	int	i;

	i = -1;
	while (set[++i] != '\0')
		if (set[i] == c)
			return 1;
	return 0;
}
char *ft_strtrim(char const *s1, char const *set){
	char	*trimmed;
	char	s1len;
	int		begin;
	int		size;
	int		end;

	if (s1 || set){
		begin = -1;
		s1len = ft_strlen((char *) s1);
		if (s1len){
			end = s1len;
			size = s1len;
			while (ft_inset(s1[++begin], set) == 1)
				size--;
			if (begin != s1len){
				while (ft_inset(s1[--end], set) == 1)
					size--;
				trimmed = ft_substr(s1, begin, size);
			} else
				trimmed = ft_strdup("");
			if (trimmed)
				return (trimmed);
		}
	}
	return 0;
}
