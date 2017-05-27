#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int i;
	char	     *s;
	char	     *d;

	i = 0;
	s = (char *)src;
	d = (char *)dest;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	dest = (void *)d;
	return (dest);
}
