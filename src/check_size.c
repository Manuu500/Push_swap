/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 14:13:13 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/06/11 15:25:40 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_lstprevsize(t_stack *list)
{
	int	i;

	i = 0;
	if (!list)
		return (0);
	while (list->prev)
	{
		i++;
		list = list->prev;
	}
	return (i);
}

int ft_lstnextsize(t_stack *list)
{
	int	i;

	i = 0;
	if (!list)
		return (0);
	while (list->next)
	{
		i++;
		list = list->next;
	}
	return (i);
}

t_prep	set_prep(t_stack *node, int cost, t_direc dir)
{
	t_prep	value;

	value.node = node;
	value.cost = cost;
	value.direc = dir;
	return (value);
}

int	ft_lstsize_ps(t_stack *list)
{
	int	i;

	i = 0;
	if (!list)
		return (0);
	while (list->prev)
	{
		list = list->prev;
	}
	i = 1;
	while (list->next)
	{
		i++;
		list = list->next;
	}
	return (i);
}