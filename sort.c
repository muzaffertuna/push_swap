/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoktas <mtoktas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:18:20 by mtoktas           #+#    #+#             */
/*   Updated: 2023/10/04 18:11:03 by mtoktas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_array(int *stack, int s_len)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < (s_len))
	{
		j = i + 1;
		while (j < (s_len))
		{
			if (stack[i] > stack[j])
			{
				tmp = stack[i];
				stack[i] = stack[j];
				stack[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	*get_stack(int *stack, int s_len)
{
	int	*array;
	int	i;

	array = malloc(sizeof(int) * (s_len + 1));
	i = 0;
	while (i < (s_len + 1))
	{
		array[i] = stack[i];
		i++;
	}
	array[i] = '\0';
	sort_array(array, s_len);
	return (array);
}

void	indexing_stack(int *stack, int s_len)
{
	int	i;
	int	j;
	int *array;

	i = 0;
	array = get_stack(stack, s_len);
	while (i < s_len)
	{
		printf("get stack : %d\n", array[i]);
		i++;
	}
	i = 0;
	while (i < (s_len + 1))
	{
		j = 0;
		while (j < (s_len + 1))
		{
			if (array[j] == stack[i])
			{
				stack[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
	free(array);
}

int get_max_digit(int *stack, int size)
{
	int max_num;
	int max_digit;
	int i;

	max_num = stack[0];
	max_digit = 0;
	i = 0;
	while (i < size)
	{
		if(stack[i] > max_num)
			max_num = stack[i];
		i++;
	}
	while (max_num > 0)
	{
		max_num >>= 1;
		max_digit++;
	}
	return (max_digit);
}

int isEmpty(int top)
{
	return (top == -1);
}

void radix(t_stack *stack)
{
	int i;
	int j;
	int max_digit;

	i = 0;
	max_digit = get_max_digit(stack->stack_a, stack->stack_len);
	while (i < max_digit)
	{
		j = 0;
		while (j < stack->stack_len)
		{
			if(stack->stack_a[j] >> i & 1)
				rotate_a(stack);
			else
				push_b(stack);
			j++;
		}
		while (!isEmpty(stack->top_b))
			push_a(stack);
		i++;
	}
}
