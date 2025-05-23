/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 18:52:59 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/05/23 12:31:47 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_main	main;

	initialize_vars(&main, argv, argc);
	is_valid_number(&main, argv);
	parse_args(&main, argc, argv);
	if (argc == 3)
		stack_two(&main, 0);
	// stack_three(&main);
	stack_more(&main);
	// push(&main.a, &main.b);
	// pb(&main);
	// pa(&main);
	// sa(&main);
	// sb(&main);
	// ss(&main);
	// ra(&main);
	// rb(&main);
	// rr(&main);
	// rra(&main);
	// rrb(&main);
	// rrr(&main);
	// reverse_rotate(main.a);
	// rotate(main.a);
	// swap(main.a);
	// save_args3(&main);
	// free(main.arg_alloc_i);
	return (0);
}