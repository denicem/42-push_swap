/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:39:41 by dmontema          #+#    #+#             */
/*   Updated: 2021/11/27 19:12:26 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	clear_list(t_node **list)
{
	t_node *tmp = *list;

	if (*list == NULL)
		return ;
	while (tmp)
	{
		free(tmp);
		tmp = tmp->next;
	}
	list = NULL;
}