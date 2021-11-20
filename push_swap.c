/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 19:55:43 by dmontema          #+#    #+#             */
/*   Updated: 2021/11/21 00:19:20 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

#include <stdio.h>

void swap(t_list **stack_a, t_list **stack_b)
{
	t_list *first;
	t_list *sec;

	if (stack_a != NULL && stack_b == NULL)
	{
		first = *stack_a;
		sec = (*stack_a)->next;

		first->next = sec->next;
		sec->next = first;
		*stack_a = sec;

		ft_printf("sa\n");

	}
	if (stack_a == NULL && stack_b != NULL)
	{
		first = *stack_b;
		sec = (*stack_b)->next;

		first->next = sec->next;
		sec->next = first;
		*stack_b = sec;

		ft_printf("sb\n");

	}
	if (stack_a != NULL && stack_b != NULL)
	{
		first = *stack_b;
		sec = (*stack_b)->next;

		first->next = sec->next;
		sec->next = first;
		*stack_b = sec;

		first = *stack_b;
		sec = (*stack_b)->next;

		first->next = sec->next;
		sec->next = first;
		*stack_b = sec;

		ft_printf("ss\n");
	}
}

void print_lst(void *content)
{
	ft_printf("%d\n", *((int *) content));
}

int main(int argc, char const *argv[])
{
	if (argc > 1)
	{
		t_list *list;
		int i;
		int nbr[argc - 1];

		i = 1;
		while (i < argc)
		{
			nbr[i] = ft_atoi(argv[i]);
			ft_lstadd_back(&list, ft_lstnew((&nbr[i])));
			i++;
		}
		ft_lstiter(list, print_lst);
	}
	else 
		ft_printf("F*CK\n");
	return (0);
}
