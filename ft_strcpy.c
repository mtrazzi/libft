#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	int i;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
