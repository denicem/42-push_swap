/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 23:11:26 by dmontema          #+#    #+#             */
/*   Updated: 2021/12/06 20:16:31 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	is_sorted(t_node **stack)
{
	t_node	*list;

	list = *stack;
	while (list->next)
	{
		if (list->val >= list->next->val)
			return (0);
		list = list->next;
	}
	return (1);
}

void	sort_three(t_node **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->val;
	b = (*stack)->next->val;
	c = (*stack)->next->next->val;
	if (a < b && a < c && b > c)
	{
		swap(stack, "sa");
		rotate(stack, "ra");
	}
	if (a > b && a < c && b < c)
		swap(stack, "sa");
	if (a < b && a > c && b > c)
		rev_rotate(stack, "rra");
	if (a > b && a > c && b < c)
		rotate(stack, "ra");
	if (a > b && a > c && b > c)
	{
		swap(stack, "sa");
		rev_rotate(stack, "rra");
	}
}

int	is_reverse(t_node **stack, int val)
{
	int		pos;
	t_node	*list;

	pos = 0;
	list = *stack;
	while (list)
	{
		if (list->val == val)
			break ;
		pos++;
		list = list->next;
	}
	if (pos > get_listsize(*stack) / 2)
		return (1);
	return (0);
}

void	sort_small(t_node **stack_a, t_node **stack_b)
{
	int		index;
	t_node	*list;

	list = *stack_a;
	index = 0;
	while (get_listsize(*stack_a) > 3)
	{
		if (!is_reverse(stack_a, index))
			while ((*stack_a)->val != index)
				rotate(stack_a, "ra");
		else
			while ((*stack_a)->val != index)
				rev_rotate(stack_a, "rra");
		push(stack_a, stack_b, "pb");
		if (is_sorted(stack_a))
			break ;
		index++;
	}
	if (get_listsize(*stack_a) <= 3)
		sort_three(stack_a);
	while (*stack_b)
		push(stack_b, stack_a, "pa");
}
