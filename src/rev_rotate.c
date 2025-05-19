/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:54:35 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/05/19 17:56:43 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_main *main)
{
	reverse_rotate(&main->a);
	ft_printf("rra\n");
}

void	rrb(t_main *main)
{
	reverse_rotate(&main->b);
	ft_printf("rrb\n");
}

void	rrr(t_main *main)
{
	reverse_rotate(&main->a);
	reverse_rotate(&main->b);
	ft_printf("rrr\n");
}