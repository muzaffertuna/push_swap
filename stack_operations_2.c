/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoktas <mtoktas@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:10:35 by mtoktas           #+#    #+#             */
/*   Updated: 2023/10/07 12:36:10 by mtoktas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack *stack)
{
	int	tmp;
	int	i;

	i = (stack->top_a - 1);
	tmp = stack->stack_a[stack->top_a];
	while (i >= 0)
	{
		stack->stack_a[i + 1] = stack->stack_a[i];
		i--;
	}
	stack->stack_a[0] = tmp;
	write(1, "ra\n", 3);
}

void	rotate_b(t_stack *stack)
{
	int	tmp;
	int	i;

	i = (stack->top_b - 1);
	tmp = stack->stack_b[stack->top_b];
	while (i >= 0)
	{
		stack->stack_b[i + 1] = stack->stack_b[i];
		i--;
	}
	stack->stack_b[0] = tmp;
	write(1, "rb\n", 3);
}

void	rr(t_stack *stack)
{
	rotate_a(stack);
	rotate_b(stack);
	write(1, "rr\n", 3);
}

void	reverse_rotate_a(t_stack *stack)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = stack->stack_a[0];
	while (i < stack->top_a)
	{
		stack->stack_a[i] = stack->stack_a[i + 1];
		i++;
	}
	stack->stack_a[stack->top_a] = tmp;
	write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_stack *stack)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = stack->stack_b[0];
	while (i < stack->top_b)
	{
		stack->stack_b[i] = stack->stack_b[i + 1];
		i++;
	}
	stack->stack_b[stack->top_b] = tmp;
	write(1, "rrb\n", 4);
}
