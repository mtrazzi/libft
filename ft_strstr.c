#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = (char *)haystack;
	i = 0;
	while (str[i])
	{
		j = 0;
		while (needle[j] && needle[j] == str[i + j])
			j++;
		if (j == ft_strlen(needle))
			return (str + i);
		i++;			
	}
	return (NULL);
}
