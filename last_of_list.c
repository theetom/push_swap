/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_of_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etom <etom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 01:37:48 by etom              #+#    #+#             */
/*   Updated: 2024/09/25 13:27:46 by etom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_listlast(t_node *lst)
{
	printf("ultimo antes\n");
	if (!lst)
		return (NULL);
	printf("ultimo fim\n");
	return (lst->prev);
}
