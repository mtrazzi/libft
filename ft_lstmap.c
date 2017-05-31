/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrazzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 16:59:43 by mtrazzi           #+#    #+#             */
/*   Updated: 2017/05/31 17:25:03 by mtrazzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*rec;

	if (lst == NULL)
		return (NULL);
	if ((tmp = ft_lstnew(f(lst)->content, f(lst)->content_size)) == NULL)
		return (NULL);
	if (f(lst)->next == NULL)
		return (tmp);
	if ((rec = ft_lstmap(f(lst)->next, f)) == NULL)
		return (NULL);
	tmp->next = rec;
	return (tmp);
}
