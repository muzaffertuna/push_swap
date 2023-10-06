/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoktas <mtoktas@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 23:05:49 by mtoktas           #+#    #+#             */
/*   Updated: 2023/10/07 02:12:36 by mtoktas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	int i;
	t_stack *stack;
	stack = malloc(sizeof(t_stack));
	init_stack(stack, ac, av);
	// i = stack->top_a;
	// while (i >= 0)
	// {
	// 	printf("A first : %d\n", stack->stack_a[i]);
	// 	i--;
	// }
	int *array = get_stack(stack->stack_a, stack->stack_len);
	sort_array(array, stack->stack_len);
	indexing_stack(stack->stack_a, stack->stack_len);
	manual_sort(stack, stack->stack_len);
	radix(stack);
}