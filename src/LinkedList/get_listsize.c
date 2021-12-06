/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_listsize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:38:56 by dmontema          #+#    #+#             */
/*   Updated: 2021/12/06 15:36:47 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	get_listsize(t_node *list)
{
	int	res;

	res = 0;
	while (list)
	{
		res++;
		list = list->next;
	}
	return (res);
}
