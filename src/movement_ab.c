/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_ab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:12:04 by jowoundi          #+#    #+#             */
/*   Updated: 2025/04/30 19:02:52 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack *stack)
{
	s(&stack->a);
	s(&stack->b);
}

void	rrb(t_stack *stack)
{
	r(&stack->a);
	r(&stack->b);
}

void	rrr(t_stack *stack)
{
	rr(&stack->a);
	rr(&stack->b);
}
