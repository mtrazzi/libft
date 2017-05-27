#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	char	*ans;
	
	ans = (char *)s; 
	i = ft_strlen(ans) - 1;
	if (c == 0)
		return (ans + i + 1);
	while (i >= 0 && ans[i] != c)
		i--;
	if (i >= 0)
		return (ans + i);
	return (NULL);
}
