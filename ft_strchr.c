#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;
	char	*ans;
	
	ans = (char *)s; 
	i = 0;
	while (ans[i] && ans[i] != c)
		i++;
	if (ans[i] == c)
		return (ans + i);
	return (NULL);
}
