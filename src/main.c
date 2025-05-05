/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 18:52:59 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/05/05 16:30:12 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_main	main;
	
	initialize_vars(&main, argv, argc);
	// if (argc > 2)
	// {
	// 	save_args(&main);
	// }
	// else
	// 	save_args2(&main, 0);
	// validate_nums(argv);
	parse_args(&main, argc, argv);
	// save_args3(&main);
	// free(main.arg_alloc_i);
	return (0);
}