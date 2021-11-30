/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 21:20:59 by dmontema          #+#    #+#             */
/*   Updated: 2021/11/30 01:19:17 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	free_split_string(char **str)
{
	int i;

	i = 0;
	while (str[i])
		free(str[i++]);
	str = 0;
}

static int add_strings(t_node **stack, char *str)
{
	char **numbers;

	if (!str)
		return (0);
	numbers = ft_split(str, ' ');
	if (!numbers)
	{
		return (0);
	}
	while (*numbers)
	{
		if (!add_back(stack, new_node(ft_atoi(*numbers))))
		{
			free_split_string(numbers);
			return (0);
		}
		numbers++;
	}
	free_split_string(numbers);
	return (1);
}

static int has_space(char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == ' ')
			return (1);
		str++;
	}
	return (0);
}

int init_stack(t_node **stack, int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (has_space(argv[i]))
			{
				if (!add_strings(stack, argv[i]))
					return (0);
			}
		else
			if (!add_back(stack, new_node(ft_atoi(argv[i]))))
				return (0);
		i++;
	}
	return (1);
}

void setIndex(t_node **stack)
{
	int index;
	int count;
	int *arr_stack;
	t_node *list;
	t_node *curr_elem;

	arr_stack = malloc(sizeof(int) * get_listsize(*stack));
	if (arr_stack == NULL)
		return ;
	count = 0;
	curr_elem = *stack;
	while (curr_elem)
	{
		index = 0;
		list = *stack;
		while (list)
		{
			if (curr_elem->val > list->val)
				index++;
			list = list->next;
		}
		arr_stack[count] = index;
		curr_elem = curr_elem->next;
		count++;
	}
	list = *stack;
	count = 0;
	while (list)
	{
		list->val = arr_stack[count];
		list = list->next;
		count++;
	}
	free(arr_stack);
}