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
#include <stdio.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*elt;
	t_list	*rec;

	if (lst == NULL)
		return (NULL);
	elt = (t_list *)malloc(sizeof(t_list *));
	if (!elt)
		return (NULL);
	printf("lst->content : %s\n", lst->content);
	printf("(f(lst))->content : %s\n", (*f)(lst)->content);
	elt->content = (f(lst))->content;
	elt->content_size = (f(lst))->content_size;
	rec = ft_lstmap(lst->next, f);
	elt->next = rec;
	return (elt);
}

t_list		*uf_testmap(t_list *elem)
{
	t_list	*new;
	char	*content;
	size_t	i;

	content = ft_strdup((char *)(elem->content));
	i = 0;
	while (i < ft_strlen(content))
	{
		content[i] += 1;
		++i;
	}
	new = ft_lstnew((void const *) content, 5);
	free(content);
	return (new);
}

int	main(void)
{
    t_list			*lst_initial;
    t_list			*lst;
    char			*content;
    t_list			*(*f)(t_list *);

	content = "toto";
	lst_initial = ft_lstnew((void const *) content, 5 * sizeof(void const));
	content = "tata";
	lst_initial->next = ft_lstnew((void const *) content, 5 * sizeof(void const));
	content = "tutu";
	lst_initial->next->next = ft_lstnew((void const *) content, 5 * sizeof(void const));
	printf("111lst_initial->content : %s\nlst_initial->next->content : %s\nlst_initial->next->next->content : %s\n", lst_initial->content, lst_initial->next->content, lst_initial->next->next->content);
	f = &uf_testmap;
	lst = ft_lstmap(lst_initial, f);
	printf("222lst_initial->content : %s\nlst_initial->next->content : %s\nlst_initial->next->next->content : %s\n", lst_initial->content, lst_initial->next->content, lst_initial->next->next->content);
	printf("lst_initial->content_size : %zu\nlst_initial->next->content_size : %zu\nlst_initial->next->next->content_size : %zu\n", lst_initial->content_size, lst_initial->next->content_size, lst_initial->next->next->content_size);
	if (!strcmp((const char *) lst->content, (const char *) lst_initial->content))
        printf("ERROR1\n");
    	if (strcmp((const char *) lst->content, "upup"))
	printf("ERROR1_BIS\n");
	if (!strcmp((const char *) lst->next->content, (const char *) lst_initial->next->content))  
        printf("ERROR2\n");
	if(strcmp((const char *) lst->next->content, "ubub"))
    	printf("ERROR2_BIS\n");
	if (!strcmp((const char *) lst->next->next->content, (const char *) lst_initial->next->next->content)) 
	printf("ERROR3\n");
	if(strcmp((const char *) lst->next->next->content, "uvuv"))
	printf("ERROR3_BIS\n");
	
	printf("333lst_initial->content : %s\nlst_initial->next->content : %s\nlst_initial->next->next->content : %s\n", lst_initial->content, lst_initial->next->content, lst_initial->next->next->content);
	printf("lst->content : %s\nlst->next->content : %s\nlst->next->next->content : %s\n", lst->content, lst->next->content, lst->next->next->content);
    return (1);
}
