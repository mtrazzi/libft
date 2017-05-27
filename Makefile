# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtrazzi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/27 16:05:15 by mtrazzi           #+#    #+#              #
#    Updated: 2017/05/27 17:18:49 by mtrazzi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = *.c

all: $(NAME)

$(NAME):
	gcc -c -Wall -Wextra -Werror $(SRC) -Ilibft.h
	ar rc $(NAME) *.o
	
clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
