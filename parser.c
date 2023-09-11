/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoktas <mtoktas@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 20:37:53 by mtoktas           #+#    #+#             */
/*   Updated: 2023/09/11 21:31:51 by mtoktas          ###   ########.fr       */
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
		if (res > 2147483647)
			return (-1);
		if (res < -2147483648)
			return (0);
		i++;
	}
	return (res);
}

int ft_num_of_args(char *str)
{
    int i;
    int res;
    
    i = 0;
    res = 0;
		while (str[i])
		{
			while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
				i++;
			if (str[i] == '-' || str[i] == '+')
			{
				if(str[i + 1] <= '9' && str[i + 1] >= '0')
					i++;
				else{
					write(2,"Invalid argument\n", 17);
					return (-1);
				}
			}
			if (str[i] <= '9' && str[i] >= '0')
			{
				res += 1;
				i++;
			}
			else if (str[i] == 0)
				break;
			else
			{
				write(2,"Invalid argument\n", 17);
				return (-1);
			}
			while (str[i] <= '9' && str[i] >= '0')
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

void init_stack_helper(int *array, char **av)
{
	int i;
	int j;
	int arr_i;
	
	i = 1;
	arr_i = 0;
	while (av[i])
	{
		j = 0;
		while(av[i][j])
		{
			while ((av[i][j] >= 9 && av[i][j] <= 13) || av[i][j] == 32)
				j++;
			if (av[i][j] == '-' || av[i][j] == '+' || (av[i][j] <= '9' && av[i][j] >= '0'))
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

int *init_stack(int (*f)(int, char**), int ac, char **av)
{
    int *array;
    int i;

    array = malloc(sizeof(int) * (f(ac, av) + 1));
    i = 0;
	init_stack_helper(array, av);
    return (array);
}

int main(int ac, char **av)
{
    int *array;
	int i = 0;
	array = init_stack(ft_malloc_size, ac, av);
	while(array[i])
	{
		printf("%d\n\n", array[i]);
		i++;
	}

	/*if(!is_array_ordered(array))
		printf("ARRAY NOT ORDERED");*/
	
	if(control_duplicates(array))
		printf("NO DUPLICATES\n\n");

}