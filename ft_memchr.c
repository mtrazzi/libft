#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned int	i;

	str = (unsigned char *)s;
	i = 0;
	while (i < n && str[i] != c)
		i++;
	if (i == n)
		return (NULL);
	return (str + i);
}
