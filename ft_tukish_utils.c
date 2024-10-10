/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tukish_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etom <etom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 00:49:37 by etom              #+#    #+#             */
/*   Updated: 2024/10/10 00:49:59 by etom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	rotate_a_b(t_data *data, int n)
{
	while (n > 0)
	{
		rr(data);
		n--;
	}
	while (n < 0)
	{
		rrr(data);
		n++;
	}
}

void	rotate_a(t_data *data, int n)
{
	while (n > 0)
	{
		ra(data);
		n--;
	}
	while (n < 0)
	{
		rra(data);
		n++;
	}
}

void rotate_b(t_data *data, int n)
{
	while (n > 0)
	{
		rb(data);
		n--;
	}
	while (n < 0)
	{
		rrb(data);
		n++;
	}
}
