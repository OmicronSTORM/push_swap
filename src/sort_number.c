/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_number.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:13:03 by jowoundi          #+#    #+#             */
/*   Updated: 2025/04/25 16:00:05 by jowoundi         ###   ########.fr       */
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
	while (node != NULL)
	{
		node = node->next;
		i++;
	}
	return (i);
}

int	max_value(t_node *stack)
{
	t_node	*runner;
	int		max_value;

	max_value = stack->num;
	runner = stack->next;
	while (runner != NULL)
	{
		if (max_value < runner->num)
			max_value = runner->num;
		runner = runner->next;
	}
	return (max_value);
}

int	find_match(t_node *stack, int value)
{
	int		best_match;
	int		check;
	t_node	*runner;

	best_match = 0;
	check = 0;
	printf("findmatch %d\n", value);
	runner = stack;
	while (runner != NULL)
	{
		if (runner->num < value && (!check || runner->num > best_match))
		{
			best_match = runner->num;
			check = 1;
		}
		runner = runner->next;
	}
	if (!check)
		best_match = max_value(stack);
	printf("bestmatch %d\n", best_match);
	return (best_match);
}

int		calculate_cost(t_node *stack_a, t_node *stack_b)
{
	
	int length;
	int index;
	int cost;
}

void	sort_number(t_stack *stack)
{
	int		cheapest;
	int		test;

	pb(stack);
	pb(stack);

	while (list_length(stack->a) >= 3)
	{
		// push to b using insertion sort
		test = find_match(stack->b, stack->a->num);
		cheapest = calculate_cost(stack->a, stack->b);
		printf("COST: %d\n", cheapest);
		print_stack(stack->a);
		print_stack(stack->b);
		pb(stack);
	}
	// sort stack a 3
	// move max from stack b to the top
	
	while (list_length(stack->b) > 0)
	{
		// push to a at the right spot
	}
	// move max from stack a to the top
}
