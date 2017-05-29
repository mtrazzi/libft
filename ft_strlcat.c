/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrazzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 12:45:42 by mtrazzi           #+#    #+#             */
/*   Updated: 2017/05/29 13:10:23 by mtrazzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (dest[i] && i < n)
		i++;
	j = 0;
	while (src[j] && j < n - i - 1)
	{
		dest[i + j] = src[i];
		j++;
	}
	dest[i + j] = '\0';
	if (i == n)
		return (n + ft_strlen(src));
	return (ft_strlen(dest) + ft_strlen(src));
}
