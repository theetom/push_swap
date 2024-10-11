/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turkish_b_to_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etom <etom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 01:50:28 by etom              #+#    #+#             */
/*   Updated: 2024/10/11 00:40:29 by etom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	from_b_to_a(t_data *data)
{
	int	temp;
	int	m;

	m = data->max_b;
	while (data->s_s_b > 0)
	{
		temp = (*data->stack_a)->prev->index;
		while (data->s_s_b > 0 && m != temp)
		{
			rotate_b(data, fastest_route(*data->stack_b, m));
			pa(data);
			data->s_s_b--;
			m--;
		}
		if (m == temp)
		{
			rra(data);
			m--;
		}
	}
}
