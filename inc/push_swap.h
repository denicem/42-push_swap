/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 00:50:03 by dmontema          #+#    #+#             */
/*   Updated: 2021/12/05 19:20:11 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PUSH_SWAP_H
# define	PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>

#include "libft.h"
#include "ft_printf.h"

typedef struct	s_node
{
	int	val;
	struct s_node *next;
}				t_node;

t_node	*new_node(int nbr);
void	add_front(t_node **list, t_node *new);
int		add_back(t_node **list, t_node *new);
int		get_listsize(t_node *list);
t_node	*get_last(t_node *list);
void	print_list(t_node **list);
void	clear_list(t_node **list);

void	swap(t_node **list, char *str);
void	rotate(t_node **list, char *str);
void	rev_rotate(t_node **list, char *str);
void	push(t_node **list_a, t_node **list_b, char *str);

int		init_stack(t_node **stack, int argc, char **argv);
int		ft_atoi_ps(const char *str, t_node **stack);
void	set_index(t_node **stack);
void	exit_prg(t_node **stack);

int		is_sorted(t_node **stack);
void	sort_three(t_node **stack);
void	sort_small(t_node **stack_a, t_node **stack_b);
void	sort_big(t_node **stack_a, t_node **stack_b, int init_size, int divider);

#endif
