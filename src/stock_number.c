/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 18:52:06 by jowoundi          #+#    #+#             */
/*   Updated: 2025/04/04 16:15:16 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	ft_get_number(char *src, t_stack *stack)
{
	int	number;

	(void)stack;
	number = ft_atoi(src);
	printf("%d\n", number);
	return (stack->a);
}

t_stack	insert_number(int ac, char **av)
{
	int		i;
	t_stack	stack;

	i = 0;
	while (i <= ac)
	{
		stack.a = ft_get_number(av[i], &stack);
	}
	return (stack);
}
