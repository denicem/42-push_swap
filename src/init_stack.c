/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 21:20:59 by dmontema          #+#    #+#             */
/*   Updated: 2021/11/29 21:21:40 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int init_stack(t_node **stack, int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (!add_back(stack, new_node(ft_atoi(argv[i]))))
			return (0);
		i++;
	}
	return (1);
}

void setIndex(t_node **stack)
{
	int index;
	int count;
	int *arr_stack;
	t_node *list;
	t_node *curr_elem;

	arr_stack = malloc(sizeof(int) * get_listsize(*stack));
	if (arr_stack == NULL)
		return ;
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
		arr_stack[count] = index;
		curr_elem = curr_elem->next;
		count++;
	}
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