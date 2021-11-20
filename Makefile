# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/19 00:52:39 by dmontema          #+#    #+#              #
#    Updated: 2021/11/20 17:42:23 by dmontema         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = lib/libft.a lib/libftprintf.a push_swap.c

CFLAGS	=	-Wall -Wextra -Werror

all:	$(NAME)

$(NAME): push_swap.c
	gcc $(CFLAGS) $(SRCS) -o $(NAME)

fclean:	
	rm $(NAME)