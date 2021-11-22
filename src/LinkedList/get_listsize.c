/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_listsize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:38:56 by dmontema          #+#    #+#             */
/*   Updated: 2021/11/22 17:56:56 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	get_listsize(t_node *list)
{
	int res;

	if (list == NULL)
		return (0);
	res = 1;
	while (list->next != NULL)
	{
		res++;
		list = list->next;
	}
	return (res);
}