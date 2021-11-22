/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:39:50 by dmontema          #+#    #+#             */
/*   Updated: 2021/11/22 17:57:09 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void print_list(t_node **list) //TODO: after pushing last element from b to a and want to print out b, it segfaults.
{
	t_node *tmp;

	tmp = *list;
	while (list != NULL)
	{
		ft_printf("%d", tmp->content);
		if (tmp->next == NULL)
			break ;
		ft_printf(" - ");
		tmp = tmp->next;
	}
	ft_printf("\n");
}