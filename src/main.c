/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:22:29 by jowoundi          #+#    #+#             */
/*   Updated: 2025/05/16 11:31:55 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../header/push_swap.h"

// void	print_stack(t_node *stack)
// {
// 	t_node	*node;

// 	node = stack;
// 	while (node != NULL)
// 	{
// 		ft_printf("[%d] ", node->num);
// 		node = node->next;
// 	}
// 	ft_printf("\n");
// }

void	sort_quote(char **av, t_stack **stack)
{
	char	**tab;
	int		i;

	if (!av || !av[1])
		return ;
	i = 0;
	tab = ft_split(av[1], ' ');
	if (!tab)
		exit (1);
	while (tab[i])
		i++;
	if (i > 0)
	{
		check_args_quote(i, tab);
		if (i < 5)
			sort_till_five_quote(i, tab, stack);
		else
		{
			*stack = insert_number_quote(i, tab);
			sort_number(*stack);
			free_all(*stack, tab);
		}
	}
}

void	sort_till_five_quote(int ac, char **av, t_stack **stack)
{
	if (ac == 1)
		check_args_quote(ac, av);
	else if (ac == 2)
	{
		check_args_quote(ac, av);
		*stack = insert_number_quote(ac, av);
		sort_two(*stack);
		free_all(*stack, av);
	}
	else if (ac == 3)
	{
		check_args_quote(ac, av);
		*stack = insert_number_quote(ac, av);
		sort_three(&(*stack)->a);
		free_all(*stack, av);
	}
	else if (ac == 4)
	{
		check_args_quote(ac, av);
		*stack = insert_number_quote(ac, av);
		sort_four(*stack);
		free_all(*stack, av);
	}
}

int	main(int ac, char **av)
{
	t_stack	*stack;

	if (ac > 1)
	{
		stack = NULL;
		if (ac <= 5)
		{
			sort_till_five(ac, av, &stack);
		}
		else
		{
			check_args(ac, av);
			stack = insert_number(ac, av);
			sort_number(stack);
			free_stack(stack);
		}
	}
	return (0);
}
