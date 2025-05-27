/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:18:15 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/05/27 18:26:41 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_two(t_main *main, int flag)
{
	int	first;
	
	if (flag == 0)
	{
		first = main->a->content;
		if (first < main->a->next->content)
			sa(main);
		else
			return ;
	}
	else if (flag == 1)
	{
		first = main->b->content;
		if (first < main->b->next->content)
			sb(main);
		else
			return ;
	}
}

void	stack_three(t_main *main)
{
	main->a_int = main->a->content;
	main->b_int = main->a->next->content;
	main->c_int = main->a->next->next->content;
	if (main->a_int < main->b_int && main->b_int < main->c_int)
		return ;
	if (main->a_int > main->b_int && main->a_int > main->c_int)
	{
		ra(main);
		if (main->a->content > main->a->next->content)
			sa(main);
	}
	else if (main->b_int > main->a_int && main->b_int > main->c_int)
	{
		rra(main);
		if (main->a->content > main->a->next->content)
			sa(main);
	}
	else
	{
		if (main->a_int > main->b_int)
			sa(main);
	}
}

void	stack_three_b(t_main *main)
{
	main->a_int = main->b->content;
	main->b_int = main->b->next->content;
	main->c_int = main->b->next->next->content;
	if (main->a_int > main->b_int && main->b_int > main->c_int)
		return ;
	if (main->a_int < main->b_int && main->a_int < main->c_int)
	{
		rb(main);
		if (main->b->content < main->b->next->content)
			sb(main);
	}
	else if (main->b_int < main->a_int && main->b_int < main->c_int)
	{
		rrb(main);
		if (main->b->content < main->b->next->content)
			sb(main);
	}
	else
	{
		if (main->a_int < main->b_int)
			sb(main);
	}
}

t_stack	find_last(t_stack *list)
{
	t_stack	last;

	last.content = list->content;
	while (list)
	{
		if (list->next == NULL)
			last.content = list->content;
		list = list->next;
	}
	return (last);
}

void	stack_more(t_main *main)
{
	int	cont;
	int	pos;
	t_stack *temp;

	cont = 0;
	temp = main->a;
	while (temp != NULL)
	{
		temp = temp->next;
		cont++;
	}
	while (cont > 3)
	{
		pb(main);
		cont--;
	}
	stack_three(main);
	while(main->b)
	{
		pos = find_insert_position(main, main->b->content);
		move_to_position(main, pos);
		pa(main);
	}
	rotate_to_min(main);
}


