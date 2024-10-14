/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turkish.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 00:51:50 by etom              #+#    #+#             */
/*   Updated: 2024/10/14 15:21:14 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	fastest_route(t_node *lst, size_t n)
{
	t_node	*temp;
	size_t	m;
	size_t	o;

	o = 0;
	m = 0;
	temp = lst;
	if (temp->index == n)
		return (0);
	while (temp->index != n)
	{
		temp = temp->next;
		m++;
	}
	temp = lst;
	while (temp->index != n)
	{
		temp = temp->prev;
		o++;
	}
	if (m < o)
		return (m);
	else
		return (-(o));
}

int	calculate_for_node(t_data *data, t_node *lst)
{
	data->mv_b = 0;
	data->mv_a_b = 0;
	if (lst->index < data->min_b)
		data->mv_b = fastest_route(*data->stack_b, data->max_b);
	if (lst->index > data->max_b)
		data->mv_b = fastest_route(*data->stack_b, data->max_b);
	else if (lst->index > data->min_b)
		data->mv_b = fastest_route(*data->stack_b, \
		find_right_below(*data->stack_b, lst->index));
	while (data->mv_a > 0 && data->mv_b > 0)
	{
		data->mv_a--;
		data->mv_b--;
		data->mv_a_b++;
	}
	while (data->mv_a < 0 && data->mv_b < 0)
	{
		data->mv_a++;
		data->mv_b++;
		data->mv_a_b--;
	}
	return (abs(data->mv_a) + abs(data->mv_b) + abs(data->mv_a_b));
}

int	find_cheapest(t_data *data, t_node *lst)
{
	int		current;
	t_node	*last;
	size_t	index;

	last = lst->prev;
	index = lst->index;
	data->mv_a = 0;
	current = calculate_for_node(data, lst);
	lst = lst->next;
	while (lst->prev != last)
	{
		data->mv_a = fastest_route(*data->stack_a, lst->index);
		if (calculate_for_node(data, lst) < current)
		{
			current = calculate_for_node(data, lst);
			index = lst->index;
		}
		lst = lst->next;
	}
	while (lst->index != index)
		lst = lst->next;
	data->mv_a = fastest_route(*data->stack_a, lst->index);
	calculate_for_node(data, lst);
	return (index);
}

void	init_sort(t_data *data)
{
	pb(data);
	is_max_min(data, (*data->stack_b)->index);
	pb(data);
	is_max_min(data, (*data->stack_b)->index);
	if ((*data->stack_b)->index == data->min_b)
		rb(data);
}

void	turk_sort(t_data *data)
{
	int	n;

	n = data->size;
	data->s_s_b = 2;
	if (n > 4)
	{
		init_sort(data);
		send_to_b(data);
		three_numbers(data);
		from_b_to_a(data);
	}
	else
	{
		pb(data);
		data->s_s_b++;
		is_max_min(data, (*data->stack_b)->index);
		three_numbers(data);
		if ((*data->stack_b)->index == data->size)
			rotate_a(data, fastest_route(*data->stack_a, 1));
		else
			rotate_a(data, fastest_route(*data->stack_a, data->max_b + 1));
		pa(data);
	}
	rotate_a(data, fastest_route(*data->stack_a, 1));
}
