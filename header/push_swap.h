/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:54:15 by jowoundi          #+#    #+#             */
/*   Updated: 2025/04/11 14:18:35 by jowoundi         ###   ########.fr       */
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
void	sa(t_stack *stack);
void	ra(t_stack *stacks);
void	rra(t_stack *stacks);
void	pa(t_stack *stacks);
void	sb(t_stack *stack);
void	rb(t_stack *stacks);
void	rrb(t_stack *stacks);
void	pb(t_stack *stacks);
void	ss(t_stack *stack);
void	rr(t_stack *stack);
void	rrr(t_stack *stack);

#endif