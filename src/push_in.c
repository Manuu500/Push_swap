/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_in.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 14:03:42 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/06/05 16:01:22 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_prep	cost_to_put_first(t_stack *node)
{
	int		cost_up;
	int		cost_down;

	cost_up = ft_lstprevsize(node);
	cost_down = ft_lstnextsize(node) + 1;
	if (cost_down < cost_up)
		return (set_prep(node, cost_down, DOWN));
	else if (cost_down > cost_up)
		return (set_prep(node, cost_up, UP));
	else
		return (set_prep(node, cost_down, ANY));
}

t_cost	cost_to_push(t_main *main, t_stack *current, t_bool stack_a)
{
	t_cost	value;
	
	value.prep_a = cost_to_put_first(current);
	if (stack_a)
		value.prep_b = cost_to_put_first(place_in_stack_b(main->a, current));
	else
		value.prep_b = cost_to_put_first(place_in_stack_a(main->b, current));
	return (value);		
}

void	put_cheapest(t_main *main, t_bool stack_a)
{
	t_prep	placeholder;
	t_stack *current;
	t_cost	cheapest_cost;
	t_cost	current_cost;
	
	if (stack_a)
		current = main->a;
	else
		current = main->b;
	cheapest_cost.total = 2147483647;
	while (current)
	{
		current_cost = cost_to_push(main, current, 1);
		if (current_cost.total < cheapest_cost.total)
			cheapest_cost.total = current_cost.total;
		current = current->next;
	}
	if (!stack_a)
	{
		placeholder = cheapest_cost.prep_a;
		cheapest_cost.prep_a = cheapest_cost.prep_b;
		cheapest_cost.prep_b = placeholder;
	}
	perf_move(main, cheapest_cost, stack_a);
}