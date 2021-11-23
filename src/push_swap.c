/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 19:55:43 by dmontema          #+#    #+#             */
/*   Updated: 2021/11/23 23:11:51 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

#include <stdio.h>

void sort_three(t_linked_list *stack)
{
	int a;
	int b;
	int c;

	a = stack->head->content;
	b = stack->head->next->content;
	c = stack->head->next->next->content;

	if (a < b && a < c && b > c) // 1 3 2
	{
		swap(&(stack->head), "sa");
		rotate(&(stack->head), "ra");
	}
	if (a > b && b < c && a < c) // 2 1 3
		swap(&(stack->head), "sa");
	if (a < b && a > c && b > c) // 2 3 1
		rev_rotate(&stack->head, "rra");
	if (a > b && a > c && b < c) // 3 1 2
		rotate(&stack->head, "ra");
	if (a > b && a > c && b > c) // 3 2 1
	{
		swap(&stack->head, "sa");
		rev_rotate(&stack->head, "rra");
	}
}

void sort_five(t_linked_list *stack_a, t_linked_list *stack_b)
{
	// push smallest number
	if (stack_a->head->content == 0) // [0]
		push(&stack_a->head, &stack_b->head, "pb");
	else if (stack_a->head->next->content == 0) // [1]
	{
		rotate(&stack_a->head, "ra");
		push(&stack_a->head, &stack_b->head, "pb");
	}
	else if (stack_a->head->next->next->content == 0) // [2]
	{
		rotate(&stack_a->head, "ra");
		rotate(&stack_a->head, "ra");
		push(&stack_a->head, &stack_b->head, "pb");
	}
	else if (stack_a->head->next->next->next->content == 0) // [3]
	{
		rev_rotate(&stack_a->head, "rra");
		rev_rotate(&stack_a->head, "rra");
		push(&stack_a->head, &stack_b->head, "pb");
	}
	else // [4]
	{
		rev_rotate(&stack_a->head, "rra");
		push(&stack_a->head, &stack_b->head, "pb");
	}

	// push second smalles number to b
	if (stack_a->head->content == 1) // [0]
		push(&stack_a->head, &stack_b->head, "pb");
	else if (stack_a->head->next->content == 1) // [1]
	{
		rotate(&stack_a->head, "ra");
		push(&stack_a->head, &stack_b->head, "pb");
	}
	else if (stack_a->head->next->next->content == 1) // [2]
	{
		rotate(&stack_a->head, "ra");
		rotate(&stack_a->head, "ra");
		push(&stack_a->head, &stack_b->head, "pb");
	}
	else // [3]
	{
		rev_rotate(&stack_a->head, "rra");
		push(&stack_a->head, &stack_b->head, "pb");
	}

	sort_three(stack_a);
	push(&stack_b->head, &stack_a->head,  "pa");
	push(&stack_b->head, &stack_a->head, "pa");
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

int main (int argc, char **argv)
{
	t_linked_list a;
	t_linked_list b;
	int i;

	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			add_back(&a.head, new_node(ft_atoi(argv[i])));
			i++;
		}
		a.tail = get_last(a.head);
		b.head = NULL;
		b.tail = NULL;

		print_list(&a.head);
		setIndex(&a.head);
		if (argc == 4)
			sort_three(&a);
		else if (argc == 6)
			sort_five(&a, &b);
		print_list(&a.head);

	}

	// t_node *n1 = new_node(123);
	// t_node *n2 = new_node(42);
	// t_node *n3 = new_node(4);
	// t_node *n4 = new_node(56);
	// t_node *n5 = new_node(21);
	// t_node *head = n1;

	// add_back(&head, n2);
	// add_back(&head, n3);
	// add_back(&head, n4);
	// add_back(&head, n5);
	// t_node *tail = get_last(head);

	// t_node *list_b;
	// add_front(&head, new_node(890));

	//rev_rotate(&head, "rra");
	// rotate(&head, tail, "ra");
	// swap(&head, "sa");
	// push(&head, &list_b, "pb");
	// push(&list_b, &head, "pa");

	// print_list(&head);
	// print_list(&list_b);
	return (0);
}
