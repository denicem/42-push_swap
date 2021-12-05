/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_ps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 17:42:04 by dmontema          #+#    #+#             */
/*   Updated: 2021/12/05 17:56:29 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	ft_isWhitespace(char c)
{
	if (c == ' ' || (c >= '\b' && c <= '\r'))
		return (1);
	return (0);
}

static int	ft_calcRes(const char *str, int sign, t_node **stack)
{
	long	res;

	res = 0;
	while (ft_isdigit(*str))
	{
		if (sign == -1 && res >= INT_MAX)
			exit_prg(stack);
		else if (res >= INT_MAX)
			exit_prg(stack);
		res = res * 10 + (ft_isdigit(*str) - '0');
		str++;
	}
	return (res);
}

int	ft_atoi_ps(const char *str, t_node **stack)
{
	int	res;
	int	sign;

	if (!ft_strlen(str))
		return (0);
	res = 0;
	sign = 1;
	while (ft_isWhitespace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	res = ft_calcRes(str, sign, stack);
	return (res * sign);
}