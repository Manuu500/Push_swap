/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:11:31 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/04/25 17:54:00 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_num_limit(int num)
{
	ft_printf("El numero pasado es: %d\n", num);
	if (num > INT_MAX || num < INT_MIN)
		ft_error("El numero sobrepasa un límite");
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
			check = 1;
		i++;
	}
	return (check);
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
			if (main->arg_alloc[i] == main->arg_alloc[j])
				ft_error("One number is duplicated");
			j++;
		}
		i++;
	}
}
