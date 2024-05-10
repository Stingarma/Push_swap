/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:29:41 by lsaumon           #+#    #+#             */
/*   Updated: 2024/05/08 06:41:18 by lsaumon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_stack **a, int flag)
{
	t_stack	*temp;

	if (ft_lstsize_push(*a) < 2)
		return ;
	temp = *a;
	*a = ft_lstlast_push(*a);
	(*a)->next = temp;
	temp = *a;
	while (temp->next != *a)
		temp = temp->next;
	temp->next = NULL;
	if (flag)
		ft_printf("rra\n");
}

void	rrb(t_stack **b, int flag)
{
	t_stack	*temp;

	if (ft_lstsize_push(*b) < 2)
		return ;
	temp = *b;
	*b = ft_lstlast_push(*b);
	(*b)->next = temp;
	temp = *b;
	while (temp->next != *b)
		temp = temp->next;
	temp->next = NULL;
	if (flag)
		ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a, 0);
	rrb(b, 0);
	ft_printf("rrr\n");
}
