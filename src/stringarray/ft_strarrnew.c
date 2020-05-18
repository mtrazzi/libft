/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringarray/ft_strarrnew.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duquesne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2006/06/06 06:06:06 by duquesne          #+#    #+#             */
/*   Updated: 2006/06/06 06:06:06 by duquesne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_memory.h"
#include "libft_stringarray.h"



char	**ft_strarrnew(t_u32 len)
{
	char	**result;
	t_u32	i;

	if (!(result = (char**)ft_memalloc(sizeof(char*) * (len + 1))))
		return (NULL);
	i = 0;
	while (i <= len)
	{
		result[i] = NULL;
		++i;
	}
	return (result);
}
