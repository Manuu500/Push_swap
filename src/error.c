/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 19:01:26 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/06/18 15:53:07 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error(t_main *main, char *message)
{
	ft_printf(message);
	ft_printf("\n");
	if (main)
	{
		if (main->a)
			free_stack(&main->a);
		if (main->b)
			free_stack(&main->b);
		if (main->list)
			free(main->list);
		if (main->num_array)
			free(main->num_array);
		// if (main->av_array)
		// 	free(main->num_array);
	}
	exit (1);
}

void	free_matrix(char **matrix)
{
	int i;

	i = 0;
	if (!matrix)
		return ;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	check_num_beyond(t_main *main, long long n)
{
	if (n > INT_MAX || n < INT_MIN)
	{
		free_matrix(main->av_array);
		ft_error(main, "One number is beyond the limits");
	}
}