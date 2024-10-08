/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etom <etom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:53:11 by toferrei          #+#    #+#             */
/*   Updated: 2024/10/10 01:53:15 by etom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	list_size(t_node **lst)
{
	t_node	*temp;
	t_node	*last;
	size_t	n;

	if (lst == NULL)
		return (0);
	temp = *lst;
	last = (*lst)->prev;
	temp = temp->next;
	n = 1;
	while (temp->prev != last)
	{
		temp = temp->next;
		n++;
	}
	return (n);
}
