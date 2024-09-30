/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List_cleaner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:35:08 by toferrei          #+#    #+#             */
/*   Updated: 2024/09/30 17:02:57 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clean_list(t_node **lst)
{
	t_node	*temp;

	if (!lst)
		return ;
	if (*lst)
	{
		temp = *lst;
		*lst = (*lst)->prev;
		(*lst)->next = NULL;
		*lst = temp;
		while (*lst)
		{
			temp = (*lst)->next;
			free(*lst);
			*lst = temp;
		}
	}
	free(lst);
	lst = NULL;
}
