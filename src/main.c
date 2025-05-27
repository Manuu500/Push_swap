/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 18:52:59 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/05/27 16:48:20 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_main	main;

	initialize_vars(&main, argv, argc);
	is_valid_number(&main, argv);
	parse_args(&main, argc, argv);
	if (argc == 2)
		ft_printf(argv[1]);
	else if (argc == 3)
	{
		stack_two(&main, 0);
		print_list(&main);
	}
	else if (argc == 4)
	{
		stack_three(&main);
		print_list(&main);
	}
	else
	{ 
		stack_more(&main);
		print_list(&main);
	}
	return (0);
}