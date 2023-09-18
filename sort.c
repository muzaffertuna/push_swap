/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoktas <mtoktas@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:18:20 by mtoktas           #+#    #+#             */
/*   Updated: 2023/09/18 15:59:18 by mtoktas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_array(int *stack, int s_len)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (stack[i] < (s_len - 1))
	{
		j = i + 1;
		while (stack[j] < (s_len - 1))
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

	array = malloc(sizeof(int) * s_len);
	i = 0;
	while (i < (s_len - 1))
	{
		array[i] = stack[i];
		i++;
	}
	array[i] = '\0';
	sort_array(array, s_len);
	return (array);
}

void	indexing_stack(int *stack, int *array, int s_len)
{
	int	i;
	int	j;

	i = 0;
	while (i < s_len)
	{
		j = 0;
		while (j < s_len)
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
}
