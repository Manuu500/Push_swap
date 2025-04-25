/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:11:31 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/04/25 19:41:51 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_num_limit(t_main *main, long long num)
{
	ft_printf("El numero pasado es: %d\n", num);
	if (num > INT_MAX || num < INT_MIN)
		ft_error(main, "El numero sobrepasa un límite");
}

int	is_valid_number(t_main *main, int i)
{
	int	j;
	int	check;
	
	check = 0;
	while (i < main->argc)
	{
		j = 0;
		if (main->argv[i][j] == '-')
			j++;
		if (main->argv[i][j] < '0'
			|| main->argv[i][j] > '9')
			ft_error(main, "One argument is not valid");
		i++;
	}
	return (check);
}

void	is_valid_number_s(t_main *main, int i)
{
	int	j;
	int	num;

	while (i < main->c_arg_count)
	{
		j = 0;
		num = ft_atoi(main->arg_matrix[i]);
		if (main->arg_matrix[i][j] == '-')
			j++;
		if (main->arg_matrix[i][j] < '0'
			|| main->arg_matrix[i][j] > '9')
			ft_error(main, "One argument is not valid");
		i++;
	}
}

void	check_dup_num(t_main *main)
{
	int	i;
	int	j;
	
	i = 0;
	while (i < main->argc)
	{
		j = i + 1;
		while (j < main->argc)
		{
			if (main->arg_alloc_i[i] == main->arg_alloc_i[j])
				ft_error(main, "One number is duplicated");
			j++;
		}
		i++;
	}
}

void	check_dup_num_c(t_main *main)
{
	int	i;
	int	j;
	
	i = 0;
	while (i < main->c_arg_count)
	{
		j = i + 1;
		while (j < main->c_arg_count)
		{
			if (main->arg_alloc_i[i] == main->arg_alloc_i[j])
				ft_error(main, "One number is duplicated");
			j++;
		}
		i++;
	}
}
