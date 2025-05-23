/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jowoundi <jowoundi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:54:15 by jowoundi          #+#    #+#             */
/*   Updated: 2025/05/16 11:28:22 by jowoundi         ###   ########.fr       */
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

typedef struct s_stack
{
	t_node	*a;
	t_node	*b;

}		t_stack;

// void	print_stack(t_node *stack);
t_stack	*insert_number(int ac, char **av);
void	insert_node(t_node **stack, int num);
void	sort_number(t_stack *stack);
void	sort_three(t_node **stack);
int		value_to_a(t_node *src, t_node *dest);
int		find_index(t_node *stack, int value);
void	move_top(t_node **stack, int i, char *current);
void	check_stack(t_node **stack);
void	sort_till_five(int ac, char **av, t_stack **stack);
void	sort_till_five_quote(int ac, char **av, t_stack **stack);
t_stack	*insert_number_quote(int ac, char **av);
void	check_args(int ac, char **av);
void	check_args_quote(int ac, char **av);
void	sort_two(t_stack *stack);
void	sort_four(t_stack *stack);
void	verif_one(int ac, char **av, t_stack **stack);
void	free_double_p(char **tab);
void	free_stack(t_stack *stack);
void	free_all(t_stack *stack, char **tab);
void	parsing_error(char **tab, char *str);
void	sort_quote(char **av, t_stack **stack);
int		min_value(t_node *stack);
int		find_match(t_node *stack, int value);
int		road_to_top(t_node *stack, int i);
int		list_length(t_node *stack);
void	s(t_node **stack, char *current);
void	r(t_node **stack, char *current);
void	rr(t_node **stack, char *current);
void	rrr(t_stack *stack, char *current);
void	rrb(t_stack *stack, char *current);
void	p(t_node **src, t_node **dest, char *current);

#endif