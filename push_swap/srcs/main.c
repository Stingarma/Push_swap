/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 00:51:35 by lsaumon           #+#    #+#             */
/*   Updated: 2024/07/01 18:31:48 by lsaumon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (!(parsing(argc, argv)))
	{
		ft_printf("Error\n");
		return (0);
	}
	add_args(&stack_a, argv);
	if (!stack_sorted(stack_a))
	{
		if (stack_len(stack_a) == 2)
			sa(stack_a, 1);
		else if (stack_len(stack_a) == 3)
			tiny_sort(&stack_a);
		else
			push_swap(&stack_a, &stack_b);
	}
	free_struct(stack_a);
	free_struct(stack_b);
}
