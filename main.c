/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:51:03 by toferrei          #+#    #+#             */
/*   Updated: 2024/10/10 16:49:55 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// https://push-swap-visualizer.vercel.app/

#include "push_swap.h"

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
	ft_sort(&data);
	free(temp);
	clean_list(data.stack_a);
	clean_list(data.stack_b);
	return (0);
}
