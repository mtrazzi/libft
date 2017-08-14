/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrazzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 08:35:44 by mtrazzi           #+#    #+#             */
/*   Updated: 2017/08/14 09:44:26 by mtrazzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_line_lst	*ft_add_line_to_end(t_line_lst **line_lst, \
										int fd, char *line)
{
	t_line_lst	*to_add;
	t_line_lst	*begin_lst;

	begin_lst = *line_lst;
	to_add = (t_line_lst *)ft_memalloc(sizeof(t_line_lst));
	to_add->line = line;
	to_add->fd = fd;
	to_add->next = NULL;
	if (!(*line_lst))
	{
		*line_lst = to_add;
		return (to_add);
	}
	while ((*line_lst)->next)
		*line_lst = (*line_lst)->next;
	(*line_lst)->next = to_add;
	*line_lst = begin_lst;
	return (begin_lst);
}

static void			ft_get_buffer(int fd, t_line_lst **line_lst)
{
	static char *result = NULL;
	char		buff[BUFF_SIZE + 1];
	char		*tmp;
	int			ret;

	while (!ft_strchr(result, '\n') && (ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		tmp = result;
		result = ft_strjoin(result, buff);
		free(tmp);
	}
	if (ft_strchr(result, '\n'))
	{
		*(ft_strchr(result, '\n')) = '\0';
		ft_add_line_to_end(line_lst, fd, ft_strdup(result));
		tmp = result;
		result = ft_strdup(ft_strchr(result, '\0') + 1);
		free(tmp);
		return ;
	}
	ft_add_line_to_end(line_lst, fd, ft_strdup(result));
	free(result);
}

static void			ft_get_line(int fd, t_line_lst **line_lst, char **line)
{
	t_line_lst	*next;
	t_line_lst	*begin_lst;

	begin_lst = *line_lst;
	if (!((*line_lst)->next))
	{
		*line = (*line_lst)->line;
		free((*line_lst));
		*line_lst = NULL;
		return ;
	}
	next = (*line_lst)->next;
	while (next->fd != fd)
	{
		*line_lst = next;
		next = next->next;
	}
	*line = next->line;
	(*line_lst)->next = next->next;
	free(next->line);
	free(next);
	*line_lst = begin_lst;
}

int					get_next_line(int fd, char **line)
{
	static t_line_lst	*line_lst = NULL;

	if (!line_lst)
		ft_get_buffer(fd, &line_lst);
	ft_get_line(fd, &line_lst, line);
	return (*(*line) != 0);
}
