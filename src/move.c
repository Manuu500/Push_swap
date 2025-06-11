/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 15:48:06 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/06/11 14:55:24 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mixed_move(t_main *main, t_cost move)
{
	if (move.prep_a.direc == UP)
		while (move.prep_a.node->prev)
			ra(main);
	if (move.prep_a.direc == DOWN)
		while (move.prep_a.node->prev)
			rra(main);
	if (move.prep_b.direc == UP)
		while (move.prep_b.node->prev)
			rb(main);
	if (move.prep_b.direc == DOWN)
		while (move.prep_b.node->prev)
			rrb(main);
}


void	perf_move(t_main *main, t_cost move, t_bool stack_a)
{
	if (move.direc == UP)
	{
		while (move.prep_a.node->prev && move.prep_b.node->prev)
			rr(main);
		while (move.prep_a.node->prev)
			ra(main);
		while (move.prep_b.node->prev)
			rb(main);
	}
	if (move.direc == DOWN)
	{
		while (move.prep_a.node->prev && move.prep_b.node->prev)
			rrr(main);
		while (move.prep_a.node->prev)
			rra(main);
		while (move.prep_b.node->prev)
			rrb(main);
	}
	if (move.direc == MIXED)
		mixed_move(main, move);
	if (stack_a)
		pb(main);
	else
		pa(main);
}

void	final_sort(t_main *main)
{
	t_stack	*lst;
	t_stack	*node;

	lst = main->a;
	node = lst;
	while (lst)
	{
		if (lst->content < node->content)
			node = lst;
		lst = lst->next;
	}
	if (ft_lstnextsize(node) < ft_lstprevsize(node))
		while (node->prev)
			rra(main);
	else
		while (node->prev)
			ra(main);
}