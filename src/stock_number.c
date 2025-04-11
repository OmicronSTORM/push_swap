/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 18:52:06 by jowoundi          #+#    #+#             */
/*   Updated: 2025/04/09 17:03:15 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*insert_number(int ac, char **av)
{
	int		i;
	int		num;
	t_stack	*stack;
	t_node	*a;
	(void)ac;

	i = 1;
	stack = malloc(sizeof(t_stack));
	if (!stack)
		exit(1);
	a = malloc(sizeof(t_node));
	stack->a = a;
	while (i < ac)
	{
		num = ft_atoi(av[i]);
		insert_node(&a, num);
		i++;
	}
	//printList(stack->a);
	return (stack);
}
