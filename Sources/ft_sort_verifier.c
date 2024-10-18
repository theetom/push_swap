/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_verifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:54:43 by toferrei          #+#    #+#             */
/*   Updated: 2024/10/18 15:16:20 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_list_sorted(t_data *data, t_node *lst)
{
	size_t	n;
	t_node	*last;

	last = lst->prev;
	n = 1;
	if (lst->index == n)
	{
		lst = lst->next;
		n++;
	}
	while (lst != last && lst->index == n)
	{
		lst = lst->next;
		n++;
	}
	if (data->size == n)
		return (1);
	else
		return (0);
}
