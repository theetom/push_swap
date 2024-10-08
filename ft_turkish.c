/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turkish.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etom <etom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 00:51:50 by etom              #+#    #+#             */
/*   Updated: 2024/10/08 03:14:35 by etom             ###   ########.fr       */
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

size_t	find_right_below(t_node *lst, size_t nb)
{
	t_node	*last;

	last = lst->prev;
	while (nb > 0)
	{
		
		if (nb == lst->index)
			{ft_printf("first nb is :%d and index is:%d\n", nb, lst->index);
			return (nb);}
		lst = lst->next;
		while (lst->prev != last)
		{
			if (nb == lst->index)
			{ft_printf("2nd nb is :%d and index is:%d\n", nb, lst->index);
				return (nb);}
			lst = lst->next;
		}
		nb--;
	}
	ft_printf("3rd nb is :%d and index is:%d\n", nb, lst->index);
	return (0);
}

int calculate_for_node(t_data *data, t_node *lst)
{
	ft_printf("passei ca!\n");
	data->mv_b = 0;
	data->mv_a_b = 0;
	if (lst->index < data->min_b)
		data->mv_b = 0;
	if (lst->index > data->max_b)
	{
		ft_printf("passei ca2!\n");
		ft_printf("max b%d\n", data->max_b);
		data->mv_b = fastest_route(*data->stack_b, data->max_b);
	}
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
	data->mv_a = fastest_route(lst, lst->index);
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
	is_max_min(data, (*data->stack_a)->index);
	pb(data);
	is_max_min(data, (*data->stack_a)->index);
	pb(data);
	if ((*data->stack_b)->index == data->min_b)
		rb(data);
}

void	send_to_b(t_data *data)
{
	while (list_size(data->stack_a) > 1)
	{
		find_cheapest(data, *(data->stack_a));
		ft_printf("\ndepois\n");
		while (data->mv_a_b > 0)
		{
			rr(data);
			data->mv_a_b--;
		}
		while (data->mv_a_b < 0)
		{
			rrr(data);
			data->mv_a_b++;
		}
		while (data->mv_a > 0)
		{
			ra(data);
			data->mv_a--;
		}
		while (data->mv_a < 0)
		{
			rra(data);
			data->mv_a++;
		}
		while (data->mv_b > 0)
		{	
			rb(data);
			data->mv_b--;
		}
		while (data->mv_b < 0)
		{	
			rrb(data);
			data->mv_b++;
		}
		pb(data);
		if ((*data->stack_b)->index < (*data->stack_b)->prev->index)
			rrb(data);
		data->s_s_b++; //size stack b, dont see the point in knowing anymore
		is_max_min(data, (*data->stack_b)->index);
	}
}

void from_b_to_a(t_data *data)
{
	int	temp;
	int n;
	temp = (*data->stack_a)->index;
	n = fastest_route(*data->stack_b, data->max_b);
	if (n > 0)

	while (*data->stack_b && (*data->stack_b)->index > temp)
		pa(data);
}

void turk_sort(t_data *data)
{
	int	n;

	n = data->size;
	data->s_s_b = 2;
	init_sort(data);
	send_to_b(data);
	from_b_to_a(data);
	ft_printf("\nwhile b\n");
	ft_print_list(*data->stack_b);
	ft_printf("\nwhile a\n");
	ft_print_list(*data->stack_a);
}
