#include "libft.h"

char	*ft_strdup(const char *s)
{
	char *temp;
	int i;

	i = 0;
	temp = (char *)malloc(sizeof(char)*ft_strlen(s));
	if (!temp)
		return (NULL);
	while (s[i])
	{
		temp[i] = s[i];
		i++;
	}
	return (temp);
}
