/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 19:55:43 by dmontema          #+#    #+#             */
/*   Updated: 2021/12/06 20:38:32 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

#include <stdio.h>

void	error_exit_prg(t_node **stack)
{
	clear_list(stack);
	write (2, "Error\n", 6);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		init_size;

	if (argc > 1)
	{
		init_size = init_stack(&stack_a, argc, argv);
		set_index(&stack_a);
		if (is_sorted(&stack_a))
			exit(0);
		if (init_size == 2)
		{
			swap(&stack_a, "sa");
			exit(0);
		}
		if (init_size == 3)
			sort_three(&stack_a);
		if (init_size <= 15)
			sort_small(&stack_a, &stack_b);
		else
			sort_big(&stack_a, &stack_b, init_size);
		clear_list(&stack_a);
		clear_list(&stack_b);
	}
	exit(0);
}
