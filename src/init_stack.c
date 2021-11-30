/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 21:20:59 by dmontema          #+#    #+#             */
/*   Updated: 2021/11/30 02:00:19 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	free_split_string(char **str)
{
	int i;

	i = 0;
	while (str[i])
		free(str[i++]);
	return (0);
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
			return (free_split_string(numbers));
		numbers++;
	}
	free_split_string(numbers);
	return (1);
}

static int has_letter(char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (ft_isalpha(*str++))
			return (1);
	}
	return (0);
}

static int def_input(char *str)
{
	if (!str || has_letter(str))
		return (0);
	while (*str)
	{
		if (*str == ' ')
			return (2);
		str++;
	}
	return (1);
}

int init_stack(t_node **stack, int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (def_input(argv[i]) == 1)
		{
			if (!add_back(stack, new_node(ft_atoi(argv[i]))))
				return (0);
		}
		else if (def_input(argv[i]) == 2)
		{
			if (!add_strings(stack, argv[i]))
				return (0);
		}
		else
			return (0);
		i++;
	}
	return (1);
}
