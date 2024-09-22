/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newnode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:04:10 by toferrei          #+#    #+#             */
/*   Updated: 2024/09/19 17:25:07 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

e_list	*ft_newnode(void *content)
{
	e_list	*elem;

	elem = malloc(sizeof(e_list));
	if (!elem)
		return (NULL);
	elem->content = content;
	elem->next = NULL;
	elem->prev = NULL;
	return (elem);
}
