#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	j;

	while (dest[i] && i < n)
		i++;
	if (i == n)
		return (n);
	j = 0;
	while (src[j] && j < n - i - 1)
	{
		dest[i + j] = src[i];
		j++;
	}
	dest[i + j] = '\0';
	return (i + j);
}
