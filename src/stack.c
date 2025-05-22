/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:18:15 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/05/22 18:04:24 by mruiz-ur         ###   ########.fr       */
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
	ra(main);
	pa(main);
	rra(main);
	// ¡ra(main);
	ft_printf("Contador: %d\n", cont);
	temp = main->a;
	while (temp != NULL)
	{
		ft_printf("Nodos: %d\n", temp->content);
		temp = temp->next;
	}
	
}

