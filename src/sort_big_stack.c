/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 23:43:06 by dmontema          #+#    #+#             */
/*   Updated: 2021/12/06 22:27:13 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	push_elem_back(t_node **stack_a, t_node **stack_b)
{
	int		index;
	t_node	*list;

	list = *stack_b;
	index = get_listsize(*stack_b) - 1;
	while (*stack_b)
	{
		if (!is_reverse(stack_b, index))
			while ((*stack_b)->val != index)
				rotate(stack_b, "rb");
		else
			while ((*stack_b)->val != index)
				rev_rotate(stack_b, "rrb");
		push(stack_b, stack_a, "pa");
		index--;
	}
}

static int	is_reverse_two_vals(t_node **stack, int range)
{
	int		first;
	int		last;
	int		pos;
	t_node	*list;

	list = *stack;
	pos = 0;
	while (list->val >= range)
	{
		pos++;
		list = list->next;
	}
	first = pos;
	while (list)
	{
		if (list->val < range)
			last = pos;
		list = list->next;
		pos++;
	}
	if ((get_listsize(*stack) - last) < first)
		return (1);
	return (0);
}

static int	get_chunk_size(int init_size)
{
	int	div;
	int	res;

	div = 5;
	if (init_size > 100)
		div += init_size / 100;
	res = init_size / div;
	return (res);
}

void	sort_big(t_node **stack_a, t_node **stack_b, int init_size)
{
	int	part;
	int	range;
	int	count;

	part = get_chunk_size(init_size);
	range = part;
	count = 0;
	while (range <= init_size)
	{
		while (count < range)
		{
			if (!is_reverse_two_vals(stack_a, range))
				while ((*stack_a)->val >= range)
					rotate(stack_a, "ra");
			else
				while ((*stack_a)->val >= range)
					rev_rotate(stack_a, "rra");
			push(stack_a, stack_b, "pb");
			count++;
		}
		range += part;
	}
	while (*stack_a)
		push(stack_a, stack_b, "pb");
	push_elem_back(stack_a, stack_b);
}
