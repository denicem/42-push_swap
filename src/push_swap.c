/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 19:55:43 by dmontema          #+#    #+#             */
/*   Updated: 2021/12/05 19:22:40 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

#include <stdio.h>

void	exit_prg(t_node **stack)
{
	clear_list(stack);
	write (2, "Error.\n", 7);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		init_size;
	int		divider;

	if (argc > 1)
	{
		init_size = init_stack(&stack_a, argc, argv);
		set_index(&stack_a);
		if (is_sorted(&stack_a))
			return (0);
		if (init_size == 4)
			sort_three(&stack_a);
		if (init_size <= 15)
			sort_small(&stack_a, &stack_b);
		else
		{
			if (init_size <= 100)
				divider = 5;
			else 
				divider = 10;
			sort_big(&stack_a, &stack_b, init_size, divider);
		}
		clear_list(&stack_a);
	}
	return (0);
}
