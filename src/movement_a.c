/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:53:15 by jowoundi          #+#    #+#             */
/*   Updated: 2025/05/01 17:22:25 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s(t_node **stack)
{
	t_node	*first;
	t_node	*second;
	
	first = (*stack)->next;
	second = first->next;
	first->next = second->next;
	second->next = first;
	(*stack)->next = second;
}

void	r(t_node **stack)
{
	t_node	*first;
	t_node	*last;
	
	first = (*stack)->next;
	(*stack)->next = first->next;
	last = (*stack)->next;
	while (last->next)
	last = last->next;
	last->next = first;
	first->next = NULL;
}

void	rr(t_node **stack)
{
	t_node	*prev;
	t_node	*last;
	
	prev = NULL;
	last = (*stack)->next;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = (*stack)->next;
	(*stack)->next = last;
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
