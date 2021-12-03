/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:19:18 by dmontema          #+#    #+#             */
/*   Updated: 2021/12/03 18:50:58 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	swap(t_node **list, char *str)
{
	t_node	*tmp;

	if (*list && (*list)->next)
	{
		tmp = *list;
		*list = (*list)->next;
		tmp->next = (*list)->next;
		(*list)->next = tmp;
		if (ft_strlen(str))
			ft_printf("%s\n", str);
	}
}

void	rotate(t_node **list, char *str)
{
	t_node	*tmp;
	t_node	*tail;

	tail = get_last(*list);
	if (*list && (*list)->next)
	{
		tmp = *list;
		*list = (*list)->next;
		tail->next = tmp;
		tmp->next = NULL;
		if (ft_strlen(str))
			ft_printf("%s\n", str);
	}
}

void	rev_rotate(t_node **list, char *str)
{
	t_node	*ptr1;
	t_node	*ptr2;

	if (*list)
	{
		ptr1 = *list;
		while (ptr1->next != NULL)
		{
			ptr2 = ptr1->next;
			if (ptr2->next == NULL)
			{
				ptr2->next = *list;
				ptr1->next = NULL;
				*list = ptr2;
				break ;
			}
			ptr1 = ptr1->next;
		}
		if (ft_strlen(str))
			ft_printf("%s\n", str);
	}
}

void	push(t_node **list_a, t_node **list_b, char *str)
{
	t_node	*tmp;

	if (*list_a)
	{
		tmp = *list_a;
		*list_a = tmp->next;
		tmp->next = *list_b;
		*list_b = tmp;
		if (ft_strlen(str))
			ft_printf("%s\n", str);
	}
}
