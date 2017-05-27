/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrazzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 18:06:42 by mtrazzi           #+#    #+#             */
/*   Updated: 2017/05/27 20:09:22 by mtrazzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_sizeof(int n)
{
	if (n <= 9)
		return (1);
	return (1 + ft_sizeof(n / 10));
}

static char		*ft_itoa_aux(int n, char *s, size_t len)
{
	while (--len >= 0)
	{
		s[len] = n % 10;
		n /= 10;
		len--;
	}
	return (s);
}

char			*ft_itoa(int n)
{
	char *tmp;

	if (n == -2147483648)
	{
		if ((tmp = ft_strnew(sizeof(char) * 11)) == NULL)
			return (NULL);
		return (ft_strncpy(tmp, "-2147483648", 11));
	}
	if (n < 0)
	{
		if ((tmp = ft_strnew(ft_sizeof(-n) + 1)) == NULL)
			return (NULL);
		tmp[0] = '-';
		return (ft_itoa_aux(-n, tmp + 1, ft_sizeof(-n)));
	}
	if ((tmp = ft_strnew(sizeof(char) * ft_sizeof(n))) == NULL)
		return (NULL);
	return (ft_itoa_aux(n, tmp, ft_sizeof(n)));
}
