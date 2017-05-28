/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrazzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 17:04:25 by mtrazzi           #+#    #+#             */
/*   Updated: 2017/05/28 21:10:46 by mtrazzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <ctype.h>

void	refresh(char **p1, char **p2, char **p1_bis, char **p2_bis, char *a1, char *a2)
{
		*p1 = ft_strdup(a1);
		*p1_bis = ft_strdup(a1);
		*p2 = ft_strdup(a2);
		*p2_bis = ft_strdup(a2);
}

void	line(void)
{
	printf("\n--------------------------------------------------------------------------------\n");
}

int		main(int ac, char **av)
{
	char	*str1 = strdup(av[1]);
	char	*str1_bis = strdup(av[1]);
	char	*str2 = strdup(av[2]);
	char	*str2_bis = strdup(av[2]);
	char	**p1 = &str1;
	char	**p1_bis = &str1_bis;
	char	**p2 = &str2;
	char	**p2_bis = &str2_bis;	
	int		n;
	size_t	n_p;
	int		i;

	if (ac != 4)
	{
		ft_putstr("Need three arguments : char *p1/dest, char *p2/src and int/size_t n");
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
	i = 0;
	while (i < 2)
	{
		line();
		refresh(p1, p2,p1_bis, p2_bis, av[1], av[2]);
		printf(">>>%s<<<\n", ( i == 1 ? "memcpy" : "memmove"));
		printf("my output :       %s\nexpected output : %s", ft_1[i](*p1, *p2, n_p), ft_1_sol[i](*p1_bis, *p2_bis, n_p));
		line();
		refresh(p1, p2,p1_bis, p2_bis, av[1], av[2]);
		printf(">>>%s<<<\n", ( i == 1 ? "strcpy" : "strcat"));
		printf("my output :       %s\nexpected output : %s", ft_3[i](*p1, *p2), ft_3_sol[i](*p1_bis, *p2_bis));
		line();
		refresh(p1, p2,p1_bis, p2_bis, av[1], av[2]);
		printf(">>>%s<<<\n", ( i == 1 ? "strncpy" : "strncat"));
		printf("my output :       %s\nexpected output : %s", ft_4[i](*p1, *p2, n_p), ft_4_sol[i](*p1_bis, *p2_bis, n_p));
		line();
		refresh(p1, p2,p1_bis, p2_bis, av[1], av[2]);
		printf(">>>%s<<<\n", ( i == 1 ? "strchr" : "strrchr"));
		printf("my output :       %s\nexpected output : %s", ft_5[i](*p1, n), ft_5_sol[i](*p1_bis, n));
		i++;
	}
	i = 0;
	typedef int (*Ft_2)(int);
	Ft_2	ft_2[] = {&ft_isalpha, &ft_isdigit, &ft_isalnum, &ft_isascii, &ft_isprint, &ft_toupper, &ft_tolower};
	Ft_2	ft_2_sol[] = {&isalpha, &isdigit, &isalnum, &isascii, &isprint, &toupper, &tolower};
	line();
	printf("\n>>>isalpha, isdigit, isalnum, isascii, isprint, toupper, tolower<<<");
	
	while (i < 7)
	{
		line();
		refresh(p1, p2,p1_bis, p2_bis, av[1], av[2]);
		printf("my output :       %d\nexpected output : %d", ft_2[i](n), ft_2_sol[i](n));
		i++;
	}

	line();
	refresh(p1, p2,p1_bis, p2_bis, av[1], av[2]);
	printf(">>>%s<<<\n", "ft_bzero");
	printf("my output :       %s\nexpected output : %s", ft_bzero(*p1, n_p), bzero(*p1, n_p));

	line();
	refresh(p1, p2,p1_bis, p2_bis, av[1], av[2]);
	printf(">>>%s<<<\n", "ft_bzero");
	printf("my output :       %s\nexpected output : %s", ft_bzero(*p1, n_p), bzero(*p1, n_p));


	return (0);
}
