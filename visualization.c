/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 23:28:10 by dmontema          #+#    #+#             */
/*   Updated: 2021/11/23 04:02:38 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"
#include <stdio.h>

void visualize_stacks(t_linked_list *a, t_linked_list *b, char *last_used_op,int operator_used)
{
	t_node *stack_a = a->head;
	t_node *stack_b = b->head;

	printf("\n");
	printf("%21s", "<< PUSH_SWAP >>");
	printf("\n\n");
	printf("\t A\t B\n");
	printf("---------------------------\n");
	while ((stack_a != NULL) || (stack_b != NULL))
	{
		printf("\t");
		if (stack_a != NULL)
			printf("%3d\t", stack_a->content);
		else
			printf("-|-\t");
		if (stack_b != NULL)
			printf("%3d\n", stack_b->content);
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

void exec_operation(t_linked_list *a, t_linked_list *b, char *op)
{
	if (!strcmp(op, "sa"))
		swap(&a->head, "");
	if (!strcmp(op, "sb"))
		swap(&b->head, "");
	if (!strcmp(op, "ra"))
		rotate(&a->head, a->tail, "");
	if (!strcmp(op, "rb"))
		rotate(&b->head, b->tail, "");
	if (!strcmp(op, "rra"))
		rev_rotate(&a->head, "");
	if (!strcmp(op, "rrb"))
		rev_rotate(&b->head, "");
	if (!strcmp(op, "pa"))
		push(&b->head, &a->head, "");
	if (!strcmp(op, "pb"))
		push(&a->head, &b->head, "");
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

int main (int argc, char **argv)
{
	if (argc > 1)
	{
		int i = 1;
		t_linked_list a;
		t_linked_list b;
		int operator_used = 0;
		char *last_used_op = "-";

		while (i < argc)
			add_back(&a.head, new_node(ft_atoi(argv[i++])));
		a.tail = get_last(a.head);
		b.head = NULL;
		b.tail = NULL;
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