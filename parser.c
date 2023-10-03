/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoktas <mtoktas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 20:37:53 by mtoktas           #+#    #+#             */
/*   Updated: 2023/10/03 15:59:32 by mtoktas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_len(const char *str)
{
	int		len;

	len = 0;
	if (str[len] == '-' || str[len] == '+')
		len++;
	while (str[len] >= '0' && str[len] <= '9')
		len++;
	return (len);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		neg;
	long	res;

	i = 0;
	neg = 1;
	res = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - 48) * neg;
		if (res > 2147483647 || res < -2147483648)
			return (-1);
		i++;
	}
	return (res);
}

int ft_norm(char *str, int i, int res)
{
	while (str[i])
	{
		while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
			i++;
		if (str[i] == '-' || str[i] == '+')
		{
			if (str[i + 1] <= '9' && str[i + 1] >= '0')
				i++;
			else
				return (-1);
		}
		if (str[i] <= '9' && str[i] >= '0')
		{
			res += 1;
			i++;
		}
		else if (str[i] == 0)
			break ;
		else
			return (-1);
		while (str[i] <= '9' && str[i] >= '0')
			i++;
	}
	return (res);
}
int	ft_num_of_args_helper(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	return (ft_norm(str, i, res));
}

int	ft_num_of_args(int ac, char **av)
{
	int	res;
	int	i;
	int	tmp_ac;

	res = 0;
	i = 1;
	tmp_ac = ac;
	while (av[i])
	{
		if (ft_num_of_args_helper(av[i]) != -1)
		{
			res += ft_num_of_args_helper(av[i]);
			i++;
		}
		else
			return (-1);
	}
	return (res);
}

int main(int ac, char **av)
{
	int i;
	t_stack *stack;
	stack = malloc(sizeof(t_stack));
	init_stack(stack, ac, av);
	i = stack->top_a;
	while (i >= 0)
	{
		printf("A first : %d\n", stack->stack_a[i]);
		i--;
	}
	int *array = get_stack(stack->stack_a, stack->stack_len);
	sort_array(array, stack->stack_len);
	indexing_stack(stack->stack_a, stack->stack_len);
	radix(stack);
	i = stack->top_a;
	while (i >= 0)
	{
		printf("A last: %d\n", stack->stack_a[i]);
		i--;
	}
}
