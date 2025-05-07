/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 19:01:42 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/05/07 19:23:20 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libs/libft/libft.h"
# include <limits.h>

typedef struct s_stack
{
	int	content;
	struct s_stack *next;
}				t_stack;

typedef struct main
{
	char	**arg_matrix;
	char	*arg_temp;
	char	**argv;
	int		argc;
	int		*num_array;
	int		c_arg_count;
	t_stack	*list;
}				t_main;


long long	ft_atoll(t_main *main, const char *str);
int			ft_error(t_main *main, char *message);
void		initialize_vars(t_main	*main, char **argv, int argc);
void		save_args(t_main *main);
void		check_num_limit(t_main *main, long long num);
void		check_dup_num(t_main *main, char **nums, int argc);
int			is_valid_number(t_main *main, char **nums);
// void		is_valid_number_s(t_main *main, int i);
void		save_args2(t_main *main, int flag);
int			count_args(t_main *main);
void		free_matrix(char **matrix);
void		check_dup_num_c(t_main *main);
void		save_args3(t_main *main);
void		alloc_args(t_main *main, int flag);
char		**parse_char(t_main *main, int ac, char **av);
void		parse_args(t_main *main, int argc, char **argv);
// int			validate_nums(char **nums, int ac);
int			check_duplicated(char **nums, int argc);
int 		validate_dup(t_main *main, int *nums);
void	high_to_low(t_stack *list, int *array, int argc);
//Lists
t_stack	*ft_lstnew_swap(int content);
void	ft_lstadd_back_swap(t_stack **lst, t_stack *new);

#endif