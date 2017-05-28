/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrazzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 17:04:25 by mtrazzi           #+#    #+#             */
/*   Updated: 2017/05/28 18:10:49 by mtrazzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

int		main(int ac, char **av)
{
	char	*str1;
	char	*str2;
	int		n;
	size_t	n_p;
	int		i;

	if (ac != 4)
	{
		ft_putstr("Need three arguments : char *str1/dest, char *str2/src and int/size_t n");
		return (0);
	}
	str1 = strdup(av[1]);iii
	str2 = strdup(av[2]);
	n = atoi(av[3]);
	n_p = (size_t)n;
	i = 0;
	typedef void *  (*Ftn)(void *dst, const void *src, size_t m);
	Ftn	functions[] = {&ft_memcpy, &ft_memmove};
	Ftn functions_sol[] = {&memcpy, &memmove};
	while (i < 3)
	{
		ft_putstr("\n\n--------------------------------------------------------------------------------\n\n");
		functions[i](av[1], av[2], n_p);
		printf("my output : %s\nexpected output : %s", 
		i++;
	}
	
	return (0);
}
