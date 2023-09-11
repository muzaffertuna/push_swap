/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoktas <mtoktas@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 20:37:51 by mtoktas           #+#    #+#             */
/*   Updated: 2023/09/11 21:30:08 by mtoktas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_len(const char *str);
int	ft_atoi(const char *str);
int ft_num_of_args(char *str);
int ft_malloc_size(int ac, char **av);
void init_stack_helper(int *array, char **av);
int *init_stack(int (*f)(int, char**), int ac, char **av);
int is_array_ordered(int *array);
int control_duplicates(int *array);

#endif