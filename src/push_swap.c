/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 19:55:43 by dmontema          #+#    #+#             */
/*   Updated: 2021/11/26 23:43:03 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

#include <stdio.h>

void setIndex(t_node **stack)
{
	int index;
	int size;
	t_node *list;
	t_node *min_val;

	index = 0;
	size = get_listsize(*stack);
	while (index < size)
	{
		list = *stack;
		while (list)
		{
			if (list->content >= index)
			{
				min_val = list;
				break;
			}
			list = list->next;
		}
		while (list)
		{
			if (list->content < min_val->content && list->content > index)
				min_val = list;
			list = list->next;
		}
		min_val->content = index;
		index++;
	}
}

int main (int argc, char **argv)
{
	t_node *stack_a;
	t_node *stack_b;
	int i;

	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			add_back(&stack_a, new_node(ft_atoi(argv[i])));
			i++;
		}

		print_list(&stack_a);
		setIndex(&stack_a);
		if (argc == 4)
			sort_three(&stack_a);
		sort_100(&stack_a, &stack_b);
		print_list(&stack_a);
		// print_list(&b.head);
	}
	return (0);
}
