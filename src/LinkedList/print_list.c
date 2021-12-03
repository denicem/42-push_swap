/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:39:50 by dmontema          #+#    #+#             */
/*   Updated: 2021/12/03 18:55:53 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	print_list(t_node **list)
{
	t_node	*tmp;

	if (*list)
	{
		ft_printf("\033[0;35m");
		tmp = *list;
		while (list != NULL)
		{
			ft_printf("%d", tmp->val);
			if (tmp->next == NULL)
				break ;
			ft_printf(" - ");
			tmp = tmp->next;
		}
		ft_printf("\n");
		ft_printf("\033[0m");
	}
}
