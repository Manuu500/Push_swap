/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:32:49 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/05/30 15:02:03 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **source, t_stack **dest)
{
	if (!*source)
		return ;
	ft_lstadd_front_swap(dest, ft_detach(source, *source));
}

t_stack	*ft_detach(t_stack **list, t_stack *node)
{
	if (!list || !node)
		return (0);
	if (node->prev)
		(node->prev)->next = node->next;
	else
		*list = node->next;
	if (node->next)
		(node->next)->prev = node->prev;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	rotate(t_stack **list)
{
	t_stack	*first;
	t_stack *second;
	t_stack	*last;

	if (!*list)
		return ;
	first = *list;
	second = first->next;
	last = first;
	while (last->next != NULL)
	{	
		last = last->next;
	}
	last->next = first;
	first->next = NULL;
	first->prev = last;
	second->prev = NULL;
	*list = second;
}

void	reverse_rotate(t_stack **list)
{
	t_stack *penultimate;
	t_stack *first;
	// t_stack *second;
	t_stack *last;

	if (!*list)
		return ;
	penultimate = NULL;
	first = *list;
	// second = first->next;
	last = first;
	while (last->next != NULL)
	{
		penultimate = last;
		last = last->next;
	}
	last->next = first;
	first->prev = last;
	penultimate->next = NULL;
	last->prev = NULL;
	*list = last;
}

void	swap(t_stack **list)
{
	t_stack *first;
	t_stack *second;
	int	temp;

	if (!(*list))
		return ;
	if ((*list)->next == NULL)
		return ;
	
	first = *list;
	second = first->next;
	temp = first->content;
	first->content = second->content;
	second->content = temp;	
}
