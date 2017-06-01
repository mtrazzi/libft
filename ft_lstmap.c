/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrazzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 16:59:43 by mtrazzi           #+#    #+#             */
/*   Updated: 2017/06/01 19:49:37 by mtrazzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*elt;
	t_list	*rec;

	if (lst == NULL)
		return (NULL);
	elt = (t_list *)malloc(sizeof(t_list *));
	if (!elt)
		return (NULL);
	elt->content = (f(lst))->content;
	elt->content_size = (f(lst))->content_size;
	rec = ft_lstmap(lst->next, f);
	elt->next = rec;
	return (elt);
}
