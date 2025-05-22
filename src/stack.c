/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:18:15 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/05/22 17:16:28 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_two(t_main *main)
{
	int	first;
	
	first = main->a->content;
	if (first < main->a->next->content)
		sa(main);
	// while(main->a != NULL)
	// {
	// 	ft_printf("Nodo: %d\n", main->a->content);
	// 	main->a = main->a->next;
	// }
}

void stack_more(t_main *main)
{
	int	first;
	int	bigger;
	t_stack	*tmp;
	
	first = main->a->content;
	bigger = first;
	tmp = main->a;
	while (tmp->next != NULL)
	{
		if (tmp->next->content > first)
		{
			bigger = tmp->next->content;
			ra(main);
			tmp = main->a;
		}
		else if (tmp->content > bigger)
			sa(main);
		tmp = tmp->next;
	}
}

