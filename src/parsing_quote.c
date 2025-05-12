/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_quote.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 14:49:25 by jowoundi          #+#    #+#             */
/*   Updated: 2025/05/12 15:40:54 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_tab_quote(char **tab, int check)
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

void	char_check_quote(char *str)
{
	int	i;

	i = 0;
	if (str[i] != '-' && str[i] != '+' && ft_isdigit(str[i]) == 0)
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

void	repeat_quote(int ac, char **av)
{
	char	**tab;
	int		check;
	int		i;

	i = 0;
	tab = ft_calloc(sizeof(char *), (ac));
	if (!tab)
		return ;
	while (av[i])
	{
		check = ft_atoi(av[i]);
		if (check_tab_quote(tab, check) == 1)
			tab[i] = av[i];
		else
		{
			ft_printf("Error\n");
			exit(1);
		}
		i++;
	}
	free(tab);
	tab = NULL;
}

void	letter_quote(int ac, char **av)
{
	int		i;
	int		check;
	int		len;
	int		len2;
	char	*str;

	i = 0;
	while (ac > i)
	{
		len = ft_strlen(av[i]);
		check = ft_atoi(av[i]);
		str = ft_itoa(check);
		len2 = ft_strlen(str);
		char_check_quote(av[i]);
		free(str);
		str = NULL;
		i++;
	}
}

void	sort_till_five_quote(int ac, char **av, t_stack **stack)
{
	if (ac == 1)
	{
		check_args_quote(ac, av);
		return ;
	}
	else if (ac == 2)
	{
		check_args_quote(ac, av);
		*stack = insert_number_quote(ac, av);
		sort_two(*stack);
	}
	else if (ac == 3)
	{
		check_args_quote(ac, av);
		*stack = insert_number_quote(ac, av);
		sort_three(&(*stack)->a);
	}
	else if (ac == 4)
	{
		check_args_quote(ac, av);
		*stack = insert_number_quote(ac, av);
		sort_four(*stack);
	}
}

void	check_args_quote(int ac, char **av)
{
	repeat_quote(ac, av);
	letter_quote(ac, av);
}
