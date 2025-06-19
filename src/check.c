/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:11:31 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/06/19 12:46:51 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_num_limit(t_main *main, long long num)
{
	if (num > 2147483648 || num < -2147483648)
	{
		ft_error(main, "Error");
	}
}

int	is_valid_number(t_main *main, char **nums)
{
	int	i;
	int	j;

	i = 1;
	while (nums[i])
	{
		j = 0;
		while (nums[i][j])
		{
			while (nums[i][j] == ' ')
				j++;
			if (nums[i][j] == '-' || nums[i][j] == '+')
				j++;
			if (!nums[i][j] || nums[i][j] < '0' || nums[i][j] > '9')
				ft_error(main, "Error");
			while (nums[i][j] >= '0' && nums[i][j] <= '9')
				j++;
			if (nums[i][j] && nums[i][j] != ' ')
			{
				ft_error(main, "Error");
			}
		}
		i++;
	}
	return (1);
}

int	validate_dup(t_main *main, int *nums)
{
	int		array_size;
	t_stack	*temp;
	int		i;
	int		j;

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
				ft_error(main, "Error");
			j++;
		}
		i++;
	}
	return (1);
}

int	check_ordered(t_main *main)
{
	t_stack	*temp;
	int		count;

	count = 1;
	temp = main->a;
	while (temp->next != NULL)
	{
		if (temp->next->content > temp->content)
			count++;
		temp = temp->next;
	}
	if (count == main->ar_count)
		return (1);
	else
		return (0);
}
