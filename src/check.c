/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:11:31 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/05/30 14:46:55 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_num_limit(t_main *main, long long num)
{
	if (num > INT_MAX || num < INT_MIN)
		ft_error(main, "Number exceeds integer limits");
}

int	is_valid_number(t_main *main, char **nums)
{
	int	i;
	int	j;
	
	i = 1;
	while (nums[i])
	{
		j = 0;
		while (nums[i][j] == ' ')
			j++;
		if (nums[i][j] == '-' || nums[i][j] == '+')
			j++;
		if (nums[i][j] == '\0')
			ft_error(main, "One argument is not valid");		
		while (nums[i][j])
		{
			if (nums[i][j] == ' ')
				j++;
			if (nums[i][j] < '0' || nums[i][j] > '9')
				ft_error(main, "One argument is not valid");
			else
				j++;
		}
		i++;
	}
	return (1);
}

int validate_dup(t_main *main, int *nums)
{
	int	i;
	int	j;
	int	array_size;
	t_stack *temp;

	array_size = 0;
	temp = main->a;
	while (temp)
	{
		array_size++;
		temp = temp->next;
	}
	i = 0;
	while (i < array_size)
	{
		j = i + 1;
		while (j < array_size)
		{
			if (nums[i] == nums[j])
				ft_error(main, "There is one number duplicated");
			j++;
		}
		i++;
	}
	return (1);
}
