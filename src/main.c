/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 18:52:59 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/05/30 15:27:11 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_main	main;
	
	initialize_vars(&main, argv, argc);
	is_valid_number(&main, argv);
	parse_args(&main, argc, argv);
	if (check_ordered(&main) == 1)
		return (0);
	else
	{
		if (main.ar_count == 1)
			return (0);
		else if (main.ar_count == 2)
			stack_two(&main, 0);
		else if (main.ar_count == 3)
			stack_three(&main);
		else
		stack_more(&main);
		// print_list(&main);
	}
	return (0);
}
