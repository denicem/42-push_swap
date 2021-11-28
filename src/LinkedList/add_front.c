/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_front.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:39:10 by dmontema          #+#    #+#             */
/*   Updated: 2021/11/28 17:37:41 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	add_front(t_node **list, t_node *new)
{
	t_node *tmp;

	if (new == NULL)
		return ;
	if (*list == NULL)
	{
		*list = new;
		return ;
	}
	tmp = *list;
	*list = new;
	new->next = tmp;
}