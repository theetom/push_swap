/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_add_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 18:39:25 by toferrei          #+#    #+#             */
/*   Updated: 2024/09/30 18:46:25 by toferrei         ###   ########.fr       */
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