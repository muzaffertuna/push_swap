/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoktas <mtoktas@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 20:37:51 by mtoktas           #+#    #+#             */
/*   Updated: 2023/09/12 17:01:48 by mtoktas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_stack
{
	int	*stack_a;
	int	top_a;
	int	*stack_b;
	int	top_b;
	int	stack_len;
}	t_stack;

int		ft_len(const char *str);
int		ft_atoi(const char *str);
int		ft_num_of_args(char *str);
int		ft_malloc_size(int ac, char **av);
void	init_stack_helper(int *array, char **av);
void	init_stack(t_stack *stack, int ac, char **av);
int		is_ordered(int *stack, int arr_len);
int		is_duplicate(int *stack, int arr_len);
int		check_args(int *stack, int arr_len);
void	swap_a(t_stack *stack);
void	swap_b(t_stack *stack);
void	ss(t_stack *stack);
void	push_a(t_stack *stack);
void	push_b(t_stack *stack);
void	rotate_a(t_stack *stack);
void	rotate_b(t_stack *stack);
void	rr(t_stack *stack);
void	reverse_rotate_a(t_stack *stack);
void	reverse_rotate_b(t_stack *stack);
void	rrr(t_stack *stack);

#endif