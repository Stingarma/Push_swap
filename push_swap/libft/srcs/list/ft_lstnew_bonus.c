/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:17:17 by lsaumon           #+#    #+#             */
/*   Updated: 2024/03/10 16:07:28 by lsaumon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_stack	*ft_lstnew(int value)
{
	t_stack	*structure;

	structure = malloc(1 * sizeof(t_stack));
	if (!structure)
		return (NULL);
	structure->value = value;
	structure->next = NULL;
	return (structure);
}
