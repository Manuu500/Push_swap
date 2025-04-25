/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:43:02 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/04/25 18:40:58 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize_vars(t_main	*main, char **argv, int argc)
{
	main->argc = argc;
	if (!main->argc)
		ft_error("The amount of args has not been saved");
	main->argv = argv;
	if (!main->argv)
		ft_error("The amount of argvs has not been saved");
}

void	save_args(t_main *main)
{
	int	num;
	int	check;
	int	i;

	check = 0;
	main->arg_alloc_i = malloc(sizeof(int) * main->argc);
	if (!main->arg_alloc_i)
		ft_error("The alloc failed on save_numbers function");
	i = 1;
	while (i < main->argc)
	{
		is_valid_number(main, i);
		if (check == 1)
			ft_error("One argument is not a number");
		num = ft_atoi(main->argv[i]);
		check_num_limit(num);
		main->arg_alloc_i[i] = num;
		i++;
	}
	check_dup_num(main);
}

void	save_args2(t_main *main)
{
	int	i;
	int	j;
	int	num;
	
	i = 0;
	main->arg_matrix = ft_split(main->argv[1], ' ');
	if (!main->arg_matrix)
		ft_error("Alloc failed on save_args2");
	while (main->arg_matrix[i])
		i++;
	main->arg_alloc_i = malloc(sizeof(char) * i);
	if (!main->arg_alloc_i)
		ft_error("Couldnt alloc in save_args2 ");
	j = 0;
	while (main->arg_matrix[j])
	{
		num = ft_atoi(main->arg_matrix[j]);
		main->arg_alloc_i[j] = num;
		j++;
	}
}
