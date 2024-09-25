/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_add_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 01:33:51 by etom              #+#    #+#             */
/*   Updated: 2024/09/25 19:24:35 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
