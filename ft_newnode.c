/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newnode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etom <etom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:04:10 by toferrei          #+#    #+#             */
/*   Updated: 2024/09/23 01:27:17 by etom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

node_t	*ft_newnode(void *content)
{
	node_t	*elem;

	elem = malloc(sizeof(node_t));
	if (!elem)
		return (NULL);
	elem->content = content;
	elem->next = NULL;
	elem->prev = NULL;
	return (elem);
}
