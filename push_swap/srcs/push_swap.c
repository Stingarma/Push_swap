/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 03:20:18 by lsaumon           #+#    #+#             */
/*   Updated: 2024/07/01 18:29:42 by lsaumon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rotate_all(t_stack **stack_a, t_stack **stack_b, t_stack *cheap)
{
	while (*stack_a != cheap->target && *stack_b != cheap)
		rr(stack_a, stack_b);
	set_current_position(*stack_a);
	set_current_position(*stack_b);
}

static void	reverse_rotate_all(t_stack **stack_a, t_stack **stack_b,
		t_stack *cheap)
{
	while (*stack_a != cheap->target && *stack_b != cheap)
		rrr(stack_a, stack_b);
	set_current_position(*stack_a);
	set_current_position(*stack_b);
}

void	finish_rot(t_stack **stack, t_stack *top, char stack_name)
{
	while (*stack != top)
	{
		if (stack_name == 'a')
		{
			if (top->above_median)
				ra(stack, 1);
			else
				rra(stack, 1);
		}
		else if (stack_name == 'b')
		{
			if (top->above_median)
				rb(stack, 1);
			else
				rrb(stack, 1);
		}
	}
}

static void	move_a_node(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheap;

	cheap = is_the_cheapest(*stack_b);
	if (cheap->above_median && cheap->target->above_median)
		rotate_all(stack_a, stack_b, cheap);
	else if (!(cheap->above_median) && !(cheap->target->above_median))
		reverse_rotate_all(stack_a, stack_b, cheap);
	finish_rot(stack_b, cheap, 'b');
	finish_rot(stack_a, cheap->target, 'a');
	pa(stack_a, stack_b);
}

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*smallest;
	int		len_a;

	len_a = stack_len(*stack_a);
	while (len_a-- > 3)
		pb(stack_a, stack_b);
	tiny_sort(stack_a);
	while (*stack_b)
	{
		init_nodes(*stack_a, *stack_b);
		move_a_node(stack_a, stack_b);
	}
	set_current_position(*stack_a);
	smallest = find_small(*stack_a);
	if (smallest->above_median)
		while (*stack_a != smallest)
			ra(stack_a, 1);
	else
		while (*stack_a != smallest)
			rra(stack_a, 1);
}
