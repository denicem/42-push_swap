/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_back.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:39:28 by dmontema          #+#    #+#             */
/*   Updated: 2021/11/28 17:55:01 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	add_back(t_node **list, t_node *new)
{
	t_node *last;

	if (new == NULL)
		return (0);
	if (*list == NULL)
	{
		*list = new;
		return (1);
	}
	last = *list;
	while (last->next)
	{
		if (new->val == last->val)
			return (0);
		last = last->next;
	}
	last->next = new;
	return (1);
}
