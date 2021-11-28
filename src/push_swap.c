/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 19:55:43 by dmontema          #+#    #+#             */
/*   Updated: 2021/11/28 17:27:25 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

#include <stdio.h>

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

int init_stack(t_node **stack, int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		add_back(stack, new_node(ft_atoi(argv[i])));
		i++;
	}
	return (1);
}

int main (int argc, char **argv)
{
	t_node *stack_a;
	t_node *stack_b;

	if (argc > 1)
	{
		if (!init_stack(&stack_a, argc, argv))
		{
			ft_printf("Error.\n");
			return (0);
		}
		print_list(&stack_a);
		setIndex(&stack_a);
		print_list(&stack_a);
		if (argc == 4)
			sort_three(&stack_a);
		sort_100(&stack_a, &stack_b);
		// sort_big_stack(&stack_a, &stack_b);
		print_list(&stack_a);
		print_list(&stack_b);

		clear_list(&stack_a);
		// clear_list(&stack_b);
		// ft_printf("%p\n", stack_a);
		// ft_printf("%p\n", stack_b);
		// system("leaks push_swap");
	}
	return (0);
}
