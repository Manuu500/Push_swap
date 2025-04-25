/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 19:01:42 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/04/25 19:44:53 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libs/libft/libft.h"
# include <limits.h>

typedef struct main
{
	char	**arg_matrix;
	char	**argv;
	int		argc;
	int		*arg_alloc_i;
	int		c_arg_count;
}				t_main;


int		ft_error(t_main *main, char *message);
void	initialize_vars(t_main	*main, char **argv, int argc);
void	save_args(t_main *main);
void	check_num_limit(t_main *main, long long num);
void	check_dup_num(t_main *main);
int		is_valid_number(t_main *main, int i);
void		is_valid_number_s(t_main *main, int i);
void	save_args2(t_main *main);
int	count_args(t_main *main);
void	free_matrix(char **matrix);
void	check_dup_num_c(t_main *main);
long long	ft_atoll(t_main *main, const char *str);

#endif