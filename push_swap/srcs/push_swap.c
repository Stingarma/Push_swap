/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 07:10:33 by lsaumon           #+#    #+#             */
/*   Updated: 2024/05/06 08:02:45 by lsaumon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_pushswap(t_stack *stack)
{
	stack->value = NULL;
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
		ft_lstadd_back(&stack, ft_lstnew(value));
		i++;
	}
}
