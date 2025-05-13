/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_number_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:12:12 by jowoundi          #+#    #+#             */
/*   Updated: 2025/05/13 16:13:58 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		s(stack, "a");
		r(stack, "a");
	}
	else if (val1 > val2 && val2 < val3 && val1 < val3)
		s(stack, "a");
	else if (val1 < val2 && val2 > val3 && val1 > val3)
		rr(stack, "a");
	else if (val1 > val2 && val2 < val3 && val1 > val3)
		r(stack, "a");
	else if (val1 > val2 && val2 > val3)
	{
		s(stack, "a");
		rr(stack, "a");
	}
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
