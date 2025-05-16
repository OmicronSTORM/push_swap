/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_quote.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 14:49:25 by jowoundi          #+#    #+#             */
/*   Updated: 2025/05/16 11:29:16 by jowoundi         ###   ########.fr       */
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

int	char_check_quote(char *str)
{
	int	i;

	i = 0;
	if (str[i] != '-' && str[i] != '+' && ft_isdigit(str[i]) == 0)
		return (1);
	i++;
	while (i < (int)ft_strlen(str))
	{
		if (ft_isdigit(str[i]) == 0)
			return (1);
		i++;
	}
	return (0);
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
			write(2, "Error\n", 6);
			free(tab);
			free_double_p(av);
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

	i = -1;
	while (ac > ++i)
	{
		len = ft_strlen(av[i]);
		check = ft_atoi(av[i]);
		str = ft_itoa(check);
		if (!str)
		{
			free_double_p(av);
			exit (1);
		}
		len2 = ft_strlen(str);
		if (char_check_quote(av[i]) == 1)
			parsing_error(av, str);
		free(str);
		str = NULL;
	}
}

void	check_args_quote(int ac, char **av)
{
	int	length;
	int	i;

	i = 0;
	length = -1;
	repeat_quote(ac, av);
	letter_quote(ac, av);
	while (av[i])
	{
		i++;
		length++;
	}
	i = 0;
	while (av[i] && av[i + 1] && ft_atoi(av[i]) < ft_atoi(av[i + 1]))
		i++;
	if (i == length)
	{
		free_double_p(av);
		exit (1);
	}
}
