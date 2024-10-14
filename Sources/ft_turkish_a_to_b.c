/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turkish_a_to_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 01:46:44 by etom              #+#    #+#             */
/*   Updated: 2024/10/14 14:58:00 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	send_to_b(t_data *data)
{
	while (list_size(data->stack_a) > 3)
	{
		find_cheapest(data, *(data->stack_a));
		rotate_a(data, data->mv_a);
		rotate_a_b(data, data->mv_a_b);
		rotate_b(data, data->mv_b);
		data->mv_a_b = 0;
		data->mv_b = 0;
		data->mv_a = 0;
		pb(data);
		data->s_s_b++;
		is_max_min(data, (*data->stack_b)->index);
	}
}
