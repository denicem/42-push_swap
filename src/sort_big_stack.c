/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 23:43:06 by dmontema          #+#    #+#             */
/*   Updated: 2021/12/03 19:00:23 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	is_reverse_3(t_node **stack, int max)
{
	int		pos;
	t_node	*list;

	pos = 0;
	list = *stack;
	while (list)
	{
		if (list->val == max)
			break ;
		pos++;
		list = list->next;
	}
	if (pos > get_listsize(*stack) / 2)
		return (1);
	return (0);
}

static int	is_reverse_2(t_node **stack, int range)
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

static void	sort_big_back(t_node **stack_a, t_node **stack_b)
{
	int		index;
	t_node	*list;

	list = *stack_b;
	index = get_listsize(*stack_b) - 1;
	while (get_listsize(*stack_b))
	{
		if (!is_reverse_3(stack_b, index))
			while ((*stack_b)->val != index)
				rotate(stack_b, "rb");
		else
			while ((*stack_b)->val != index)
				rev_rotate(stack_b, "rrb");
		push(stack_b, stack_a, "pa");
		index--;
	}
}

void	sort_big(t_node **stack_a, t_node **stack_b, int init_size)
{
	int	part;
	int	range;
	int	count;

	count = 0;
	part = init_size / 10;
	range = part;
	while (range <= init_size && *stack_a)
	{
		while (count < range)
		{
			if (!is_reverse_2(stack_a, range))
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
	sort_big_back(stack_a, stack_b);
}
