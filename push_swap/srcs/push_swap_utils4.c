/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 02:00:27 by lsaumon           #+#    #+#             */
/*   Updated: 2024/07/01 18:31:15 by lsaumon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	stack_len(t_stack *stack)
{
	int	count;

	if (stack == NULL)
		return (0);
	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

t_stack	*is_the_cheapest(t_stack *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	init_push_swap(t_stack *stack)
{
	stack->value = 0;
	stack->next = NULL;
}

int	add_args(t_stack **stack_a, char **argv)
{
	int		i;
	t_stack	*new_node;

	i = 1;
	while (argv[i])
	{
		new_node = ft_lstnew_push(ft_atoi(argv[i]));
		if (!new_node)
		{
			free_struct(*stack_a);
			return (1);
		}
		ft_lstadd_back_push(stack_a, new_node);
		i++;
	}
	return (0);
}

bool	stack_sorted(t_stack *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}
