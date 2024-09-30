/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprnt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 00:56:05 by etom              #+#    #+#             */
/*   Updated: 2024/09/30 18:20:12 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_list(t_node *lst)
{
	t_node *last;
	t_node *temp;

	if (lst == NULL)
		error_message(5);
	temp = lst;
	last = lst->prev;
	ft_printf("%d\n", temp->content);
		temp = temp->next;
	while (temp->prev != last)
	{
		ft_printf("%d\n", temp->content);
		temp = temp->next;
	}
}
