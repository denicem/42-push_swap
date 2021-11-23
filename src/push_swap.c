/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 19:55:43 by dmontema          #+#    #+#             */
/*   Updated: 2021/11/22 22:28:27 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

#include <stdio.h>

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
		push(&a.head, &b.head, "pb");
		push(&a.head, &b.head, "pb");
		push(&a.head, &b.head, "pb");
		push(&a.head, &b.head, "pb");
		push(&a.head, &b.head, "pb");
		push(&b.head, &a.head, "pa");
		swap(&a.head, "sa");
		push(&a.head, &b.head, "pb");
		push(&a.head, &b.head, "pb");
		push(&a.head, &b.head, "pb");
		print_list(&b.head);
		rev_rotate(&a.head, "rra");
		rev_rotate(&b.head, "rrb");
		rev_rotate(&b.head, "rrb");
		print_list(&a.head);
		print_list(&b.head);
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
