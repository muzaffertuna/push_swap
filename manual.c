/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoktas <mtoktas@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:03:49 by mtoktas           #+#    #+#             */
/*   Updated: 2023/10/07 02:13:19 by mtoktas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_index(t_stack *stack)
{
	int i;
	int max_index;

	i = 1;
	max_index = 0;
	while (i <= stack->top_a)
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
	while (i <= stack->top_a)
	{
		if (stack->stack_a[i] < stack->stack_a[min_index])
			min_index = i;
		i++;
	}
	return(min_index);
}

void two_argument_sort(t_stack *stack)
{
	if (stack->stack_a[stack->top_a] > stack->stack_a[(stack->top_a) - 1])
	{
		swap_a(stack);
	}
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

void	manual_pa(t_stack *stack)
{
	if (stack->stack_b)
	{
		stack->stack_a[++stack->top_a] = stack->stack_b[stack->top_b];
		stack->stack_b[stack->top_b] = 0;
		stack->top_b--;
	}
}
void manual_sort(t_stack *stack, int ac)
{
	if(ac == 2)
	{
		two_argument_sort(stack);
		exit(1);
	}
	else if(ac == 3)
	{
		three_argument_sort(stack);
		exit(1);
	}
	else if(ac == 4)
	{
		four_argument_sort(stack);
		exit(1);
	}
	else if(ac == 5)
	{
		five_argument_sort(stack);
		exit(1);
	}
}