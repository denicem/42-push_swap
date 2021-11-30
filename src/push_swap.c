/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 19:55:43 by dmontema          #+#    #+#             */
/*   Updated: 2021/11/30 02:10:35 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

#include <stdio.h>

int main (int argc, char **argv)
{
	t_node *stack_a;
	t_node *stack_b;

	if (argc > 1)
	{
		if (!init_stack(&stack_a, argc, argv))
		{
			if (stack_a != NULL)
				clear_list(&stack_a);
			ft_printf("Error.\n");
			return (0);
		}
		print_list(&stack_a);
		set_index(&stack_a);
		print_list(&stack_a);
		if (argc == 4)
			sort_three(&stack_a);
		if (argc <= 16)
			sort_small(&stack_a, &stack_b);
		else
			sort_big(&stack_a, &stack_b);
		print_list(&stack_a);
		print_list(&stack_b);

		clear_list(&stack_a);
		// system("leaks push_swap");
	}
	return (0);
}
