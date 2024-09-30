/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fx_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:17:26 by toferrei          #+#    #+#             */
/*   Updated: 2024/09/30 17:45:35 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_node **lst)
{
	t_node	*first;
	t_node	*second;
	t_node	*last;

	if(!(*lst) || (*lst)->next == *lst)
		return ;
	first = *lst;
	second = first->next;
	last = first->prev;
	first->next = second->next;
    second->next->prev = first;
    second->next = first;
    second->prev = last;
    first->prev = second;
    last->next = second;
	*lst = second;
}

void	sa(t_data *data)
{
	swap(data->stack_a);
	printf("sa\n");
}

void	sb(t_data *data)
{
	swap(data->stack_b);
	printf("sa\n");
}

void	ss(t_data *data)
{
	swap(data->stack_a);
	swap(data->stack_b);
	printf("ss\n");
}