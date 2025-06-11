/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 18:51:30 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/06/11 15:19:10 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstnew_swap(int content)
{
	t_stack	*new_list;

	new_list = ft_calloc(1, sizeof(t_stack));
	if (!new_list)
		return (NULL);
	new_list->content = content;
	new_list->prev = NULL;
	new_list->next = NULL;
	return (new_list);
}

void	ft_lstadd_back_swap(t_stack **lst, t_stack *new)
{
	t_stack	*list;

	if (*lst == NULL)
		*lst = new;
	else
	{
		list = *lst;
		while (list->next != NULL)
			list = list->next;
		list->next = new;
		new->prev = list;
	}
}
t_stack	*ft_lstlast_swap(t_stack *lst)
{
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

void	rotate_pos(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*before_last;
	
	first = *stack;
	before_last = *stack;
	while (before_last->next->next != NULL)
		before_last = before_last->next;
	last = before_last->next;
	before_last->next = NULL;
    last->next = first->next;
    before_last->next = first;
    first->next = NULL;
    *stack = last;
}

void	ft_lstadd_front_swap(t_stack **lst, t_stack *new)
{
	if (*lst)
		(*lst)->prev = new;
	new->next = *lst;
	*lst = new;
}
