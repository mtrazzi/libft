/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrazzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 12:45:39 by mtrazzi           #+#    #+#             */
/*   Updated: 2017/08/12 13:13:05 by mtrazzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*temp;
	int		i;

	i = 0;
	if (!s)
		exit(EXIT_FAILURE);
	if ((temp = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))) == NULL)
		exit(EXIT_FAILURE);
	while (s[i])
	{
		temp[i] = s[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}
