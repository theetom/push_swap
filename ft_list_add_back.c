/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_add_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 01:33:51 by etom              #+#    #+#             */
/*   Updated: 2024/09/30 16:27:42 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_listlast(t_node *lst)
{
	if (!lst)
		return (NULL);
	return (lst->prev);
}

void	ft_list_add_back(t_node **lst, t_node *new)
{
	t_node	*last;

	last = ft_listlast(*lst);
	if (!last)
	{
		*lst = new;
		new->next = new;
		new->prev = new;
		return ;
	}
	last->next = new;
	new->prev = last;
	new->next = *lst;
	(*lst)->prev = new;
}
