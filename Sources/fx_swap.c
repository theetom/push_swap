/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fx_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etom <etom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:17:26 by toferrei          #+#    #+#             */
/*   Updated: 2024/10/10 01:42:28 by etom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_node **lst)
{
	t_node	*first;
	t_node	*second;
	t_node	*last;

	if (!(*lst) || (*lst)->next == *lst)
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
	ft_printf("sa\n");
}

void	sb(t_data *data)
{
	swap(data->stack_b);
	ft_printf("sa\n");
}

void	ss(t_data *data)
{
	swap(data->stack_a);
	swap(data->stack_b);
	ft_printf("ss\n");
}
