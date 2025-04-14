/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_number.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:13:03 by jowoundi          #+#    #+#             */
/*   Updated: 2025/04/14 17:31:35 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	list_lenght(t_node *stack)
{
	int	i;
	t_node	*node;

	i = 0;
	node = stack;
	while (node->next)
	{
		node = node->next;
		i++;
	}
	return (i);
}

void	ft_order(t_stack *stack)
{
	t_node	*node;
	int		lenght;

	lenght = list_lenght(stack->b);
	node = stack->b;
	if (node->next->num < node->next->next->num)
	{
		rb(stack);
	}
}

void	check_stack_b(t_stack *stack)
{
	int	lenght;
	
	lenght = list_lenght(stack->b);
	if (lenght < 2)
		return ;
	printf("Avant order\n");
	print_stack(stack->b);
	ft_order(stack);
	printf("apres order\n");
	print_stack(stack->b);
}

void	sort_number(t_stack *stack)
{
	while (stack->a->next)
	{
		pb(stack);
		check_stack_b(stack);
	}
}