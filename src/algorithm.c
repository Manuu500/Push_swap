/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:32:49 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/05/07 19:18:53 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	high_to_low(t_stack *list, int *array, int argc)
{
	t_stack	*temp;
	int	i;
	
	(void) argc;
	i = 0;
	temp = list;
	while (array[i])
	{
		ft_printf("Array original: %d\n", array[i]);
		i++;
	}
	i = 0;
	while (temp != NULL)
	{
		ft_printf("Nodos: %d\n", (temp->content));
		temp = temp->next;
	}
}