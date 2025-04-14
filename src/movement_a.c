/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:53:15 by jowoundi          #+#    #+#             */
/*   Updated: 2025/04/14 16:23:07 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(t_stack *stacks)
{
	t_node *first;
	t_node *second;

	first = stacks->a->next;
	second = first->next;
	first->next = second->next;
	second->next = first;
	stacks->a->next = second;
}

void ra(t_stack *stacks)
{
	t_node *first;
	t_node *last;

	first = stacks->a->next;
	stacks->a->next = first->next;
	last = stacks->a->next;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
}

void rra(t_stack *stacks)
{
	t_node *prev;
	t_node *last;

	prev = NULL;
	last = stacks->a->next;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = stacks->a->next;
	stacks->a->next = last;
}

void	pa(t_stack *stacks)
{
	t_node	*temp;

	temp = stacks->b->next;
	stacks->b->next = stacks->b->next->next;
	
	temp->next = stacks->a->next;
	stacks->a->next = temp;
}
