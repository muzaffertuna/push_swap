/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoktas <mtoktas@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 11:18:30 by mtoktas           #+#    #+#             */
/*   Updated: 2023/10/07 11:20:36 by mtoktas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_argument_sort(t_stack *stack)
{
	if (stack->stack_a[stack->top_a] > stack->stack_a[(stack->top_a) - 1])
	{
		swap_a(stack);
	}
}

void	three_argument_sort(t_stack *stack)
{
	int	max_index;

	max_index = find_max_index(stack);
	if (max_index == 1)
		reverse_rotate_a(stack);
	else if (max_index == 2)
		rotate_a(stack);
	two_argument_sort(stack);
}

void	four_argument_sort(t_stack *stack)
{
	int	min_index;

	min_index = find_min_index(stack);
	if (min_index == 2)
		rotate_a(stack);
	else if (min_index == 1)
	{
		rotate_a(stack);
		rotate_a(stack);
	}
	else if (min_index == 0)
		reverse_rotate_a(stack);
	push_b(stack);
	three_argument_sort(stack);
	push_a(stack);
}

void	five_argument_sort(t_stack *stack)
{
	int	min_index;

	min_index = find_min_index(stack);
	if (min_index == 3)
	{
		rotate_a(stack);
	}
	else if (min_index == 2)
	{
		rotate_a(stack);
		rotate_a(stack);
	}
	else if (min_index == 1)
	{
		reverse_rotate_a(stack);
		reverse_rotate_a(stack);
	}
	else if (min_index == 0)
	{
		reverse_rotate_a(stack);
	}
	push_b(stack);
	four_argument_sort(stack);
	push_a(stack);
}
