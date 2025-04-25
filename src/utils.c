/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:43:02 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/04/25 16:30:15 by mruiz-ur         ###   ########.fr       */
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
	int	i;
	i = 1;
	main->arg_alloc = malloc(sizeof(int) * main->argc + 1);
	if (!main->arg_alloc)
		ft_error("The alloc failed on save_numbers function");
	while (i < main->argc)
	{
		num = ft_atoi(main->argv[i]);
		check_number(num);
		main->arg_alloc[i] = num;
		i++;
	}
	if (!main->arg_alloc)
		ft_error("No number allocated");
	check_dup_num(main);
}
