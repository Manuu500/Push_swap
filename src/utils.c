/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:43:02 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/04/25 19:46:31 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	save_args(t_main *main)
{
	int	num;
	int	check;
	int	i;

	check = 0;
	main->arg_alloc_i = malloc(sizeof(int) * main->argc);
	if (!main->arg_alloc_i)
		ft_error(main, "The alloc failed on save_numbers function");
	i = 1;
	while (i < main->argc)
	{
		check = is_valid_number(main, i);
		if (check == 1)
			ft_error(main, "One argument is not a number");
		num = ft_atoll(main, main->argv[i]);
		check_num_limit(main, num);
		main->arg_alloc_i[i] = num;
		i++;
	}
	check_dup_num(main);
}

void	save_args2(t_main *main)
{
	int	i;
	int	num;
	
	i = 0;
	main->arg_matrix = ft_split(main->argv[1], ' ');
	if (!main->arg_matrix)
		ft_error(main, "Alloc failed on save_args2");
	count_args(main);
	ft_printf("Datos almacenados en la matriz: %d\n", main->arg_matrix);
	main->arg_alloc_i = malloc(sizeof(int) * main->c_arg_count);
	if (!main->arg_alloc_i)
		ft_error(main, "Couldnt alloc in save_args2");
	i = 0;
	while (main->arg_matrix[i])
	{
		is_valid_number_s(main, i);
		num = ft_atoll(main, main->arg_matrix[i]);
		check_num_limit(main, num);
		main->arg_alloc_i[i] = num;
		i++;
	}
	check_dup_num_c(main);
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
		ft_error(main, "El número se pasa de los limites");
	return (n * sign);
}
