/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:37:59 by dmontema          #+#    #+#             */
/*   Updated: 2021/12/03 18:55:03 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

t_node	*new_node(int nbr)
{
	t_node	*res;

	res = (t_node *) malloc(sizeof(t_node *));
	res->val = nbr;
	res->next = NULL;
	return (res);
}
