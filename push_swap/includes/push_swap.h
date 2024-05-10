/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 00:37:34 by lsaumon           #+#    #+#             */
/*   Updated: 2024/05/08 06:39:47 by lsaumon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}					t_stack;

void	sa(t_stack *a, int flag);
void	sb(t_stack *b, int flag);
void	ss(t_stack*a, t_stack *b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a, int flag);
void	rb(t_stack **b, int flag);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a, int flag);
void	rrb(t_stack **b, int flag);
void	rrr(t_stack **a, t_stack **b);
int		ft_atol(const char *nptr);
int		check_number(char *string);
int		check_double(char **argv);
int		parsing(int argc, char **argv);
void	add_arg(t_stack *stack, char **argv);
void	init_pushswap(t_stack *stack);
void	free_struct(t_stack *stack);

t_stack	*ft_lstnew_push(int value);
void	ft_lstadd_front_push(t_stack **lst, t_stack *new);
int		ft_lstsize_push(t_stack *lst);
t_stack	*ft_lstlast_push(t_stack *lst);
void	ft_lstadd_back_push(t_stack **lst, t_stack *new);


#endif