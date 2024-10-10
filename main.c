/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etom <etom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:51:03 by toferrei          #+#    #+#             */
/*   Updated: 2024/10/10 01:41:49 by etom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// https://push-swap-visualizer.vercel.app/

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

int	is_list_sorted(t_data *data, t_node *lst)
{
	int		n;
	t_node	*last;

	last = lst->prev;
	n = 1;
	if (lst->index == n)
	{
		lst = lst->next;
		n++;
	}
	while (lst != last)
	{
		lst = lst->next;
		n++;
	}
	if (data->size == n)
		return (1);
	else
		return (0);
}

void	second_verifs(t_data *data, int *temp)
{
	if (data->size < 2)
	{
		free(temp);
		error_message(3);
	}
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		*temp;

	init(&data);
	first_verifs(argc, argv);
	temp = parser(&data, argc, argv);
	second_verifs(&data, temp);
	if (is_list_valid(&data, temp) == 0)
	{
		free(temp);
		error_message(4);
	}
	list_maker(&data, temp);
	if (is_list_sorted(&data, *data.stack_a))
	{
		if (data.size > 3)
			turk_sort(&data);
		if (data.size == 3)
			three_numbers(&data);
		else
			two_numbers(&data);}
	if (is_list_sorted (&data, *data.stack_a) == 1)
		ft_printf("yay\n");
	else
		ft_printf("nay\n");
	free(temp);
	clean_list(data.stack_a);
	clean_list(data.stack_b);
	return (0);
}
