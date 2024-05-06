/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 15:49:27 by lsaumon           #+#    #+#             */
/*   Updated: 2024/03/16 15:15:19 by lsaumon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_stack **a, int flag)
{
	t_stack	*temp;

	if (ft_lstsize(*a) < 2)
		return ;
	temp = *a;
	*a = (*a)->next;
	ft_lstadd_back(a, temp);
	temp->next = NULL;
	if (flag)
		ft_printf("ra\n");
}

void	rb(t_stack **b, int flag)
{
	t_stack	*temp;

	if (ft_lstsize(*b) < 2)
		return ;
	temp = *b;
	*b = (*b)->next;
	ft_lstadd_back(b, temp);
	temp->next = NULL;
	if (flag)
		ft_printf("rb\n");
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a, 0);
	rb(b, 0);
	ft_printf("rr\n");
}
