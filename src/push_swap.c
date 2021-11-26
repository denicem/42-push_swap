/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 19:55:43 by dmontema          #+#    #+#             */
/*   Updated: 2021/11/26 23:34:00 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

#include <stdio.h>

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
