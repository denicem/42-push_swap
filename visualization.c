/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 23:28:10 by dmontema          #+#    #+#             */
/*   Updated: 2021/12/05 19:32:59 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"
#include <stdio.h>

void visualize_stacks(t_node **a, t_node **b, char *last_used_op,int operator_used)
{
	t_node *stack_a = *a;
	t_node *stack_b = *b;

	printf("\n");
	printf("%21s", "<< PUSH_SWAP >>");
	printf("\n\n");
	printf("\t A\t B\n");
	printf("---------------------------\n");
	while ((stack_a != NULL) || (stack_b != NULL))
	{
		printf("\t");
		if (stack_a != NULL)
			printf("%3d\t", stack_a->val);
		else
			printf("-|-\t");
		if (stack_b != NULL)
			printf("%3d\n", stack_b->val);
		else
			printf("-|-\n");

		if (stack_a != NULL)
			stack_a = stack_a->next; 
		if (stack_b != NULL)
			stack_b = stack_b->next; 
	}
	printf("---------------------------\n");
	printf("LAST OPERATOR USED:\t%3s\n", last_used_op);
	printf("INSTRUCTIONS COUNT:\t%3d\n", operator_used);
	printf("---------------------------\n\n");
}

void exec_operation(t_node **a, t_node **b, char *op)
{
	if (!strcmp(op, "sa"))
		swap(a, "");
	if (!strcmp(op, "sb"))
		swap(b, "");
	if (!strcmp(op, "ra"))
		rotate(a, "");
	if (!strcmp(op, "rb"))
		rotate(b, "");
	if (!strcmp(op, "rra"))
		rev_rotate(a, "");
	if (!strcmp(op, "rrb"))
		rev_rotate(b, "");
	if (!strcmp(op, "pa"))
		push(b, a, "");
	if (!strcmp(op, "pb"))
		push(a, b, "");
}

int is_operator(char *str)
{
	if (!strcmp(str, "sa") || !strcmp(str, "sb") ||
		!strcmp(str, "ra") || !strcmp(str, "rb") ||
		!strcmp(str, "rra") || !strcmp(str, "rrb") ||
		!strcmp(str, "pa") || !strcmp(str, "pb"))
		return (1);
	else
		return (0);
}

void	exit_prg(t_node **stack)
{
	clear_list(stack);
	write (2, "Error.\n", 7);
	exit(0);
}

int main (int argc, char **argv)
{
	if (argc > 1)
	{
		int i = 1;
		t_node *a;
		t_node *b;
		int operator_used = 0;
		char *last_used_op = "-";

		while (i < argc)
			add_back(&a, new_node(ft_atoi_ps(argv[i++], &a)));
		set_index(&a);
		visualize_stacks(&a, &b, last_used_op, operator_used);

		while (1)
		{
			char *in = calloc(1,1);

			printf("OPERATOR (Type \"end\" or 'q' to exit program.): ");
			scanf("%s", in);
			// fgets(in, 10, stdin);
			if (is_operator(in))
			{
				operator_used++;
				last_used_op = in;
				exec_operation(&a, &b, in);
				visualize_stacks(&a, &b, last_used_op, operator_used);
				printf("OPERATOR FOUND. ANOTHER ONE.\n\n");
			}
			else if (!strcmp(in, "end") || !strcmp(in, "q"))
			{
				free(in);
				break ;
			}
			else if (!strcmp(in, "mis"))
			{
				visualize_stacks(&a, &b, last_used_op, --operator_used);
			}
			else if (!strcmp(in, "vis"))
				visualize_stacks(&a, &b, last_used_op, operator_used);
			else
				printf("\nOperator not found. Please try again.\n\n");
		}
		printf("\nTOTAL OPERATORS USED: %d\n", operator_used);
		printf("Thank you for using the push_swap visualization. Goodbye. See you next time!\n");
	}
	else 
		printf("No input. See you next time.\n");
	return (0);
}