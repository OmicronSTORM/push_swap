/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 22:02:59 by jowoundi          #+#    #+#             */
/*   Updated: 2025/05/13 16:05:03 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_stack *stack, char **tab)
{
	free_stack(stack);
	free_double_p(tab);
}

void	free_stack(t_stack *stack)
{
	void	*temp;

	if (!stack)
		return ;
	while (stack->a)
	{
		temp = stack->a->next;
		free(stack->a);
		stack->a = temp;
	}
	free(stack);
}

void	free_double_p(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
}
