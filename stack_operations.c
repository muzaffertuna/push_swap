/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoktas <mtoktas@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:55:14 by mtoktas           #+#    #+#             */
/*   Updated: 2023/09/12 17:03:11 by mtoktas          ###   ########.fr       */
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
	}
}

void	ss(t_stack *stack)
{
	swap_a(stack);
	swap_b(stack);
}

void	push_a(t_stack *stack)
{
	if (stack->stack_b && stack->stack_b[0])
	{
		stack->stack_a[stack->top_a++] = stack->stack_b[stack->top_b];
		stack->stack_b[stack->top_b] = 0;
		stack->top_b--;
	}
}

void	push_b(t_stack *stack)
{
	if (stack->stack_a && stack->stack_a[0])
	{
		stack->stack_b[stack->top_b++] = stack->stack_a[stack->top_a];
		stack->stack_a[stack->top_a] = 0;
		stack->top_b--;
	}
}

void rotate_a(t_stack *stack)
{
	int tmp;
	int i;

	i = 1;
	tmp = stack->stack_a[0];
	while((i + 1) <= stack->top_a)
	{
		stack->stack_a[i + 1] = stack->stack_a[i];
		i++;
	}
	stack->stack_a[stack->top_a] = tmp;
}

void rotate_b(t_stack *stack)
{
	int tmp;
	int i;

	i = 1;
	tmp = stack->stack_b[0];
	while((i + 1) <= stack->top_b)
	{
		stack->stack_b[i + 1] = stack->stack_b[i];
		i++;
	}
	stack->stack_b[stack->top_b] = tmp;
}

void rr(t_stack *stack)
{
	rotate_a(stack);
	rotate_b(stack);
}

void reverse_rotate_a(t_stack *stack)
{
	int tmp;
	int i;
	 
	i = stack->top_a;
	tmp = stack->stack_a[stack->top_a];
	while((i - 1) >= 0)
	{
		stack->stack_a[i - 1] = stack->stack_a[i];
		i--;
	}
	stack->stack_a[0] = tmp;
}

void reverse_rotate_b(t_stack *stack)
{
	int tmp;
	int i;
	 
	i = stack->top_b;
	tmp = stack->stack_b[stack->top_b];
	while((i - 1) >= 0)
	{
		stack->stack_b[i - 1] = stack->stack_b[i];
		i--;
	}
	stack->stack_b[0] = tmp;
}

void rrr(t_stack *stack)
{
	reverse_rotate_a(stack);
	reverse_rotate_b(stack);
}
