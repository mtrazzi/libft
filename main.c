/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrazzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 17:04:25 by mtrazzi           #+#    #+#             */
/*   Updated: 2017/05/28 19:37:59 by mtrazzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <ctype.h>

void	refresh(char *str1, char *str2, char *str1_bis, char *str2_bis, char *a1, char *a2)
{
		str1 = strdup(a1);
		str1_bis = strdup(a1);
		str2 = strdup(a2);
		str2_bis = strdup(a2);
}

void	line(void)
{
	printf("\n\n--------------------------------------------------------------------------------\n\n");
}

int		main(int ac, char **av)
{
	char	*str1 = strdup(av[1]);
	char	*str1_bis = strdup(av[1]);
	char	*str2 = strdup(av[2]);
	char	*str2_bis = strdup(av[2]);
	int		n;
	size_t	n_p;
	int		i;

	if (ac != 4)
	{
		ft_putstr("Need three arguments : char *str1/dest, char *str2/src and int/size_t n");
		return (0);
	}
	n = atoi(av[3]);
	n_p = (size_t)n;

	typedef void *  (*Ft_1)(void *, const void *, size_t);
	Ft_1	ft_1[] = {&ft_memcpy, &ft_memmove};
	Ft_1	ft_1_sol[] = {&memcpy, &memmove};
	typedef char *  (*Ft_3)(char *, const char *);
	Ft_3	ft_3[] = {&ft_strcpy, &ft_strcat};
	Ft_3	ft_3_sol[] = {&strcpy, &strcat};
	typedef char *  (*Ft_4)(char *, const char *, size_t);
	Ft_4	ft_4[] = {&ft_strncpy, &ft_strncat};
	Ft_4	ft_4_sol[] = {&strncpy, &strncat};
	typedef char *  (*Ft_5)(const char *, int);
	Ft_5	ft_5[] = {&ft_strchr, &ft_strrchr};
	Ft_5	ft_5_sol[] = {&strchr, &strrchr};
	printf("\n\n\n\n>>>>>>>>>>>>>>>>>>>> memcpy memmove <<<<<<<<<<<<<<<<<<<<<<<<\n\n\n\n");
	i = 0;
	while (i < 2)
	{
		line();
		refresh(str1, str2,str1_bis, str2_bis, av[1], av[2]);
		printf("my output :       %s\nexpected output : %s", ft_1[i](str1, str2, n_p), ft_1_sol[i](str1_bis, str2_bis, n_p));
		line();
		refresh(str1, str2,str1_bis, str2_bis, av[1], av[2]);
		printf("my output :       %s\nexpected output : %s", ft_3[i](str1, str2), ft_3_sol[i](str1_bis, str2_bis));
		line();
		refresh(str1, str2,str1_bis, str2_bis, av[1], av[2]);
		printf("my output :       %s\nexpected output : %s", ft_4[i](str1, str2, n_p), ft_4_sol[i](str1_bis, str2_bis, n_p));
		line();
		refresh(str1, str2,str1_bis, str2_bis, av[1], av[2]);
		printf("my output :       %s\nexpected output : %s", ft_5[i](str1, n), ft_5_sol[i](str1_bis, n));
		i++;
	}

	i = 0;

	typedef int (*Ft_2)(int);
	Ft_2	ft_2[] = {&ft_isalpha, &ft_isdigit, &ft_isalnum, &ft_isascii, &ft_isprint, &ft_toupper, &ft_tolower};
	Ft_2	ft_2_sol[] = {&isalpha, &isdigit, &isalnum, &isascii, &isprint, &toupper, &tolower};
	printf("\n\n\n\n>>>>>>>>>>>>>>>>>>>> isalpha, isdigit, isalnum, isascii, isprint, toupper, tolower <<<<<<<<<<<<<<<<<<<<<<<<\n\n\n\n");
	while (i < 7)
	{
		
		line();
		refresh(str1, str2,str1_bis, str2_bis, av[1], av[2]);
		printf("my output :       %d\nexpected output : %d", ft_2[i](n), ft_2_sol[i](n));
		i++;
	}
	return (0);
}
