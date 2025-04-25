/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 19:01:42 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/04/25 17:54:10 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libs/libft/libft.h"
# include <limits.h>

typedef struct main
{
	int	*arg_alloc;
	int	argc;
	char	**argv;
}				t_main;


int		ft_error(char *message);
void	initialize_vars(t_main	*main, char **argv, int argc);
void	save_args(t_main *main);
void	check_num_limit(int num);
void	check_dup_num(t_main *main);
int		is_valid_number(t_main *main, int i);

#endif