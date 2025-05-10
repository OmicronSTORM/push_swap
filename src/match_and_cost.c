/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match_and_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 15:12:50 by jowoundi          #+#    #+#             */
/*   Updated: 2025/05/10 15:23:52 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calc_utlis(t_node *stack_a, t_node *stack_b, int cheapest, int cost)
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
	int	cheapest;
	int	cost;

	cost = 0;
	cheapest = 0;
	cheapest = calc_utlis(stack_a, stack_b, cheapest, cost);
	return (cheapest);
}
