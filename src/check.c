/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:11:31 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/04/25 16:44:31 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_number(int num)
{
	ft_printf("El numero pasado es: %d\n", num);
	if (num > INT_MAX || num < INT_MIN)
		ft_error("El numero sobrepasa un límite");
}

char	is_valid_number(char num)
{
	return (num < '0' || num > '9');
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
