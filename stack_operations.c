/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoktas <mtoktas@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:55:14 by mtoktas           #+#    #+#             */
/*   Updated: 2023/09/17 18:12:36 by mtoktas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *stack)
{
	int	tmp;

	if (stack->top_a > 1)
	{
		push_b(stack);
		tmp = stack->stack_a[stack->top_a];
		stack->stack_a[stack->top_a--] = 0;
		push_a(stack);
		stack->stack_a[++stack->top_a] = tmp;
		write(1, "sa\n", 3);
	}
}

void	swap_b(t_stack *stack)
{
	int	tmp;

	if (stack->top_b > 1)
	{
		push_a(stack);
		tmp = stack->stack_b[stack->top_b];
		stack->stack_b[stack->top_b--] = 0;
		push_b(stack);
		stack->stack_b[++stack->top_b] = tmp;
		write(1, "sb\n", 3);
	}
}

void	ss(t_stack *stack)
{
	swap_a(stack);
	swap_b(stack);
	write(1, "ss\n", 3);
}

void	push_a(t_stack *stack)
{
	if (stack->stack_b && stack->stack_b[0])
	{
		stack->stack_a[++stack->top_a] = stack->stack_b[stack->top_b];
		stack->stack_b[stack->top_b] = 0;
		stack->top_b--;
		write(1, "pa\n", 3);
	}
	else
	{
		exit(1);
	}
}

void	push_b(t_stack *stack)
{
	if (stack->stack_a && stack->stack_a[0])
	{
		stack->stack_b[++stack->top_b] = stack->stack_a[stack->top_a];
		stack->stack_a[stack->top_a] = 0;
		stack->top_a--;
		write(1, "pb\n", 3);
	}
}
