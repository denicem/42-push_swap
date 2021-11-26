/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 23:43:06 by dmontema          #+#    #+#             */
/*   Updated: 2021/11/26 23:43:41 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int is_sorted(t_node **stack)
{
	t_node	*list;

	list = *stack;
	while (list->next)
	{
		if (list->content >= list->next->content)
			return (0);
		list = list->next;
	}
	return (1);
}

void sort_three(t_node **stack)
{
	int a;
	int b;
	int c;

	a = (*stack)->content;
	b = (*stack)->next->content;
	c = (*stack)->next->next->content;
	if (a < b && a < c && b > c) // 1 3 2
	{
		swap(stack, "sa");
		rotate(stack, "ra");
	}
	if (a > b && b < c && a < c) // 2 1 3
		swap(stack, "sa");
	if (a < b && a > c && b > c) // 2 3 1
		rev_rotate(stack, "rra");
	if (a > b && a > c && b < c) // 3 1 2
		rotate(stack, "ra");
	if (a > b && a > c && b > c) // 3 2 1
	{
		swap(stack, "sa");
		rev_rotate(stack, "rra");
	}
}

int	is_reverse(t_node **stack, int min)
{
	int pos;
	t_node *list;

	pos = 0;
	list = *stack;
	while (list)
	{
		if (list->content == min)
			break ;
		pos++;
		list = list->next;
	}
	if (pos > get_listsize(*stack) / 2)
		return (1);
	return (0);
}

void sort_100(t_node **stack_a, t_node **stack_b)
{
	int index;
	t_node *list;

	list = *stack_a;
	index = 0;
	while (get_listsize(*stack_a) > 3)
	{
		while ((*stack_a)->content != index)
		{
			if (!is_reverse(stack_a, index))
				rotate(stack_a, "ra");
			else
				rev_rotate(stack_a, "rra");
		}
		push(stack_a, stack_b, "pb");
		index++;
	}
	sort_three(stack_a);
	while (get_listsize(*stack_b))
		push(stack_b, stack_a, "pa");
}
