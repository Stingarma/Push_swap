/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 21:18:09 by lsaumon           #+#    #+#             */
/*   Updated: 2024/03/16 15:13:12 by lsaumon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_stack *a, int flag)
{
	int	temp;

	if (ft_lstsize(a) < 2)
		return ;
	temp = a->value;
	a->value = a->next->value;
	a->next->value = temp;
	if (flag)
		ft_printf("sa\n");
}

void	sb(t_stack *b, int flag)
{
	int	temp;

	if (ft_lstsize(b) < 2)
		return ;
	temp = b->value;
	b->value = b->next->value;
	b->next->value = temp;
	if (flag)
		ft_printf("sb\n");
}

void	ss(t_stack *a, t_stack *b)
{
	
	sa(a, 0);
	sb(b, 0);
	ft_printf("ss\n");
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (ft_lstsize(*b) < 1)
		return ;
	temp = *b;
	*b = (*b)->next;
	ft_lstadd_front(a, temp);
	*a = temp;
	ft_printf("pa\n");
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (ft_lstsize(*a) < 1)
		return ;
	temp = *a;
	*a = (*a)->next;
	ft_lstadd_front(b, temp);
	*b = temp;
	ft_printf("pb\n");
}
