#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned int i;
	char	     *answer;

	i = 0;
	answer = (char*)s;
	while (i < n)
	{
		answer[i] = '\0';
		i++;
	}
	s = (void *)answer;
}
