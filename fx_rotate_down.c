/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fx_rotate_down.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 20:07:03 by toferrei          #+#    #+#             */
/*   Updated: 2024/09/30 20:07:46 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void rotatedown(t_node **lst)
{
	if (!(*lst))
		return ;
	*lst = (*lst)->prev;
}

void rra(t_data *data)
{
	rotatedown(data->stack_a);
	ft_printf("rra\n");
}

void rrb(t_data *data)
{
	rotatedown(data->stack_b);
	ft_printf("rrb\n");
}

void rrr(t_data *data)
{
	rotatedown(data->stack_a);
	rotatedown(data->stack_b);
	ft_printf("rrr\n");
}
