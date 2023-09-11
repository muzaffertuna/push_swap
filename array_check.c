/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoktas <mtoktas@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 20:55:47 by mtoktas           #+#    #+#             */
/*   Updated: 2023/09/11 21:30:09 by mtoktas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_array_ordered(int *array)
{
    int i;
    
    i = 0;
    while (array[i + 1])
	{
		if(array[i + 1] < array[i])
			return(0);
		i++;
	}
	write(1, "Given list is ordered already.\n", 31);
	return(1);
}

int control_duplicates(int *array)
{
	int i;
	int j;
	
	i = 0;
	while (array[i])
	{
		j = i + 1;
		while (array[j])
		{
			if (array[i] == array[j])
			{
				write(2, "'ERROR!' Duplicate number", 25);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
