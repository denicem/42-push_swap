# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/19 00:52:39 by dmontema          #+#    #+#              #
#    Updated: 2021/11/19 01:14:38 by dmontema         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = push_swap.c ft_atoi.c ft_isdigit.c ft_strlen.c

CFLAGS	=	-Wall -Wextra -Werror

all:	$(NAME)

$(NAME):
	gcc $(CFLAGS) $(SRCS) -o $(NAME)

fclean:	
	rm $(NAME)