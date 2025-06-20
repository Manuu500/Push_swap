/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 19:01:42 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/06/19 12:47:39 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libs/libft/libft.h"
# include <limits.h>

typedef enum s_direc
{
	ANY,
	UP,
	DOWN,
	MIXED,
}	t_direc;

typedef struct s_stack
{
	struct s_stack	*prev;
	struct s_stack	*next;
	int				content;
	int				index;
}				t_stack;

typedef struct s_prep
{
	t_stack	*node;
	int		cost;
	t_direc	direc;
}				t_prep;

typedef struct s_cost
{
	int		total;
	t_direc	direc;
	t_prep	prep_a;
	t_prep	prep_b;
}				t_cost;

typedef enum e_bool
{
	false,
	true,
}	t_bool;

typedef struct main
{
	char	**av_array;
	char	**arg_matrix;
	char	*arg_temp;
	char	**argv;
	int		argc;
	int		*num_array;
	int		c_arg_count;
	int		ar_count;
	int		a_int;
	int		b_int;
	int		c_int;
	t_stack	*a;
	t_stack	*b;
	t_stack	*list;
}				t_main;

long long	ft_atoll(t_main *main, const char *str);
int			ft_error(t_main *main, char *message);
void		initialize_vars(t_main	*main, char **argv, int argc);
void		save_args(t_main *main);
void		check_num_limit(t_main *main, long long num);
void		check_dup_num(t_main *main, char **nums, int argc);
int			is_valid_number(t_main *main, char **nums);
void		save_args2(t_main *main, int flag);
int			count_args(t_main *main);
void		free_matrix(char **matrix);
void		check_dup_num_c(t_main *main);
void		save_args3(t_main *main);
void		alloc_args(t_main *main, int flag);
void		parse_char(t_main *main, int ac, char **av);
void		parse_args(t_main *main, int argc, char **argv);
int			check_duplicated(char **nums, int argc);
int			validate_dup(t_main *main, int *nums);
t_stack		*ft_lstnew_swap(int content);
t_stack		*ft_lstlast_swap(t_stack *lst);
void		ft_lstadd_front_swap(t_stack **lst, t_stack *new);
void		rotate_pos(t_stack **stack);
void		ft_lstadd_back_swap(t_stack **lst, t_stack *new);
void		swap(t_stack **list);
void		rotate(t_stack **list);
void		reverse_rotate(t_stack **list);
void		push(t_stack **listA, t_stack **listB);
t_stack		*ft_detach(t_stack **list, t_stack *node);
void		pa(t_main *main);
void		pb(t_main *main);
void		sa(t_main *main);
void		sb(t_main *main);
void		ss(t_main *main);
void		ra(t_main *main);
void		rb(t_main *main);
void		rr(t_main *main);
void		rra(t_main *main);
void		rrb(t_main *main);
void		rrr(t_main *main);
void		stack_two(t_main *main, int flag);
void		stack_three(t_main *main);
void		stack_more(t_main *main);
void		stack_three_b(t_main *main);
t_stack		*find_last(t_stack *lst);
int			find_insert_position(t_main *main, int value);
void		move_to_position(t_main *main, int pos);
void		rotate_to_min(t_main *main);
void		print_list(t_stack *main);
int			check_ordered(t_main *main);
int			ft_lstprevsize(t_stack *list);
int			ft_lstnextsize(t_stack *list);
t_prep		set_prep(t_stack *node, int cost, t_direc dir);
t_prep		cost_to_put_first(t_stack *node);
t_stack		*place_in_stack_a(t_stack *stack, t_stack *node);
t_stack		*place_in_stack_b(t_stack *stack, t_stack *node);
void		put_cheapest(t_main *main, t_bool stack_a);
int			ft_lstsize_ps(t_stack *list);
void		mixed_move(t_main *main, t_cost move);
void		perf_move(t_main *main, t_cost move, t_bool stack_a);
void		initial_desp(t_main *main);
void		final_sort(t_main *main);
void		free_stack(t_stack **stack);
void		check_num_beyond(t_main *main, long long n);
void		check_empty_args(t_main *main, char **args);

#endif