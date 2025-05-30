/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 09:11:55 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/05/30 14:56:13 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	free(value);
	return (result);
}

static void	create_list(t_main *main, char **av_array, int *num_array)
{
	t_stack	*new_node;
	t_stack	*list;
	int		i;
	int		array_size;
	
	list = NULL;
	i = 0;
	array_size = 0;
	while (av_array[array_size])
		array_size++;
	while (i < array_size)
	{
		num_array[i] = ft_atoll(main, av_array[i]);
		check_num_limit(main, num_array[i]);
		new_node = ft_lstnew_swap(num_array[i]);
		ft_lstadd_back_swap(&list, new_node);
		i++;
	}
	main->a = list;
	main->b = NULL;
	validate_dup(main, num_array);
	main->num_array = num_array;
}

void	 parse_args(t_main *main, int argc, char **argv)
{
	t_stack	*list;
	char	**av_array;
	int		*num_array;
	int		i;
	int		j;

	i = 0;
	list = NULL;
	num_array = NULL;
	av_array = parse_char(main, argc, argv);
	while (av_array[i]) 
		i++;
	main->ar_count = i;
	num_array = malloc(sizeof(int) * i);
	if (!num_array)
		exit(EXIT_FAILURE);
	create_list(main, av_array, num_array);
	j = 0;
	while (av_array[j])
	{
		free(av_array[j]);
		j++;
	}
	free(av_array);
}
