/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrazzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 16:54:46 by mtrazzi           #+#    #+#             */
/*   Updated: 2017/05/27 18:04:10 by mtrazzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*dst;
	size_t	i;
	size_t	c;

	i = 0;
	c = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (!(s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
	{
		i++;
		c++;
	}
	if ((dst = ft_strnew(c)) == NULL)
		return (NULL);
	return (ft_strncpy(dst, s + i - c, c));
}
