/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrazzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 18:23:08 by mtrazzi           #+#    #+#             */
/*   Updated: 2017/05/25 18:48:35 by mtrazzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned int	i;
	char			*answer;

	i = 0;
	answer = (char *)str;
	while (i < n)
	{
		answer[i] = (char)c;
		i++;
	}
	return (answer);
}
