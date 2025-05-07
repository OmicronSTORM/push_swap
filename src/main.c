/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:22:29 by jowoundi          #+#    #+#             */
/*   Updated: 2025/05/07 19:15:55 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

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

int	check_tab(char **tab, int check)
{
	int	i;
	int	current;

	i = 0;
	while (tab[i])
	{
		current = ft_atoi(tab[i]);
		if (current == check)
			return (0);
		i++;
	}
	return (1);
}

void	repeat(int ac, char **av)
{
	char	**tab;
	int		check;
	int		i;

	i = 1;
	tab = malloc(sizeof(char *) * (ac - 1));
	while (ac > i)
	{
		check = ft_atoi(av[i]);
		if (check_tab(tab, check) == 1)
			tab[i - 1] = av[i];
		else
		{
			ft_printf("Error\n");
			free(tab);
			exit(1);
		}
		i++;
	}
}

void	check_args(int ac, char **av)
{
	repeat(ac, av);
}

void	sort_two(t_stack *stack)
{
	int	value1;
	int	value2;

	value1 = stack->a->num;
	value2 = stack->a->next->num;
	if (value1 > value2)
		s(&stack->a);
}

void	sort_till_five(int ac, char **av, t_stack *stack)
{
	if (ac == 2)
		return ;
	else if (ac == 3)
	{
		stack = insert_number(ac, av);
		sort_two(stack);
		print_stack(stack->a);
	}
	else if (ac == 4)
	{
		stack = insert_number(ac, av);
		sort_three(&stack->a);
		print_stack(stack->a);
	}
	else if (ac == 5)
	{
		stack = insert_number(ac, av);
		sort_four(stack);
	}
}

int	main(int ac, char **av)
{
	t_stack	*stack;

	if (ac > 1)
	{
		check_args(ac, av);
		stack = NULL;
		if (ac <= 5)
			sort_till_five(ac, av, stack);
		else
		{	
			stack = insert_number(ac, av);
			sort_number(stack);
		}
	}
	return (0);
}
