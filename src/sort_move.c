/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:14:14 by jowoundi          #+#    #+#             */
/*   Updated: 2025/05/13 16:18:25 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_top(t_node **stack, int i, char *current)
{
	int	length;

	length = list_length(*stack);
	if (i > length / 2)
	{
		while (i < length)
		{
			rr(stack, current);
			i++;
		}
	}
	else
	{
		while (i > 0)
		{
			r(stack, current);
			i--;
		}
	}
}

int	road_to_top(t_node *stack, int i)
{
	int	length;
	int	move;

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
