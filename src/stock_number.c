/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 18:52:06 by jowoundi          #+#    #+#             */
/*   Updated: 2025/05/06 12:43:04 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

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
		insert_node(&stack->a, num);
		i++;
	}
	return (stack);
}
