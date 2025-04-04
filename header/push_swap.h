/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:54:15 by jowoundi          #+#    #+#             */
/*   Updated: 2025/04/03 18:50:46 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_data
{
	int				num;
	struct s_data	*next;
}		t_data;

typedef struct	s_stack
{
	t_data	a;
	t_data	b;
	
}		t_stack;

t_stack	insert_number(int ac, char **av);

#endif