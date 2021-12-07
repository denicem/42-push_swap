# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/19 00:52:39 by dmontema          #+#    #+#              #
#    Updated: 2021/12/07 17:53:44 by dmontema         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	push_swap

SRC_DIR	:=	./src

PS_SRC	:=	$(SRC_DIR)/push_swap.c

SRCS	:=	$(SRC_DIR)/push_swap_operations.c \
			$(SRC_DIR)/init_stack.c \
			$(SRC_DIR)/ft_atoi_ps.c \
			$(SRC_DIR)/index_stack.c \
			$(SRC_DIR)/sort_big_stack.c \
			$(SRC_DIR)/sort_small_stack.c

SRCS	+=	$(SRC_DIR)/LinkedList/new_node.c		\
			$(SRC_DIR)/LinkedList/add_front.c		\
			$(SRC_DIR)/LinkedList/add_back.c		\
			$(SRC_DIR)/LinkedList/get_listsize.c	\
			$(SRC_DIR)/LinkedList/get_last.c		\
			$(SRC_DIR)/LinkedList/print_list.c		\
			$(SRC_DIR)/LinkedList/clear_list.c

OBJS	:=	$(SRCS:.c=.o)

LIBS	:=	lib/libft.a lib/libftprintf.a

CC		:=	gcc
CFLAGS	=	-Wall -Wextra -Werror

all:	$(NAME)

$(NAME):	$(PS_SRC) $(OBJS) $(LIBS)
	$(CC) $(CFLAGS) $(LIBS) $(PS_SRC) $(OBJS) -o $(NAME)

.c.o:	
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(LIBS):	
	@make -C $(SRC_DIR)/Libft
	@make -C $(SRC_DIR)/ft_printf

clean:
	rm -f $(OBJS)
	@make -C $(SRC_DIR)/Libft clean
	@make -C $(SRC_DIR)/ft_printf clean

fclean:	clean
	rm -f $(NAME)
	@make -C $(SRC_DIR)/Libft fclean
	@make -C $(SRC_DIR)/ft_printf fclean

re:	fclean all
