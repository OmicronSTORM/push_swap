/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_till_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 14:59:00 by jowoundi          #+#    #+#             */
/*   Updated: 2025/05/10 15:00:47 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *stack)
{
	int	value1;
	int	value2;

	value1 = stack->a->num;
	value2 = stack->a->next->num;
	if (value1 > value2)
		s(&stack->a, "a");
}

void	sort_four(t_stack *stack)
{
	int	move_to_a;
	int	move_to_a_index;

	p(&stack->a, &stack->b, "b");
	sort_three(&stack->a);
	move_to_a = value_to_a(stack->b, stack->a);
	move_to_a_index = find_index(stack->a, move_to_a);
	move_top(&stack->a, move_to_a_index, "a");
	p(&stack->b, &stack->a, "a");
	check_stack(&stack->a);
}

void	verif_one(int ac, char **av, t_stack **stack)
{
	if (ft_strlen(av[1]) > 0)
		sort_bracket(av, stack);
	else
	{
		check_args_bracket(ac, av);
		return ;
	}
}

void	sort_till_five(int ac, char **av, t_stack **stack)
{
	if (ac == 2)
		verif_one(ac, av, stack);
	else if (ac == 3)
	{
		check_args(ac, av);
		*stack = insert_number(ac, av);
		sort_two(*stack);
	}
	else if (ac == 4)
	{
		check_args(ac, av);
		*stack = insert_number(ac, av);
		sort_three(&(*stack)->a);
	}
	else if (ac == 5)
	{
		check_args(ac, av);
		*stack = insert_number(ac, av);
		sort_four(*stack);
	}
}