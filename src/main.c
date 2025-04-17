/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:22:29 by jowoundi          #+#    #+#             */
/*   Updated: 2025/04/17 11:35:38 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stack(t_node *stack)
{
	t_node *node;

	node = stack;
	while (node != NULL)
	{
		ft_printf("[%d] ", node->num);
		node = node->next;
	}
	ft_printf("\n");
}

int	main(int ac, char **av)
{
	t_stack	*stack;

	if (ac)
	{
		stack = insert_number(ac, av);
		sort_number(stack);
	}
	return (0);
}

// printf("stacks de depart\n");
// print_stack(stack->a);
// print_stack(stack->b);

// printf("push a\n");
// pa(stack);
// print_stack(stack->a);
// print_stack(stack->b);

// printf("push a\n");
// pa(stack);
// print_stack(stack->a);
// print_stack(stack->b);

// printf("swap\n");
// sa(stack);
// print_stack(stack->a);

// printf("swap\n");
// sb(stack);
// print_stack(stack->b);

// printf("rotate\n");
// ra(stack);
// print_stack(stack->a);

// printf("rotate\n");
// rb(stack);
// print_stack(stack->b);

// printf("reverse rotate\n");
// rra(stack);
// print_stack(stack->a);

// printf("reverse rotate\n");
// rrb(stack);
// print_stack(stack->b);

// printf("push b\n");
// pb(stack);
// print_stack(stack->a);
// print_stack(stack->b);

// printf("push b\n");
// pb(stack);
// print_stack(stack->a);
// print_stack(stack->b);