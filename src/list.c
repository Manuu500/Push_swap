/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 18:51:30 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/05/07 19:23:04 by mruiz-ur         ###   ########.fr       */
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
	}
}
