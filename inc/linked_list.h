/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 23:04:31 by dmontema          #+#    #+#             */
/*   Updated: 2021/11/21 23:04:31 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct	s_node
{
	int	content;
	struct s_node *next;
}	t_node;

t_node	*new_node(int nbr);
int		get_listsize(t_node *list);
t_node	*get_last(t_node *list);
void	add_front(t_node **list, t_node *new);
void	add_back(t_node **list, t_node *new);
void	clear_list(t_node **list);
void	print_list(t_node **list);
