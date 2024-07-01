/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 03:13:14 by lsaumon           #+#    #+#             */
/*   Updated: 2024/07/01 18:32:09 by lsaumon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*find_small(t_stack *stack)
{
	long	small;
	t_stack	*smallest;

	if (stack == NULL)
		return (NULL);
	small = LONG_MAX;
	while (stack)
	{
		if (stack->value < small)
		{
			small = stack->value;
			smallest = stack;
		}
		stack = stack->next;
	}
	return (smallest);
}

t_stack	*find_min(t_stack **stack_a)
{
	t_stack	*min;
	t_stack	*temp;

	min = *stack_a;
	temp = *stack_a;
	while (temp)
	{
		if (temp->value < min->value)
			min = temp;
		temp = temp->next;
	}
	return (min);
}

t_stack	*find_max(t_stack **stack_a)
{
	t_stack	*max;
	t_stack	*temp;

	max = *stack_a;
	temp = *stack_a;
	while (temp)
	{
		if (temp->value > max->value)
			max = temp;
		temp = temp->next;
	}
	return (max);
}

void	tiny_sort(t_stack **stack_a)
{
	t_stack	*highest;

	highest = find_max(stack_a);
	if (*stack_a && (*stack_a)->next == NULL)
		return ;
	if (*stack_a == highest)
		ra(stack_a, 1);
	else if ((*stack_a)->next == highest)
		rra(stack_a, 1);
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(*stack_a, 1);
}
