/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrazzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 06:39:41 by mtrazzi           #+#    #+#             */
/*   Updated: 2017/08/14 09:51:58 by mtrazzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# include "libft/includes/libft.h"
# define BUFF_SIZE 1023

typedef struct			s_line_lst
{
	int					fd;
	char				*line;
	struct s_line_lst	*next;	
}						t_line_lst;
int						get_next_line(int fd, char **line);

#endif
