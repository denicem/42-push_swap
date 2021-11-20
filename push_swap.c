/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 19:55:43 by dmontema          #+#    #+#             */
/*   Updated: 2021/11/20 17:44:34 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

#include <stdio.h>

void print_lst(void *content)
{
	ft_printf("%d\n", (int) content);
}

int main(int argc, char const *argv[])
{
	if (argc > 1)
	{
		printf("%s\n", argv[0]);
		t_list *list;

		int *i = ft_atoi(argv[1]);
		ft_lstadd_front(&list, ft_lstnew((i)));
		// argc -= 1;
		// ft_printf("%+d\n", i);
	}
	return (0);
}
