/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:41:13 by toferrei          #+#    #+#             */
/*   Updated: 2024/10/14 14:43:37 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_numbers(t_data *data)
{
	int	first;
	int	second;
	int	third;

	first = (*data->stack_a)->index;
	second = (*data->stack_a)->next->index;
	third = (*data->stack_a)->prev->index;
	if (first < second && first < third && second > third)
	{
		rra(data);
		sa(data);
		return ;
	}
	if (first > second && first < third && first > second)
		sa(data);
	if (first < second && first > third && first > third)
		rra(data);
	if (first > second && first > third && second < third)
		ra(data);
	if (first > second && second > third && second > third)
	{
		sa(data);
		rra(data);
	}
}

void	two_numbers(t_data *data)
{
	if ((*data->stack_a)->index == 2)
		ra(data);
}

void	ft_sort(t_data *data)
{
	if (!is_list_sorted(data, *data->stack_a))
	{
		if (data->size > 3)
			turk_sort(data);
		if (data->size == 3)
			three_numbers(data);
		else
			two_numbers(data);
	}
}
