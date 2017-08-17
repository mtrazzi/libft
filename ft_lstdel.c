/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrazzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 16:20:07 by mtrazzi           #+#    #+#             */
/*   Updated: 2017/08/17 10:09:34 by mtrazzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *))
{
	t_list	*tmp;

	if (!(*alst))
		return ;
	tmp = (*alst)->next;
	ft_lstdelone(alst, del);
	ft_lstdel(&tmp, del);
}
