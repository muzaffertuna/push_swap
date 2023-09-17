/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoktas <mtoktas@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 20:55:47 by mtoktas           #+#    #+#             */
/*   Updated: 2023/09/17 18:32:30 by mtoktas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_ordered(int *stack, int s_len)
{
	int	i;

	i = 0;
	while ((i + 1) < s_len)
	{
		if (stack[i + 1] < stack[i])
			return (0);
		i++;
	}
	return (1);
}

int	is_duplicate(int *stack, int s_len)
{
	int	i;
	int	j;

	i = 0;
	while (i < s_len)
	{
		j = i + 1;
		while (j < s_len)
		{
			if (stack[i] == stack[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_args(int *stack, int s_len)
{
	if (is_duplicate(stack, s_len))
	{
		write(2, "'ERROR!' \n Given list has duplicate numbers.", 44);
		return (-1);
	}
	if (is_ordered(stack, s_len))
	{
		write(2, "'ERROR!' \n Given list ordered already.", 38);
		return (-1);
	}
	return (1);
}
