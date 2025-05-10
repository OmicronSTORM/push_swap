/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 18:52:06 by jowoundi          #+#    #+#             */
/*   Updated: 2025/05/10 14:01:49 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

t_stack	*insert_number_bracket(int ac, char **av)
{
	int		i;
	int		num;
	t_stack	*stack;

	i = 0;
	stack = malloc(sizeof(t_stack));
	if (!stack)
		exit(1);
	stack->a = NULL;
	stack->b = NULL;
	while (i < ac)
	{
		num = ft_atoi(av[i]);
		insert_node(&stack->a, num);
		i++;
	}
	return (stack);
}

t_stack	*insert_number(int ac, char **av)
{
	int		i;
	int		num;
	t_stack	*stack;

	i = 1;
	stack = malloc(sizeof(t_stack));
	if (!stack)
		exit(1);
	stack->a = NULL;
	stack->b = NULL;
	while (i < ac)
	{
		num = ft_atoi(av[i]);
		if (num > 2147483647 || num < -2147483648)
		{
			free(stack);
			ft_printf("Error\n");
			exit (1);
		}
		insert_node(&stack->a, num);
		i++;
	}
	return (stack);
}
