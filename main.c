#include "libft.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	printf("\natoi : %d\nft_atoi : %d", atoi(av[1]), ft_atoi(av[1]));
	return (0);
}
