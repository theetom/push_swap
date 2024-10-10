/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turkish_find_below.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 01:48:24 by etom              #+#    #+#             */
/*   Updated: 2024/10/10 16:54:25 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	find_right_below(t_node *lst, size_t nb)
{
	t_node	*last;

	last = lst->prev;
	if (nb == lst->index)
		return (nb);
	lst = lst->next;
	while (nb > 0)
	{
		if (nb == lst->index)
			return (nb);
		if (lst == last)
			nb--;
		lst = lst->next;
	}
	return (0);
}
