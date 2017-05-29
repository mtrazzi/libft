/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrazzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 17:04:25 by mtrazzi           #+#    #+#             */
/*   Updated: 2017/05/29 14:05:23 by mtrazzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <ctype.h>

void	refresh(char **p1, char **p2, char **p1_bis, char **p2_bis, char *a1, char *a2, char *message)
{
		printf("\n--------------------------------------------------------------------------------\n");
		printf(">>>%s<<<\n", message);
		*p1 = ft_strdup(a1);
		*p1_bis = ft_strdup(a1);
		*p2 = ft_strdup(a2);
		*p2_bis = ft_strdup(a2);
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
	int		c;

	if (ac != 5)
	{
		ft_putstr("Need four arguments : char *p1/dest, char *p2/src and int/size_t n and c");
		return (0);
	}
	n = atoi(av[3]);
	n_p = (size_t)n;
	c = av[4][0];
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
	i = -1;
	while (++i < 2)
	{
		refresh(p1, p2,p1_bis, p2_bis, av[1], av[2], ( i == 1 ? "memcpy" : "memmove"));
		printf("my output :       %s\nexpected output : %s", ft_1[i](*p1, *p2, n_p), ft_1_sol[i](*p1_bis, *p2_bis, n_p));
		refresh(p1, p2,p1_bis, p2_bis, av[1], av[2], ( i == 1 ? "strcpy" : "strcat"));
		printf("my output :       %s\nexpected output : %s", ft_3[i](*p1, *p2), ft_3_sol[i](*p1_bis, *p2_bis));
		refresh(p1, p2,p1_bis, p2_bis, av[1], av[2], ( i == 1 ? "strncpy" : "strncat"));
		printf("my output :       %s\nexpected output : %s", ft_4[i](*p1, *p2, n_p), ft_4_sol[i](*p1_bis, *p2_bis, n_p));
		refresh(p1, p2,p1_bis, p2_bis, av[1], av[2], ( i == 1 ? "strchr" : "strrchr"));
		printf("my output :       %s\nexpected output : %s", ft_5[i](*p1, n), ft_5_sol[i](*p1_bis, n));
		i++;
	}
	i = -1;
	typedef int (*Ft_2)(int);
	Ft_2	ft_2[] = {&ft_isalpha, &ft_isdigit, &ft_isalnum, &ft_isascii, &ft_isprint, &ft_toupper, &ft_tolower};
	Ft_2	ft_2_sol[] = {&isalpha, &isdigit, &isalnum, &isascii, &isprint, &toupper, &tolower};
	char *	messages[] = {"isalpha", "isdigit", "isalnum", "isascii", "isprint", "toupper", "tolower"};
	while (++i < 7)
	{
		refresh(p1, p2,p1_bis, p2_bis, av[1], av[2], messages[i]);
		printf("my output :       %d\nexpected output : %d", ft_2[i](c), ft_2_sol[i](c));
	}
	refresh(p1, p2,p1_bis, p2_bis, av[1], av[2], "ft_bzero");
	ft_bzero(*p1, n_p);
   	bzero(*p1_bis, n_p);
	printf("my output :       %s\nexpected output : %s", *p1, *p1_bis);
	refresh(p1, p2,p1_bis, p2_bis, av[1], av[2], "memccpy");
	printf("my output :       %s\nexpected output : %s", ft_memccpy(*p1, *p2, c, n_p), memccpy(*p1_bis, *p2_bis, c, n_p));
	refresh(p1, p2,p1_bis, p2_bis, av[1], av[2], "memset");
	printf("my output :       %s\nexpected output : %s", ft_memset(*p1, c, n_p), memset(*p1_bis, c, n_p));
	refresh(p1, p2,p1_bis, p2_bis, av[1], av[2], "memchr");
	printf("my output :       %s\nexpected output : %s", ft_memchr(*p1, c, n_p), memchr(*p1_bis, c, n_p));
	refresh(p1, p2,p1_bis, p2_bis, av[1], av[2], "memcmp");
	printf("my output :       %d\nexpected output : %d", ft_memcmp(*p1, *p2, n_p), memcmp(*p1_bis, *p2_bis, n_p));
	refresh(p1, p2,p1_bis, p2_bis, av[1], av[2], "strlen");
	printf("my output :       %zu\nexpected output : %zu", ft_strlen(*p1), strlen(*p1_bis));
	refresh(p1, p2,p1_bis, p2_bis, av[1], av[2], "strdup");
	printf("my output :       %s\nexpected output : %s", ft_strdup(*p1), strdup(*p1_bis));
	refresh(p1, p2,p1_bis, p2_bis, av[1], av[2], "strlcat");
	printf("my output :       %zu\nexpected output : %zu", ft_strlcat(*p1, *p2, n_p), strlcat(*p1_bis, *p2_bis, n_p));
	refresh(p1, p2,p1_bis, p2_bis, av[1], av[2], "strstr");
	printf("my output :       %s\nexpected output : %s", ft_strstr(*p1, *p2), strstr(*p1_bis, *p2_bis));
	refresh(p1, p2,p1_bis, p2_bis, av[1], av[2], "strnstr");
	printf("my output :       %s\nexpected output : %s", ft_strnstr(*p1, *p2, n_p), strnstr(*p1_bis, *p2_bis, n_p));
	refresh(p1, p2,p1_bis, p2_bis, av[1], av[2], "strcmp");
	printf("my output :       %d\nexpected output : %d", ft_strcmp(*p1, *p2), strcmp(*p1_bis, *p2_bis));
	refresh(p1, p2,p1_bis, p2_bis, av[1], av[2], "strncmp");
	printf("my output :       %d\nexpected output : %d", ft_strncmp(*p1, *p2, n_p), strncmp(*p1_bis, *p2_bis, n_p));
	refresh(p1, p2,p1_bis, p2_bis, av[1], av[2], "atoi");
	printf("my output :       %d\nexpected output : %d\n", ft_atoi("-42"), atoi("-42"));
	printf("my output :       %d\nexpected output : %d\n", ft_atoi("-2147483648"), atoi("-2147483648"));
	printf("my output :       %d\nexpected output : %d\n", ft_atoi("2147483647"), atoi("2147483647"));
	printf("my output :       %d\nexpected output : %d\n", ft_atoi("++42"), atoi("++42"));
	printf("my output :       %d\nexpected output : %d\n", ft_atoi("          42abc"), atoi("          42abc"));
	printf("my output :       %d\nexpected output : %d\n", ft_atoi("          -42abc"), atoi("          -42abc"));
	printf("my output :       %d\nexpected output : %d\n", ft_atoi("   abc42"), atoi("   abc42"));
	printf("my output :       %d\nexpected output : %d", ft_atoi("   +001abc"), atoi("   +001abc"));
	refresh(p1, p2,p1_bis, p2_bis, av[1], av[2], "ft_memalloc");
	printf("my output :       %s\nexpected output : %s", strcpy(ft_memalloc(strlen(*p1)), *p1), strdup(*p1));
	refresh(p1, p2,p1_bis, p2_bis, av[1], av[2], "ft_memdel");
	ft_memdel((void **)p1);
	printf("my output :       %s\nexpected output : %s", *p1, "(null)");
	refresh(p1, p2,p1_bis, p2_bis, av[1], av[2], "ft_memalloc");
	printf("my output :       %s\nexpected output : %s", strcpy(ft_memalloc(strlen(*p1)), *p1), strdup(*p1));
	return (0);
}
