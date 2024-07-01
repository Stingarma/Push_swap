/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 06:24:59 by lsaumon           #+#    #+#             */
/*   Updated: 2024/07/01 18:31:58 by lsaumon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*ft_lstnew_push(int value)
{
	t_stack	*structure;

	structure = malloc(1 * sizeof(t_stack));
	if (!structure)
		return (NULL);
	structure->value = value;
	structure->next = NULL;
	return (structure);
}

void	ft_lstadd_back_push(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (!*lst)
		*lst = new;
	else
	{
		last = ft_lstlast_push(*lst);
		last->next = new;
	}
}

void	ft_lstadd_front_push(t_stack **lst, t_stack *new)
{
	if (!new)
		return ;
	if (*lst)
		new->next = *lst;
	*lst = new;
}

int	ft_lstsize_push(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

t_stack	*ft_lstlast_push(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
