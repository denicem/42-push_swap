/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_back.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:39:28 by dmontema          #+#    #+#             */
/*   Updated: 2021/11/22 19:21:55 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	add_back(t_node **list, t_node *new)
{
	t_node *last;

	if (new == NULL)
		return ;
	if (*list == NULL)
	{
		*list = new;
		return ;
	}
	if ((*list)->next == NULL)
	{
		(*list)->next = new;
		return ;
	}
	last = get_last(*list);
	last->next = new;
}