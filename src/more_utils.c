/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruiz-ur <mruiz-ur@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:32:22 by mruiz-ur          #+#    #+#             */
/*   Updated: 2025/06/17 12:30:10 by mruiz-ur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_insert_position(t_main *main, int value)
{
    t_stack *stack;
    int min_pos;
    int min;
    int max;
    int i;
    
	stack = main->a;
	min_pos = 0;
	max = INT_MIN;
	min = INT_MAX;
	i = 0;
    while (stack)
    {
        if (stack->content < min)
        {
            min = stack->content;
            min_pos = i;
        }
        if (stack->content > max)
            max = stack->content;
        stack = stack->next;
        i++;
    }    
    if (value > max || value < min)
        return min_pos;
    stack = main->a;
    i = 0;
    while (stack && stack->next)
    {
        if (value > stack->content && value < stack->next->content)
            return i + 1;
        stack = stack->next;
        i++;
    } 
    return 0;
}

void move_to_position(t_main *main, int pos)
{
    int stack_size;
    t_stack *temp;
    int	i;

	i = 0;
	temp = main->a;
	stack_size = 0;
    while (temp)
    {
        stack_size++;
        temp = temp->next;
    }    
    if (pos <= stack_size / 2)
    {
		while (i < pos)
		{
			ra(main);
			i++;
		}
    }
    else
    {
		i = 0;
		while (i < stack_size - pos)
		{
			rra(main);
			i++;
		}
    }
}

void rotate_to_min(t_main *main)
{
    t_stack *stack;
    int max;
    int min_pos;
    int i;
    
	stack = main->a;
	max = INT_MAX;
	min_pos = 0;
	i = 0;
    while (stack)
    {
        if (stack->content < max)
        {
            max = stack->content;
            min_pos = i;
        }
        stack = stack->next;
        i++;
    }
    move_to_position(main, min_pos);
}

void	print_list(t_stack *main)
{
		ft_printf("list:  ");
	while (main)
	{
		ft_printf("%d ", main->content);
		main = main->next;
	}
	ft_printf("\n");
}

t_stack	*place_in_stack_a(t_stack *stack, t_stack *node)
{
	t_stack	*lowest;
	t_stack	*current;
	t_stack	*closest;

	lowest = stack;
	current = lowest;
	closest = 0;
	while (current)
	{
		if (!closest)
		{
			if (current->content < lowest->content)
				lowest = current;
			if (current->content > node->content)
				closest = current;
		}
		else if (current->content < closest->content
			&& current->content > node->content)
			closest = current;
		current = current->next;
	}
	if (closest)
		return (closest);
	return (lowest);
}

t_stack	*place_in_stack_b(t_stack *stack, t_stack *node)
{
	t_stack	*biggest;
	t_stack	*current;
	t_stack	*closest;

	biggest = stack;
	current = biggest;
	closest = 0;
	while (current)
	{
		if (!closest)
		{
			if (current->content > biggest->content)
				biggest = current;
			if (current->content < node->content)
				closest = current;
		}
		else if (current->content > closest->content
			&& current->content < node->content)
			closest = current;
		current = current->next;
	}
	if (closest)
		return (closest);
	return (biggest);
}

void free_stack(t_stack **stack)
{
    t_stack *current;
    t_stack *next;

    current = *stack;
    while (current)
    {
        next = current->next;
        free(current);
        current = next;
    }
    *stack = NULL;
}
/*
2 
3 1 6 5 4 -1
*/
