/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:51:03 by toferrei          #+#    #+#             */
/*   Updated: 2024/10/07 17:50:15 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// https://push-swap-visualizer.vercel.app/

#include "push_swap.h"

int	fastest_route(t_node *lst, size_t n)
{
	t_node	*temp;
	size_t	m;
	size_t	o;

	o = 0;
	m = 0;
	temp = lst;
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

int	ft_abs(int nb)
{
	if (nb >= 0)
		return (nb);
	else
		return (-nb);
}

size_t	find_right_below(t_node *lst, size_t nb)
{
	t_node	*last;

	last = lst->prev;
	nb--;
	while (nb > 0)
	{
		ft_printf("nb is :%d and index is:%d\n", nb, lst->index);
		if (nb == lst->index)
			return (nb);
		lst = lst->next;
		ft_printf("nb is :%d and index is:%d\n", nb, lst->index);
		while (lst->prev != last)
		{
			if (nb == lst->index)
				return (nb);
			lst = lst->next;
		}
		nb--;
	}
	return (0);
}

int calculate_for_node(t_data *data, t_node *lst)
{
	ft_printf("semiantes\n");
	data->mv_b = 0;
	if (lst->index > data->max_b || lst->index < data->min_b)
		data->mv_b = fastest_route(*data->stack_b, data->max_b);
	else
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
	ft_printf("\naqui\n");
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
	ft_printf("vai tomar");
	data->mv_a = fastest_route(lst, lst->index);
	calculate_for_node(data, lst);
	return (index);
}

void	is_max_min(t_data *data, size_t nb)
{
	if (nb > data->max_b)
		data->max_b = nb;
	if (nb < data->min_b)
		data->min_b = nb;
}

void	init_sort(t_data *data)
{
	is_max_min(data, (*data->stack_a)->index);
	pb(data);
	is_max_min(data, (*data->stack_a)->index);
	pb(data);
}

void	send_to_b(t_data *data)
{
	while (list_size(data->stack_a) > 3)
	{
		find_cheapest(data, *(data->stack_a));
		ft_printf("\ndepois\n");
		while (data->mv_a_b > 0)
			rr(data);
		while (data->mv_a_b < 0)
			rrr(data);
		while (data->mv_a > 0)
			ra(data);
		while (data->mv_a < 0)
			rra(data);
		while (data->mv_b > 0)
			rb(data);
		while (data->mv_b < 0)
			rrb(data);
		pb(data);
	}
}

void turk_sort(t_data *data)
{
	int	n;

	n = data->size;
	data->s_s_b = 0;
	init_sort(data);
	send_to_b(data);
}

void print_array(int *arr, t_data *data)
{
	size_t		n;

	n = 0;
	while (n < data->size)
	{
		ft_printf("%d\n", arr[n]);
		n++;
	}
}

// void three_numbers(t_data *data) // WIP
// {
// 	if ((*data->stack_a)->index == 1 && (*data->stack_a)->next->index)
// 		return ;
// }

void	two_numbers(t_data *data) // WIP
{
	if ((*data->stack_a)->index == 2)
		ra(data);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		*temp;

	init(&data);
	first_verifs(argc, argv);
	temp = parser(&data, argc, argv);
	if (is_list_valid(&data, temp) == 0)
		error_message(4);
	list_maker(&data, temp);
	ft_printf("\nbefore a\n");
	ft_print_list(*(data.stack_a));
	// ft_insertion_sort(&data);
	if (data.size > 2)
		turk_sort(&data);
	else
		two_numbers(&data);
	free(temp);
	ft_printf("\nafter a\n");
	ft_print_list(*(data.stack_a));
	ft_printf("\nafter b\n");
	ft_print_list(*(data.stack_b));
	clean_list(data.stack_a);//, data.size);
	clean_list(data.stack_b);
	return (0);
}
