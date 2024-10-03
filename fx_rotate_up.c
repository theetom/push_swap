/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fx_rotate_up.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 19:46:22 by toferrei          #+#    #+#             */
/*   Updated: 2024/10/03 17:27:19 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotateup(t_node **lst)
{
	if (!(*lst))
		return ;
	*lst = (*lst)->next;
}

void ra(t_data *data)
{
	rotateup(data->stack_a);
	ft_printf("ra\n");
}

void rb(t_data *data)
{
	rotateup(data->stack_b);
	ft_printf("rb\n");
}

void rr(t_data *data)
{
	rotateup(data->stack_a);
	rotateup(data->stack_b);
	ft_printf("rr\n");
}
