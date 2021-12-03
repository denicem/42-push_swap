/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:39:41 by dmontema          #+#    #+#             */
/*   Updated: 2021/12/03 18:53:53 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	clear_list(t_node **list)
{
	t_node	*tmp;

	tmp = *list;
	if (*list == NULL)
		return ;
	while (tmp)
	{
		free(tmp);
		tmp = tmp->next;
	}
	list = NULL;
}
