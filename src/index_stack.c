/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 01:59:30 by dmontema          #+#    #+#             */
/*   Updated: 2021/12/03 18:56:24 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	set_arr(t_node **stack, int **arr_stack)
{
	int		index;
	int		count;
	t_node	*curr_elem;
	t_node	*list;

	count = 0;
	curr_elem = *stack;
	while (curr_elem)
	{
		index = 0;
		list = *stack;
		while (list)
		{
			if (curr_elem->val > list->val)
				index++;
			list = list->next;
		}
		(*arr_stack)[count] = index;
		curr_elem = curr_elem->next;
		count++;
	}
}

void	set_index(t_node **stack)
{
	int		count;
	int		*arr_stack;
	t_node	*list;

	arr_stack = malloc(sizeof(int) * get_listsize(*stack));
	if (arr_stack == NULL)
		return ;
	set_arr(stack, &arr_stack);
	list = *stack;
	count = 0;
	while (list)
	{
		list->val = arr_stack[count];
		list = list->next;
		count++;
	}
	free(arr_stack);
}
