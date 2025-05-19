/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 09:11:55 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/05/19 16:14:19 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void	join_args()
// {
	
// }

// void	save_args(t_main *main)
// {
// 	int	num;
// 	int	check;
// 	int	i;

// 	check = 0;
// 	main->arg_alloc_i = malloc(sizeof(int) * main->argc);
// 	if (!main->arg_alloc_i)
// 		ft_error(main, "The alloc failed on save_numbers function");
// 	i = 1;
// 	while (i < main->argc)
// 	{
// 		check = is_valid_number(main, i);
// 		if (check == 1)
// 			ft_error(main, "One argument is not a number");
// 		num = ft_atoll(main, main->argv[i]);
// 		check_num_limit(main, num);
// 		main->arg_alloc_i[i] = num;
// 		i++;
// 	}
// 	check_dup_num(main);
// }

// void	save_args2(t_main *main, int flag)
// {
// 	int	i;
// 	int	num;
	
// 	i = 0;
// 	if (flag == 1)
// 		alloc_args(main, 1);
// 	else
// 		alloc_args(main, 0);
// 	count_args(main);
// 	main->arg_alloc_i = malloc(sizeof(int) * main->c_arg_count);
// 	if (!main->arg_alloc_i)
// 		ft_error(main, "Couldnt alloc in save_args2");
// 	i = 0;
// 	while (main->arg_matrix[i])
// 	{
// 		is_valid_number_s(main, i);
// 		num = ft_atoll(main, main->arg_matrix[i]);
// 		check_num_limit(main, num);
// 		main->arg_alloc_i[i] = num;
// 		i++;
// 	}
// 	check_dup_num_c(main);
// }

char	**parse_char(t_main *main, int ac, char **av)
{
	char		**result;
	char	*value;
	char	*temp;
	int		i;
	
	i = 1;
	value = ft_strdup("");
	if (ac == 1)
		ft_error(main, "There's only one argument");
	while (av[i])
	{
		temp = value;
		value = ft_strjoin(value, av[i]);
		free(temp);
		temp = value;
		value = ft_strjoin(value, " ");
		free(temp);
		i++;
	}
	result = ft_split(value, ' ');
	i = 0;
	return (result);
}

void	 parse_args(t_main *main, int argc, char **argv)
{
	t_stack	*list;
	t_stack	*new_node;
	char	**av_array;
	int		*num_array;
	int	i;

	i = 0;
	list = NULL;
	num_array = NULL;
	av_array = parse_char(main, argc, argv);
	while (av_array[i]) 
		i++;
	num_array = malloc(sizeof(int) * i);
	if (!num_array)
		exit(EXIT_FAILURE);
	i = 0;
	while (av_array[i])
	{
		num_array[i] = ft_atoll(main, av_array[i]);
		new_node = ft_lstnew_swap(num_array[i]);
		ft_lstadd_back_swap(&list, new_node);
		i++;
	}
	main->a = list;
	main->b = NULL;
	validate_dup(main, num_array);
	main->num_array = num_array;
	// free (num_array);
}
