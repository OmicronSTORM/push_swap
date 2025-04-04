/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 17:08:53 by jowoundi          #+#    #+#             */
/*   Updated: 2025/04/03 18:31:47 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	*createNode(int	num)
{
	t_data	*newNode = malloc(sizeof(t_data));
	if (!newNode)
		exit(1);
	newNode->num = num;
	newNode->next = NULL;
	return (newNode);
}

