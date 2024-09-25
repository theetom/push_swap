/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 03:16:53 by etom              #+#    #+#             */
/*   Updated: 2024/09/25 19:24:30 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	list_maker(t_data *data, int *arr)
{
	size_t	n;
	t_node	*temp;
	data->stack_a = malloc(sizeof * data->stack_a);
	*data->stack_a = NULL;
	
	n = 0;
	while (n < data->size)
	{
		temp = ft_newnode(arr[n]);
		ft_list_add_back(data->stack_a, temp);
		n++;
	}
}