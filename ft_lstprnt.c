/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprnt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etom <etom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 00:56:05 by etom              #+#    #+#             */
/*   Updated: 2024/09/25 13:33:13 by etom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_list(t_node *lst, size_t size)
{
	t_node	*temp;
	size_t	n;

	n = 0;
	if (lst == NULL)
	{
		printf("The list is empty.\n");
		return;
	}
	printf("ola");
	temp = lst;
	while (n < size)
	{
		ft_printf("%daqui\n", temp->content);
		lst = lst->next;
		n++;
	}
}
