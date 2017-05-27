#include "libft.h"
int	ft_atoi(const char *nptr)
{
	int n;
	int s;
	int i;

	i = 0;
	s = 1;
	n = 0;
	while (nptr[i] == ' ')
		i++;
	if (nptr[i] == '-')
		s = -1;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (48 <= nptr[i] && nptr[i] <= 57)
	{
		n = 10 * n + nptr[i] - 48;
		i++;
	}
	return (s*n);
}
