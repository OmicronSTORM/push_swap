/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:22:29 by jowoundi          #+#    #+#             */
/*   Updated: 2025/05/10 15:37:20 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

// void print_stack(t_node *stack)
// {
// 	t_node *node;

// 	node = stack;
// 	while (node != NULL)
// 	{
// 		ft_printf("[%d] ", node->num);
// 		node = node->next;
// 	}
// 	ft_printf("\n");
// }

void	sort_bracket(char **av, t_stack **stack)
{
	char	**tab;
	int		i;

	if (!av || !av[1])
		return ;
	i = 1;
	tab = ft_split(av[1], ' ');
	if (!tab)
		return ;
	while (tab[i])
		i++;
	if (i > 0)
	{
		check_args_bracket(i, tab);
		if (i <= 5)
			sort_till_five(i, tab, stack);
		else
		{
			*stack = insert_number_bracket(i, tab);
			sort_number(*stack);
		}
	}
	else
		return ;
}

int	main(int ac, char **av)
{
	t_stack	*stack;

	if (ac > 1)
	{
		stack = NULL;
		if (ac <= 5)
			sort_till_five(ac, av, &stack);
		else
		{
			check_args(ac, av);
			stack = insert_number(ac, av);
			sort_number(stack);
		}
		free(stack);
	}
	return (0);
}
