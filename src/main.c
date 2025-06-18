/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 18:52:59 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/06/18 19:18:56 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_main	main;
	
	ft_bzero(&main, sizeof(main));
	initialize_vars(&main, argv, argc);
	check_empty_args(&main, argv);
	is_valid_number(&main, argv);
	parse_args(&main, argc, argv);
	if (check_ordered(&main) != 1)
	{
		if (main.ar_count == 1)
			return (0);
		else if (main.ar_count == 2)
			stack_two(&main, 0);
		else if (main.ar_count == 3)
			stack_three(&main);
		else
			stack_more(&main);
	}
	free_stack(&main.a);
	free_stack(&main.b);
	if (main.num_array)
		free(main.num_array);
	return (0);
}

// void	free_stack(t_stack **stack)
// {
// 	t_stack	*current;
// 	t_stack	*next;

//     if (!stack || !(*stack))
//         return;
    
//     current = *stack;
// 	while (current)
// 	{
// 		if (current->next)
// 			next = current->next;
// 		if (current)
// 			free(current);
// 		if (next)
// 			current = next;
// 	}
// 	*stack = NULL;
// }