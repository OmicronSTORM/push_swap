/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 12:58:05 by jowoundi          #+#    #+#             */
/*   Updated: 2025/05/13 15:45:26 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	char_check(char	*str)
{
	int	i;

	i = 0;
	if (str[i] != '-' && str[i] != '+' && ft_isdigit(str[i]) == 0)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	i++;
	while (i < (int)ft_strlen(str))
	{
		if (ft_isdigit(str[i]) == 0)
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		i++;
	}
}

void	repeat(int ac, char **av)
{
	char	**tab;
	int		check;
	int		i;

	i = 1;
	tab = ft_calloc(sizeof(char *), (ac));
	if (!tab)
		return ;
	while (av[i])
	{
		check = ft_atoi(av[i]);
		if (check_tab(tab, check) == 1)
			tab[i - 1] = av[i];
		else
		{
			write(2, "Error\n", 6);
			free(tab);
			exit(1);
		}
		i++;
	}
	free(tab);
	tab = NULL;
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
		free(str);
		str = NULL;
		char_check(av[i]);
		i++;
	}
}

void	check_args(int ac, char **av)
{
	int	length;
	int	i;

	i = 1;
	length = 0;
	repeat(ac, av);
	letter(ac, av);
	while (av[i])
	{
		i++;
		length++;
	}
	i = 0;
	while (av[i] && av[i + 1] && ft_atoi(av[i]) < ft_atoi(av[i + 1]))
		i++;
	if (i == length)
		exit (1);
}
