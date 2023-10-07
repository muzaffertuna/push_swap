/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoktas <mtoktas@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:03:49 by mtoktas           #+#    #+#             */
/*   Updated: 2023/10/07 12:36:06 by mtoktas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_index(t_stack *stack)
{
	int	i;
	int	max_index;

	i = 1;
	max_index = 0;
	while (i <= stack->top_a)
	{
		if (stack->stack_a[i] > stack->stack_a[max_index])
			max_index = i;
		i++;
	}
	return (max_index);
}

int	find_min_index(t_stack *stack)
{
	int	i;
	int	min_index;

	i = 1;
	min_index = 0;
	while (i <= stack->top_a)
	{
		if (stack->stack_a[i] < stack->stack_a[min_index])
			min_index = i;
		i++;
	}
	return (min_index);
}

void	manual_pa(t_stack *stack)
{
	if (stack->stack_b)
	{
		stack->stack_a[++stack->top_a] = stack->stack_b[stack->top_b];
		stack->stack_b[stack->top_b] = 0;
		stack->top_b--;
	}
}

void	manual_sort(t_stack *stack, int ac)
{
	if (ac == 2)
		two_argument_sort(stack);
	else if (ac == 3)
		three_argument_sort(stack);
	else if (ac == 4)
		four_argument_sort(stack);
	else if (ac == 5)
		five_argument_sort(stack);
	free_stack_exit(stack);
}
