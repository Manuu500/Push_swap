/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:32:49 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/05/13 19:36:55 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *list, int *array, int argc)
{
	t_stack	*temp;
	int	i;
	
	(void) argc;
	i = 0;
	temp = list;
	while (array[i])
	{
		// ft_printf("Array original: %d\n", array[i]);
		i++;
	}
	rotate_pos(&temp);
	while (temp != NULL)
	{
		// ft_printf("Nodos: %d\n", (temp->content));
		temp = temp->next;
	}
}

void	swap(t_stack *list, int *array)
{
	t_stack *first;
	t_stack *second;
	int	temp;
	int	i;

	i = 0;
	while (array[i])
	{
		ft_printf("Array original: %d\n", array[i]);
		i++;
	}
	first = list;
	second = first->next;
	temp = first->content;
	first->content = second->content;
	second->content = temp;
	while(list != NULL)
	{
		ft_printf("Nodos: %d\n", first->content);
		first = first->next;
	}	
}