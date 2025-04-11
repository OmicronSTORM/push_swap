/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:54:15 by jowoundi          #+#    #+#             */
/*   Updated: 2025/04/10 16:01:31 by jowoundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>

typedef struct s_node
{
	int				num;
	struct s_node	*next;
}		t_node;

typedef struct	s_stack
{
	t_node	*a;
	t_node	*b;
	
}		t_stack;

t_stack	*insert_number(int ac, char **av);
void	insert_node(t_node **stack, int num);
void	swap(t_stack *stack);
void	rotate(t_stack *stacks);
void	reverse_rotate(t_stack *stacks);
void	push_a(t_stack *stacks);
void	push_b(t_stack *stacks);

#endif