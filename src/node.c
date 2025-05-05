/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 17:08:53 by jowoundi          #+#    #+#             */
/*   Updated: 2025/05/02 15:32:44 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

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
	t_node	*temp;

	new_node = create_node(num);
	if (!*stack)
	{
		*stack = new_node;
		return ;
	}
	temp = *stack;
	while (temp->next)
		temp = temp->next;
	temp->next = new_node;
}
