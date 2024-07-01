/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_my_nodes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 18:58:51 by lsaumon           #+#    #+#             */
/*   Updated: 2024/07/01 18:32:16 by lsaumon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	set_target(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*current_a;
	t_stack	*target_node;
	long	match_index;

	while (stack_b)
	{
		match_index = LONG_MAX;
		current_a = stack_a;
		while (current_a)
		{
			if (current_a->value > stack_b->value
				&& current_a->value < match_index)
			{
				match_index = current_a->value;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (LONG_MAX == match_index)
			stack_b->target = find_min(&stack_a);
		else
			stack_b->target = target_node;
		stack_b = stack_b->next;
	}
}

void	set_price(t_stack *stack_a, t_stack *stack_b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(stack_a);
	len_b = stack_len(stack_b);
	while (stack_b)
	{
		stack_b->push_price = stack_b->current_position;
		if (!(stack_b->above_median))
			stack_b->push_price = len_b - (stack_b->current_position);
		if (stack_b->target->above_median)
			stack_b->push_price += stack_b->target->current_position;
		else
			stack_b->push_price += len_a - (stack_b->target->current_position);
		stack_b = stack_b->next;
	}
}

void	set_current_position(t_stack *stack)
{
	int	i;
	int	centerline;

	i = 0;
	if (stack == NULL)
		return ;
	centerline = stack_len(stack) / 2;
	while (stack)
	{
		stack->current_position = i;
		if (i <= centerline)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

void	set_cheapest(t_stack *stack_b)
{
	long	best_match_value;
	t_stack	*best_match;

	if (stack_b == NULL)
		return ;
	best_match_value = LONG_MAX;
	while (stack_b)
	{
		if (stack_b->push_price < best_match_value)
		{
			best_match_value = stack_b->push_price;
			best_match = stack_b;
		}
		stack_b = stack_b->next;
	}
	best_match->cheapest = true;
}

void	init_nodes(t_stack *stack_a, t_stack *stack_b)
{
	set_current_position(stack_a);
	set_current_position(stack_b);
	set_target(stack_a, stack_b);
	set_price(stack_a, stack_b);
	set_cheapest(stack_b);
}
