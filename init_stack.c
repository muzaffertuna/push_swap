/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoktas <mtoktas@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:27:03 by mtoktas           #+#    #+#             */
/*   Updated: 2023/09/17 18:27:28 by mtoktas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack_helper(int *array, char **av)
{
	int	i;
	int	j;
	int	arr_i;

	i = 1;
	arr_i = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			while ((av[i][j] >= 9 && av[i][j] <= 13) || av[i][j] == 32)
				j++;
			if (av[i][j] == '-' || av[i][j] == '+'
				|| (av[i][j] <= '9' && av[i][j] >= '0'))
			{
				array[arr_i] = ft_atoi(&av[i][j]);
				j += ft_len(&av[i][j]);
				arr_i++;
			}
		}
		i++;
	}
	array[arr_i] = '\0';
}

void	init_stack(t_stack *stack, int ac, char **av)
{
	if (!ac || !av || !av[1])
	{
		write(2, "'ERROR!' \n Incorrect argument input.", 36);
		exit(1);
	}
	stack->stack_len = (ft_num_of_args(ac, av) + 1);
	stack->stack_a = malloc(sizeof(int) * (stack->stack_len));
	stack->stack_b = malloc(sizeof(int) * (stack->stack_len));
	init_stack_helper(stack->stack_a, av);
	if (check_args(stack->stack_a, stack->stack_len - 1) == -1)
		exit(1);
	stack->top_a = (stack->stack_len - 2);
	stack->top_b = -1;
}
