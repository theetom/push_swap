/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprnt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 00:56:05 by etom              #+#    #+#             */
/*   Updated: 2024/09/25 19:26:46 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_list(t_node *lst, size_t size)
{
	t_node	*temp;
	size_t	n;

	n = 0;
	if (lst == NULL)
		error_message(5);
	temp = lst;
	while (n < size)
	{
		ft_printf("%d", temp->content);
		temp = temp->next;
		n++;
	}
}
