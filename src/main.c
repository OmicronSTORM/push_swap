/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:22:29 by jowoundi          #+#    #+#             */
/*   Updated: 2025/05/09 19:11:04 by jowoundi         ###   ########.fr       */
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

void	char_check(char	*str)
{
	int	i;

	i = 0;
	if (str[i] == '"')
	{
		// i = ft_strlen(str);		il faut check les guillemets
		// if (str[i] != '"')
		// {
		// 	ft_printf("Error\n");
		// 	exit(1);
		// }
	}
	i = 0;
	if ((str[i] != '-') && str[i] != '+' && ft_isdigit(str[i]) == 0)
	{
		ft_printf("Error\n");
		exit(1);
	}
	i++;
	while (i < (int)ft_strlen(str))
	{
		if (ft_isdigit(str[i]) == 0)
		{	
			ft_printf("Error\n");
			exit(1);
		}
		i++;
	}
}

void	letter(int ac, char **av)
{
	int		i;
	int		check;
	int		len;
	int		len2;
	char	*str;

	i = 1;
	while (ac > i)
	{
		len = ft_strlen(av[i]);
		check = ft_atoi(av[i]);
		str = ft_itoa(check);
		len2 = ft_strlen(str);
		char_check(av[i]);
		i++;
	}
}

void	check_args(int ac, char **av)
{
	repeat(ac, av);
	letter(ac, av);
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

void	sort_four(t_stack *stack)
{
	int	move_to_a;
	int	move_to_a_index;

	p(&stack->a, &stack->b);
	sort_three(&stack->a);
	move_to_a = value_to_a(stack->b, stack->a);
	move_to_a_index = find_index(stack->a, move_to_a);
	move_top(&stack->a, move_to_a_index);
	p(&stack->b, &stack->a);
	check_stack(&stack->a);
}

void	sort_bracket(char **av, t_stack **stack)
{
	char	**tab;
	int		i;

	if (!av || !av[1])
		return;
	i = 1;
	tab = ft_split(av[1], ' ');
	while (tab[i])
		i++;
	if (i > 0)
	{
		check_args(i, tab);
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

void	sort_till_five(int ac, char **av, t_stack **stack)
{
	if (ac == 2)
	{
		if (ft_strlen(av[1]) > 0)
			sort_bracket(av, stack);
		else
			return ;
	}
	else if (ac == 3)
	{
		*stack = insert_number(ac, av);
		sort_two(*stack);
	}
	else if (ac == 4)
	{
		*stack = insert_number(ac, av);
		sort_three(&(*stack)->a);
	}
	else if (ac == 5)
	{
		*stack = insert_number(ac, av);
		sort_four(*stack);
	}
}

int	main(int ac, char **av)
{
	t_stack	*stack;

	if (ac > 1)
	{
		stack = NULL;
		check_args(ac, av);
		if (ac <= 5)
			sort_till_five(ac, av, &stack);
		else
		{	
			stack = insert_number(ac, av);
			sort_number(stack);
		}
	}
	return (0);
}
