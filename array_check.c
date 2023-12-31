/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoktas <mtoktas@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 20:55:47 by mtoktas           #+#    #+#             */
/*   Updated: 2023/10/07 13:09:50 by mtoktas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_ordered(int *stack, int s_len)
{
	int	i;

	i = 0;
	while ((i + 1) < s_len)
	{
		if (stack[i + 1] > stack[i])
			return (1);
		i++;
	}
	return (-1);
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
			{
				write(2, "Error\n", 6);
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	free_stack_exit(t_stack *stack)
{
	free(stack->stack_a);
	free(stack->stack_b);
	free(stack);
	exit(0);
}

int	check_args(int *stack, int s_len)
{
	if (is_duplicate(stack, s_len) == -1 || is_ordered(stack, s_len) == -1)
		return (-1);
	return (1);
}

void	rrr(t_stack *stack)
{
	reverse_rotate_a(stack);
	reverse_rotate_b(stack);
	write(1, "rrr\n", 4);
}
