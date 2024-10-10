/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_add_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etom <etom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 18:39:25 by toferrei          #+#    #+#             */
/*   Updated: 2024/10/10 01:52:41 by etom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_list_add_front(t_node **lst, t_node *new)
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
	*lst = new;
}
