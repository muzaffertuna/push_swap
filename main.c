/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoktas <mtoktas@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 23:05:49 by mtoktas           #+#    #+#             */
/*   Updated: 2023/10/07 12:31:22 by mtoktas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	init_stack(stack, ac, av);
	indexing_stack(stack->stack_a, stack->stack_len);
	if (stack->stack_len <= 5)
		manual_sort(stack, stack->stack_len);
	else
		radix(stack);
}
