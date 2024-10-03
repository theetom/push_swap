/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:51:03 by toferrei          #+#    #+#             */
/*   Updated: 2024/10/03 17:27:34 by toferrei         ###   ########.fr       */
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
		return (1);
	else
		return (0);
}

void ft_quick_sort(t_data *data)
{
	size_t	n;

	n = 1;
	while (*data->stack_a)
	{
		if (fastest_route((*data->stack_a), n) == 1)
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

void turk_sort(t_data *data)
{
	int	n = data->size;
	n++;
}

size_t	list_size(t_node **lst)
{
	t_node *temp;
	t_node *last;
	size_t	n;

	if (lst == NULL)
		return (0);
	temp = *lst;
	last = (*lst)->prev;
	temp = temp->next;
	n = 1;
	while (temp->prev != last)
	{
		temp = temp->next;
		n++;
	}
	return (n);
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

void	two_numbers(t_data *data)
{
	if ((*data->stack_a)->index == 2)
	{
		ro
	}
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
	// ft_quick_sort(&data);
	if (data.size > 2)
		turk_sort(&data);
	else
		two_numbers(&data);
	sa(&data);
	free(temp);
	ft_printf("\nafter a\n");
	ft_print_list(*(data.stack_a));
	// ft_printf("\nafter b\n");
	// ft_print_list(*(data.stack_b));
	clean_list(data.stack_a);//, data.size);
	clean_list(data.stack_b);
	return (0);
}
