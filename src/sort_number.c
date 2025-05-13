/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_number.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:13:03 by jowoundi          #+#    #+#             */
/*   Updated: 2025/05/13 16:24:02 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	find_index(t_node *stack, int value)
{
	int		index;
	t_node	*runner;

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

int	value_to_a(t_node *src, t_node *dest)
{
	t_node	*runner;
	int		match;
	int		check;

	check = 0;
	runner = dest;
	while (runner)
	{
		if (runner->num > src->num)
		{
			if (!check || runner->num < match)
			{
				match = runner->num;
				check = 1;
			}
		}
		runner = runner->next;
	}
	if (!check)
		match = min_value(dest);
	return (match);
}

int	calculate_cheapest(int cheapest, t_node *stack_a, t_node *stack_b, int cost)
{
	t_node	*runner;
	int		match_index;
	int		cheapest_cost;

	runner = stack_a;
	if (runner)
	{
		cheapest = runner->num;
		match_index = find_index(stack_b, find_match(stack_b, runner->num));
		cheapest_cost = road_to_top(stack_a, find_index(stack_a, runner->num))
			+ road_to_top(stack_b, match_index);
	}
	while (runner)
	{
		match_index = find_index(stack_b, find_match(stack_b, runner->num));
		cost = road_to_top(stack_a, find_index(stack_a, runner->num))
			+ road_to_top(stack_b, match_index);
		if (cost < cheapest_cost)
		{
			cheapest_cost = cost;
			cheapest = runner->num;
		}
		runner = runner->next;
	}
	return (cheapest);
}

int	calculate_cost(t_node *stack_a, t_node *stack_b)
{
	int		cheapest;
	int		cost;

	cost = 0;
	cheapest = 0;
	cheapest = calculate_cheapest(cheapest, stack_a, stack_b, cost);
	return (cheapest);
}

void	sort_number(t_stack *stack)
{
	int	cheapest;
	int	index;
	int	move_to_a;
	int	move_to_a_index;

	p(&stack->a, &stack->b, "b");
	p(&stack->a, &stack->b, "b");
	while (list_length(stack->a) > 3)
	{
		cheapest = calculate_cost(stack->a, stack->b);
		index = find_index(stack->a, cheapest);
		move_top(&stack->a, index, "a");
		move_top(&stack->b, find_index(stack->b,
				find_match(stack->b, cheapest)), "b");
		p(&stack->a, &stack->b, "b");
	}
	sort_three(&stack->a);
	while (list_length(stack->b) > 0)
	{
		move_to_a = value_to_a(stack->b, stack->a);
		move_to_a_index = find_index(stack->a, move_to_a);
		move_top(&stack->a, move_to_a_index, "a");
		p(&stack->b, &stack->a, "a");
	}
	check_stack(&stack->a);
}
