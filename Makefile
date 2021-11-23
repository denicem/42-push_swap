# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/19 00:52:39 by dmontema          #+#    #+#              #
#    Updated: 2021/11/23 19:08:29 by dmontema         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap

SRC_DIR := src

PS_SRC = $(SRC_DIR)/push_swap.c

SRCS := $(SRC_DIR)/push_swap_operations.c

SRCS += 	$(SRC_DIR)/LinkedList/new_node.c		\
			$(SRC_DIR)/LinkedList/add_front.c		\
			$(SRC_DIR)/LinkedList/add_back.c		\
			$(SRC_DIR)/LinkedList/get_listsize.c	\
			$(SRC_DIR)/LinkedList/get_last.c		\
			$(SRC_DIR)/LinkedList/print_list.c		\
			$(SRC_DIR)/LinkedList/clear_list.c

LIBS = lib/libft.a lib/libftprintf.a

CFLAGS	=	-Wall -Wextra -Werror

all:	$(NAME)

$(NAME): $(PS_SRC) $(SRCS) 
	gcc $(CFLAGS) $(LIBS) $(PS_SRC) $(SRCS) -o $(NAME)

fclean:	
	rm $(NAME)

re: fclean
	all

visual:
	gcc $(CFLAGS) $(LIBS) $(SRCS) visualization.c -o visualizer

clean-vis:	
	rm visualizer