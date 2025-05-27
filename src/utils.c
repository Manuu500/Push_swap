/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:43:02 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/05/27 18:22:59 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	alloc_args(t_main *main, int flag)
{
	if (flag == 1)
	{
		main->arg_matrix = ft_split(main->arg_temp, ' ');
		if (!main->arg_matrix)
			ft_error(main, "Alloc failed on save_args2");
	}
	else
	{
		main->arg_matrix = ft_split(main->argv[1], ' ');
		if (!main->arg_matrix)
			ft_error(main, "Alloc failed on save_args2");
	}
}

void	initialize_vars(t_main	*main, char **argv, int argc)
{
	main->argc = argc;
	if (!main->argc)
		ft_error(main, "The amount of args has not been saved");
	main->argv = argv;
	if (!main->argv)
		ft_error(main, "The amount of argvs has not been saved");
	main->c_arg_count = 0;
}

int	count_args(t_main *main)
{
	int	i;

	i = 0;
	while (main->arg_matrix[i])
	{
		main->c_arg_count++;
		i++;
	}
	return (i);
}

long long	ft_atoll(t_main *main, const char *str)
{
	ssize_t		i;
	long long			n;
	int			sign;

	n = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = (n * 10) + (str[i] - '0');
		i++;
	}
	if (n > INT_MAX || n < INT_MIN)
		ft_error(main, "One number is beyond the limits");
	return (n * sign);
}
