/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoktas <mtoktas@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 20:37:53 by mtoktas           #+#    #+#             */
/*   Updated: 2023/09/11 18:37:20 by mtoktas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int ft_num_of_args(char *str)
{
    int i;
    int res;
    
    i = 0;
    res = 0;
		while(str[i])
		{
			while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
				i++;
			if (str[i] == '-' || str[i] == '+')
				i++;
			if(str[i] <= '9' && str[i] >= '0')
			{
				res += 1;
				i++;
			}
			else
			{
				write(2,"Invalid argument\n", 17);
				return (-1);
			}
			while(str[i] <= '9' && str[i] >= '0')
				i++;
		}
    return res;
}

int ft_malloc_size(int ac, char **av)
{
    int res;
    int i;
    int tmp_ac;
    
    res = 0;
    i = 1;
    tmp_ac = ac;
    while(av[i])
    {
        if(ft_num_of_args(av[i]) != -1)
        {
            res += ft_num_of_args(av[i]);
            i++;   
        }else
            return (-1);
    }
    return (res);
}

void init_stack_helper(int size, int *array, char **av)
{
	int i;
	int j;
	
	i = 1;
	while(av[i])
	{
		j = 0;
		while(av[i][j])
		{
			while ((av[i][j] >= 9 && av[i][j] <= 13) || av[i][j] == 32)
				j++;
			if (av[i][j] == '-' || av[i][j] == '+' || (av[i][j] <= '9' && av[i][j] >= '0'))
			{
				while(av[i][j] <= '9' && av[i][j] >= '0')
						i++;
			}
			
			
		}
	}	
}

int *init_stack(int size, int ac, char **av)
{
    int *array;
    int i;

    array = malloc(sizeof(int) * (size + 1));
    i = 0;
    while(i < size)
    {
        array[i] = ft_get_number(ac, av);
		i++;
    }
    array[i] = NULL;
    return (array);
}

int main(int ac, char **av)
{
    printf("YASİN : %d\n", ft_malloc_size(ac, av));
}