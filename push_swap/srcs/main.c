/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 00:51:35 by lsaumon           #+#    #+#             */
/*   Updated: 2024/05/08 06:40:14 by lsaumon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int main(int argc, char **argv)
{
	t_stack	*stack;
	t_stack	*node;

	stack = ft_lstnew_push(0);
	if (!(parsing(argc, argv)))
		return (ft_printf("Error\n"), 1);
	// init_pushswap(&stack);
	node = stack;
	add_arg(stack, argv);
	while (node)
	{
		printf("%d\n", node->value);
		node = node->next;
	}
	free_struct(stack);
	return (0);
}

