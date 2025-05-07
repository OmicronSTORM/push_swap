/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_number.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:13:03 by jowoundi          #+#    #+#             */
/*   Updated: 2025/05/06 18:44:33 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

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

int	min_value(t_node *stack)
{
	t_node	*runner;
	int		min_value;

	min_value = stack->num;
	runner = stack->next;
	while (runner)
	{
		if (min_value > runner->num)
			min_value = runner->num;
		runner = runner->next;
	}
	return (min_value);
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
int	road_to_top(t_node *stack, int i)
{
	int	length;
	int move;

	move = 0;
	length = list_length(stack);
	if (i > length / 2)
	{
		while (i < length)
		{
			move++;
			i++;
		}
	}
	else
	{
		while (i > 0)
		{
			move++;
			i--;
		}
	}
	return (move);
}

void	move_top(t_node **stack, int i)
{
	int	length;

	length = list_length(*stack);
	if (i > length / 2)
	{
		while (i < length)
		{
			rr(stack);
			i++;
		}
	}
	else
	{
		while (i > 0)
		{
			r(stack);
			i--;
		}
	}
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

int		calculate_cost(t_node *stack_a, t_node *stack_b)
{
	t_node	*runner;
	int cheapest;
	int	cheapest_cost;
	int match_index;
	int cost;
	
	runner = stack_a;
	if (runner)
	{
		cheapest = runner->num;
		match_index = find_index(stack_b, find_match(stack_b, runner->num));
		cheapest_cost = road_to_top(stack_a, find_index(stack_a, runner->num)) + road_to_top(stack_b, match_index);
	}
	while (runner)
	{
		match_index = find_index(stack_b, find_match(stack_b, runner->num));
		cost = road_to_top(stack_a, find_index(stack_a ,runner->num)) + road_to_top(stack_b, match_index);
		if (cost < cheapest_cost)
		{
			cheapest_cost = cost;
			cheapest = runner->num;
		}
		runner = runner->next;
	}
	return (cheapest);
}

void	sort_three(t_node **stack)
{
	int	val1;
	int	val2;
	int	val3;

	val1 = (*stack)->num;
	val2 = (*stack)->next->num;
	val3 = (*stack)->next->next->num;
	if (val1 < val2 && val2 < val3)
		return ;
	else if (val1 < val2 && val2 > val3 && val1 < val3)
	{
		s(stack);
		r(stack);
	}
	else if (val1 > val2 && val2 < val3 && val1 < val3)
		s(stack);
	else if (val1 < val2 && val2 > val3 && val1 > val3)
		rr(stack);
	else if (val1 > val2 && val2 < val3 && val1 > val3)
		r(stack);
	else if (val1 > val2 && val2 > val3)
	{
		s(stack);
		rr(stack);
	}
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
	move_top(stack, find_index(*stack, min_value));
}

void	sort_number(t_stack *stack)
{
	int	cheapest;
	int	index;
	int	move_to_a;
	int	move_to_a_index;

	p(&stack->a, &stack->b);
	p(&stack->a, &stack->b);
	while (list_length(stack->a) > 3)
	{
		cheapest = calculate_cost(stack->a, stack->b);
		index = find_index(stack->a, cheapest);
		move_top(&stack->a, index);
		move_top(&stack->b, find_index(stack->b, find_match(stack->b, cheapest)));
		p(&stack->a, &stack->b);
	}
	sort_three(&stack->a);
	while (list_length(stack->b) > 0)
	{
		move_to_a = value_to_a(stack->b, stack->a);
		move_to_a_index = find_index(stack->a, move_to_a);
		move_top(&stack->a, move_to_a_index);
		 p(&stack->b, &stack->a);
	}
	check_stack(&stack->a);
	print_stack(stack->a);
}
