/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 07:10:33 by lsaumon           #+#    #+#             */
/*   Updated: 2024/05/08 06:41:47 by lsaumon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_pushswap(t_stack *stack)
{
	stack->value = 0;
	stack->next = NULL;
}

void	add_arg(t_stack *stack, char **argv)
{
	int	i;
	int	value;

	i = 1;
	while (argv[i])
	{
		value = ft_atoi(argv[i]);
		ft_lstadd_back_push(&stack, ft_lstnew_push(value));
		i++;
	}
}
