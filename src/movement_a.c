/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:53:15 by jowoundi          #+#    #+#             */
/*   Updated: 2025/05/06 12:24:56 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	s(t_node **stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || !*stack || !(*stack)->next)
		return;
	first = (*stack);
	second = first->next;
	if (!second)
		return;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	r(t_node **stack)
{
	t_node	*first;
	t_node	*last;
	
	first = *stack;
	last = *stack;
	(*stack)->next = first->next;
	while (last->next)
		last = last->next;
	*stack = first->next;
	last->next = first;
	first->next = NULL;
}

void rr(t_node **stack)
{
	t_node *prev;
	t_node *last;
	
	prev = NULL;
	last = *stack;
	if (!stack || !*stack || !(*stack)->next)
		return;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	p(t_node **src, t_node **dest)
{
	t_node *temp;
	
	if (!src)
	return ;
	temp = *src;
	*src = (*src)->next;
	temp->next = *dest;
	*dest = temp;
}
