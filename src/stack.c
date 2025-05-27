/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:18:15 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/05/27 16:51:12 by mruiz-ur         ###   ########.fr       */
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
	int	a;
	int	b;
	int	c;

	a = main->a->content;
	b = main->a->next->content;
	c = main->a->next->next->content;
	if (a < b && b < c)
		return ;
	if (a > b && a > c)
	{
		ra(main);
		if (main->a->content > main->a->next->content)
			sa(main);
	}
	else if (b > a && b > c)
	{
		rra(main);
		if (main->a->content > main->a->next->content)
			sa(main);
	}
	else
	{
		if (a > b)
			sa(main);
	}
}

void	stack_three_b(t_main *main)
{
	int	a;
	int	b;
	int	c;

	a = main->b->content;
	b = main->b->next->content;
	c = main->b->next->next->content;
	if (a > b && b > c)
		return ;

	if (a < b && a < c)
	{
		rb(main);
		if (main->b->content < main->b->next->content)
			sb(main);
	}
	else if (b < a && b < c)
	{
		rrb(main);
		if (main->b->content < main->b->next->content)
			sb(main);
	}
	else
	{
		if (a < b)
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
	int	cont_b;
	int	pos;
	t_stack *temp;
	t_stack *temp_b;

	cont = 0;
	cont_b = 0;
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
	temp_b = main->b;
	while (temp_b != NULL)
	{
		cont_b++;
		if (cont_b == 2)
			stack_two(main, 1);
		else if (cont_b == 3)
			stack_three_b(main);
		temp_b = temp_b->next;
	}
	while(main->b)
	{
		pos = find_insert_position(main, main->b->content);
		move_to_position(main, pos);
		pa(main);
	}
	rotate_to_min(main);
}

// void	stack_more(t_main *main)
// {
// 	t_stack *stack_b;
// 	t_stack *stack;
// 	int	cont;
// 	int	i;
	
// 	i = -1;
// 	cont = 0;
// 	stack = main->a;
// 	stack_b = main->b;
// 	while (stack)
// 	{
// 		cont++;
// 		stack = stack->next;
// 	}
// 	while (i < cont)
// 	{
// 		pb(main);
// 		if (i == 2)
// 			stack_two(main, 1);
// 		else if (i == 3)
// 			stack_three(main);
// 		i++;
// 	}
// 	stack_b = main->b;
// 	while (stack_b)
//  	{
//  		ft_printf("Nodos B: %d\n", stack_b->content);
// 		stack_b = stack_b->next;
// 	}

// }
