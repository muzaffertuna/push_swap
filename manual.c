/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoktas <mtoktas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:03:49 by mtoktas           #+#    #+#             */
/*   Updated: 2023/10/04 18:11:10 by mtoktas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_index(t_stack *stack)
{
	int i;
	int max_index;

	i = 1;
	max_index = 0;
	while (i < stack->top_a)
	{
		if (stack->stack_a[i] > stack->stack_a[max_index])
			max_index = i;
		i++;
	}
	return(max_index);
}

int	find_min_index(t_stack *stack)
{
	int i;
	int min_index;

	i = 1;
	min_index = 0;
	while (i < stack->top_a)
	{
		if (stack->stack_a[i] < stack->stack_a[min_index])
			min_index = i;
		i++;
	}
	return(min_index);
}

void two_argument_sort(t_stack *stack)
{
	if (stack->stack_a[stack->top_a] > stack->stack_a[stack->top_a -1])
		rotate_a(stack);
}

void three_argument_sort(t_stack *stack)
{
	int max_index;

	max_index = find_max_index(stack);
	if (max_index == 1)
		reverse_rotate_a(stack);
	else if(max_index == 2)
		rotate_a(stack);
	two_argument_sort(stack);
}

void four_argument_sort(t_stack *stack)
{
	int min_index;

	min_index = find_min_index(stack);
	if (min_index == 2)
		rotate_a(stack);
	else if (min_index == 1)
	{
		rotate_a(stack);
		rotate_a(stack);
	}
	else if(min_index == 0)
		reverse_rotate_a(stack);
	push_b(stack);
	three_argument_sort(stack);
	push_a(stack);
}

void five_argument_sort(t_stack *stack)
{
	int min_index;
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
	}else if (min_index == 0)
	{
		reverse_rotate_a(stack);
	}
	push_b(stack);
	four_argument_sort(stack);
	push_a(stack);
}
