/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 00:50:03 by dmontema          #+#    #+#             */
/*   Updated: 2021/11/22 18:48:38 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PUSH_SWAP_H
# define	PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>

#include "libft.h"
#include "ft_printf.h"

// OWN INT LINKED LIST
// TODO: create linked list initializer for the input (argv)
// TODO: handle error input (letters and duplicates)

typedef struct	s_node
{
	int	content;
	struct s_node *next;
}	t_node;

t_node	*new_node(int nbr);
void	add_front(t_node **list, t_node *new);
void	add_back(t_node **list, t_node *new);
int		get_listsize(t_node *list);
t_node	*get_last(t_node *list);
void	print_list(t_node **list);
void	clear_list(t_node **list);
 
void	swap(t_node **list, char *str);
void	rotate(t_node **list, t_node *tail, char *str);
void	rev_rotate(t_node **list, char *str);
void	push(t_node **list_a, t_node **list_b, char *str);

#endif