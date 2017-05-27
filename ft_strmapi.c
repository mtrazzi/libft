/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrazzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 16:00:47 by mtrazzi           #+#    #+#             */
/*   Updated: 2017/05/27 16:01:34 by mtrazzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	size_t	i;

	i = 0;
	if ((res = ft_strdup(s)) == NULL)
		return (NULL);
	while (i < ft_strlen(s))
	{
		res[i] = f(i, res[i]);
		i++;
	}
	return (res);
}
