/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:29:48 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/05/19 16:46:30 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_main *main)
{
	swap(&main->a);
	ft_printf("sa\n");
}

void	sb(t_main *main)
{
	swap(&main->b);
	ft_printf("sb\n");
}

void	ss(t_main *main)
{
	swap(&main->a);
	swap(&main->b);
	ft_printf("ss\n");
}