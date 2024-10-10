/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turkish.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etom <etom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 00:51:50 by etom              #+#    #+#             */
/*   Updated: 2024/10/10 01:21:53 by etom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	find_right_below(t_node *lst, size_t nb)
{
	t_node	*last;

	last = lst->prev;
	if (nb == lst->index)
		return (nb);
	lst = lst->next;
	while (nb > 0)
	{
		if (nb == lst->index)
			return (nb);
		if (lst == last)
			nb--;
		lst = lst->next;
	}
	return (0);
}

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

void ft_insertion_sort(t_data *data)
{
	size_t	n;

	n = 1;
	while (*data->stack_a)
	{
		if (fastest_route((*data->stack_a), n) >= 0 )
			while ((*data->stack_a)->index != n)
				ra(data);
		else
			while ((*data->stack_a)->index != n)
				rra(data);
		pb(data);
		n++;
	}
	while (*data->stack_b)
		pa(data);
}

int calculate_for_node(t_data *data, t_node *lst)
{
	data->mv_b = 0;
	data->mv_a_b = 0;
	if (lst->index < data->min_b)
		data->mv_b = fastest_route(*data->stack_b, data->max_b);
	if (lst->index > data->max_b)
		data->mv_b = fastest_route(*data->stack_b, data->max_b);
	else if (lst->index > data->min_b)
		data->mv_b = fastest_route(*data->stack_b, find_right_below(*data->stack_b, lst->index));
	if ((data->mv_a > 0 && data->mv_b > 0) || (data->mv_a < 0 && data->mv_b < 0))
	{
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

void	is_max_min(t_data *data, size_t nb)
{
	if (nb > data->max_b)
		data->max_b = nb;
	if (nb < data->min_b || data->min_b == 0)
		data->min_b = nb;
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

void	send_to_b(t_data *data)
{
	while (list_size(data->stack_a) > 1)
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

void from_b_to_a(t_data *data)
{
	int	temp;
	int m;
	int	n;

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

void turk_sort(t_data *data)
{
	int	n;

	n = data->size;
	data->s_s_b = 2;
	if (n > 4)
	{
		init_sort(data);
		send_to_b(data);
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
	// from_b_to_a(data);
	rotate_a(data, fastest_route(*data->stack_a, 1));
}
