/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_number.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:13:03 by jowoundi          #+#    #+#             */
/*   Updated: 2025/04/15 18:25:07 by jowoundi         ###   ########.fr       */
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

void	check_target(int target_a, t_node *sb)
{
	if (sb->num > target_a)
		return ;
	else
		target_a = sb->num;
}

void	define_target(t_node *cur_node,t_stack *stack)
{
	t_stack	*node;

	node = stack;
	cur_node->target = 0;
	printf("avant la boucle de define_target\n");
	while(node->b->next)
	{
		printf("on entre dans la boucle\n");
		if (stack->b->num < cur_node->num)
		{
			printf("avant check_target\n");
			check_target(cur_node->target, stack->b);
			printf("apres check_target\n");
			node->b = node->b->next;
		}
		node->b = node->b->next;
	}
	printf("apres la boucle de define_target\n");
}

void	target_number(t_stack *stack)
{
	t_stack	*node;

	node = stack;
	printf("avant la boucle de target_number\n");
	while (node->a->next)
	{
		printf("on est dans la boucle de target_number\n");
		printf("avant define_target\n");
		define_target(stack->a, stack);
		printf("apres define_target\n");
		node->a = node->a->next;
	}
	printf("on est sorti de la boucle de target_number\n");
}

void	check_stack(t_stack *stack)
{
	printf("avant target_number\n");
	target_number(stack);
	printf("apres target number\n");
}

void	sort_number(t_stack *stack)
{
	int	i;
	int	lenght;

	i = -1;
	lenght = list_lenght(stack->a);
	printf("LENGHT: %d\n", lenght);
	printf("avant boucle sort number\n");
	while (++i <= (lenght - 3))
	{
		printf("on est dans la boucle de sort number\n");
		if (i < 2)
			pb(stack);
		else
		{
			printf("Avant check_stack\n");
			check_stack(stack);
			printf("apres check_stack\n");
		}
		printf("fin de la boucle de sort number\n");
	}
}
