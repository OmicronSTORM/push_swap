/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_number.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:13:03 by jowoundi          #+#    #+#             */
/*   Updated: 2025/04/17 13:54:41 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_index(t_node *stack, int value)
{
	int index;
	t_node *runner;
	
	index = 0;
	runner = stack;
	while (runner != NULL)
	{
		if (runner->num == value)
			return (index);
		index++;
		runner = runner->next;
	}
	return (-1);
}

int	list_length(t_node *stack)
{
	int	i;
	t_node	*node;

	i = 0;
	node = stack;
	while (node->next)
	{
		node = node->next;
		i++;
	}
	return (i);
}

int		find_match(t_stack *stack, int value)
{
	int		best_match;
	t_node	*runner;

	(void)value;
	best_match = 0;
	runner = stack->b;
	while (runner != NULL)
	{
		// find the good number to insert, should be next smaller or max if nothing found! :D :D:D :D
		runner = runner->next;
	}
	return (best_match);
}

int		calculate_cost(t_node *stack, int value)
{
	int length;
	int index;
	int cost;

	cost = 0;
	index = find_index(stack, value);
	if (index == -1)
		return (-1);
	length = list_length(stack);
	if (index > length / 2)
	{
		while (index != length)
			cost++;
	}
	else
	{
		while (index != 0)
		cost++;
	}
	return (cost);
}

void	push_stack(t_stack *stack)
{
	
}

void	sort_number(t_stack *stack)
{
	pb(stack);
	pb(stack);
	
	t_node *runner = stack->a->next;

	// int cost = calculate_cost(stack->a, runner->num);
	// ft_printf("COST: %d\n", cost);
		
	while (list_length(stack->a) > 3)
	{
		// push to b using insertion sort
		push_stack(stack);
	}
	// sort stack a 3
	// move max from stack b to the top
	
	while (list_length(stack->b) > 0)
	{
		// push to a at the right spot
	}
	// move max from stack a to the top
}

/*
void	sort_number(t_stack *stack)
{
	int	i;
	int	length;

	i = -1;
	length = list_length(stack->a);
	while (++i <= (length - 3))
	{
		if (i < 2)
		{
			pb(stack);
			continue;
		}
		check_stack(stack);
	}
}
*/