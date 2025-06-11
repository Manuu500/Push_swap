/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:52:50 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/06/11 15:56:09 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_main *main)
{
	rotate(&main->a);
	ft_printf("ra\n");
}

void	rb(t_main *main)
{
	rotate(&main->b);
	ft_printf("rb\n");
}

void	rr(t_main *main)
{
	rotate(&main->a);
	rotate(&main->b);
	ft_printf("rr\n");
}