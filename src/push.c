/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:02:48 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/05/30 15:14:26 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_main *main)
{
	push(&main->b, &main->a);
	ft_printf("pa\n");
}

void	pb(t_main *main)
{
	push(&main->a, &main->b);
	ft_printf("pb\n");
}