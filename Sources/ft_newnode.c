/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newnode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:04:10 by toferrei          #+#    #+#             */
/*   Updated: 2024/10/10 16:53:56 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_newnode(int content, size_t index)
{
	t_node	*elem;

	elem = malloc(sizeof * elem);
	if (!elem)
		return (NULL);
	elem->content = content;
	elem->index = index;
	elem->next = NULL;
	elem->prev = NULL;
	return (elem);
}
