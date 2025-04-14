/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 13:58:49 by jowoundi          #+#    #+#             */
/*   Updated: 2025/04/14 16:22:57 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sb(t_stack *stacks)
{
	t_node *first;
	t_node *second;

	first = stacks->b->next;
	second = first->next;
	first->next = second->next;
	second->next = first;
	stacks->b->next = second;
}

void rb(t_stack *stacks)
{
	t_node *first;
	t_node *last;

	first = stacks->b->next;
	stacks->b->next = first->next;
	last = stacks->b->next;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
}

void rrb(t_stack *stacks)
{
	t_node *prev;
	t_node *last;

	prev = NULL;
	last = stacks->b->next;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = stacks->b->next;
	stacks->b->next = last;
}

void	pb(t_stack *stacks)
{
	t_node *temp;

	temp = stacks->a->next;
	stacks->a->next = stacks->a->next->next;

	temp->next = stacks->b->next;
	stacks->b->next = temp;
}