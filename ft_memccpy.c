#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned int i;
	char	     *s;
	char	     *d;

	i = 0;
	s = (char *)src;
	d = (char *)dest;
	while (i < n && s[i] != c)
	{
		d[i] = s[i];
		i++;
	}
	dest = (void *)d;
	return (dest);
}
