/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:18:15 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/05/22 19:08:14 by mruiz-ur         ###   ########.fr       */
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

void stack_three(t_main *main)
{
	int	first;
	int	smaller;
	t_stack	*tmp;
	
	first = main->a->content;
	smaller = first;
	tmp = main->a;
	while (tmp->next != NULL)
	{
		if (tmp->next->content < first)
		{
			smaller = tmp->next->content;
			rra(main);
			tmp = main->a;
		}
		else if (tmp->content < smaller)
			sa(main);
		tmp = tmp->next;
	}
}

void	stack_more(t_main *main)
{
	int	cont;
	int	cont_b;
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
		else if (cont_b > 2)
		{	
		}
		temp_b = temp_b->next;
	}
	// ra(main);
	// pa(main);
	// rra(main);
	ft_printf("Contador: %d\n", cont);
	temp = main->b;
	while (temp != NULL)
	{
		ft_printf("Nodos B: %d\n", temp->content);
		temp = temp->next;
	}
}

