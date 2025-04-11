/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 17:08:53 by jowoundi          #+#    #+#             */
/*   Updated: 2025/04/09 15:47:49 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int num)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		exit(1);
	new_node->num = num;
	new_node->next = NULL;
	return (new_node);
}

void	insert_node(t_node **stack, int num)
{
	t_node	*new_node;
	
	new_node = create_node(num);
	if (!stack || !*stack)
	{
		*stack = new_node;
		return ;
	}
	while ((*stack)->next)
		(*stack) = (*stack)->next;
	(*stack)->next = new_node;
}
