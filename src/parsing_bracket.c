/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bracket.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 14:49:25 by jowoundi          #+#    #+#             */
/*   Updated: 2025/05/10 15:35:24 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_tab_bracket(char **tab, int check)
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

void	char_check_bracket(char *str)
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

void	repeat_bracket(int ac, char **av)
{
	char	**tab;
	int		check;
	int		i;

	i = 0;
	tab = malloc(sizeof(char *) * (ac - 1));
	if (!tab)
		return ;
	while (ac > i)
	{
		check = ft_atoi(av[i]);
		if (check_tab_bracket(tab, check) == 1)
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

void	letter_bracket(int ac, char **av)
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
		char_check_bracket(av[i]);
		i++;
	}
}

void	check_args_bracket(int ac, char **av)
{
	repeat_bracket(ac, av);
	letter_bracket(ac, av);
}
