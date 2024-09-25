/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_add_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etom <etom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 01:33:51 by etom              #+#    #+#             */
/*   Updated: 2024/09/25 13:45:16 by etom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_list_add_back(t_node **lst, t_node *new)
{
	t_node	*last;

	printf("acrescenta princ\n");
	last = ft_listlast(*lst);
	if (!last)
	{
	printf("acrescenta mid\n");
		*lst = new;
		new->next = new;
		new->prev = new;
		return ;
	}
	printf("acrescenta fim\n");
	last->next = new;
	new->prev = last;
	new->next = *lst;
	(*lst)->prev = new;
}
