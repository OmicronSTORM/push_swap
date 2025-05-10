/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 15:09:22 by jowoundi          #+#    #+#             */
/*   Updated: 2025/05/10 15:10:59 by jowoundi         ###   ########.fr       */
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
