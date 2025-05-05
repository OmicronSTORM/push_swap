/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_ab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:12:04 by jowoundi          #+#    #+#             */
/*   Updated: 2025/05/02 15:32:44 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

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
