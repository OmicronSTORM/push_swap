/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 15:24:21 by jowoundi          #+#    #+#             */
/*   Updated: 2025/05/10 15:25:51 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
