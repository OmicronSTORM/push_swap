/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_number.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:13:03 by jowoundi          #+#    #+#             */
/*   Updated: 2025/05/10 15:25:46 by jowoundi         ###   ########.fr       */
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

int	list_length(t_node *stack)
{
	int		i;
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

int	find_match(t_node *stack, int value)
{
	int		best_match;
	int		check;
	t_node	*runner;

	best_match = 0;
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
	return (best_match);
}

void	check_stack(t_node **stack)
{
	t_node	*runner;
	int		i;
	int		min_value;

	i = 0;
	runner = *stack;
	min_value = runner->num;
	while (runner)
	{
		if (min_value > runner->num)
			min_value = runner->num;
		runner = runner->next;
	}
	move_top(stack, find_index(*stack, min_value), "a");
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
