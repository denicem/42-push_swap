# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/19 00:52:39 by dmontema          #+#    #+#              #
#    Updated: 2021/11/20 19:49:17 by dmontema         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = push_swap.c

LIBS = lib/libft.a lib/libftprintf.a

CFLAGS	=	-Wall -Wextra -Werror

all:	$(NAME)

$(NAME): $(SRCS)
	gcc $(CFLAGS) $(LIBS) $(SRCS) -o $(NAME)

fclean:	
	rm $(NAME)