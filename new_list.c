/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 03:16:53 by etom              #+#    #+#             */
/*   Updated: 2024/10/01 15:05:52 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int *array_sort(t_data *data, int *arr)
{
	size_t	n;
	int		*temp;

	temp = malloc(sizeof * temp * data->size);
	n = 0;
	while (n < data->size)
	{
		temp[n] = arr[n];
		n++;
	}
	n = 0;
	while (n < data->size - 1)
	{
		if (temp[n] > temp[n + 1])
		{
			temp[n] ^= temp[n + 1];
 			temp[n + 1] ^= temp[n];
			temp[n] ^= temp[n + 1];
			n = 0;
		}
		else
			n++;
	}
	return (temp);
}

size_t	index_finder(int *arr, int vtf)
{
	size_t	n;

	n = 0;
	while (arr[n] != vtf)
		n++;
	return (n + 1);
}

void	list_maker(t_data *data, int *arr)
{
	size_t	n;
	t_node	*temp1;
	int		*temp;
	data->stack_a = malloc(sizeof * data->stack_a);
	*data->stack_a = NULL;
	data->stack_b = malloc(sizeof * data->stack_b);
	*data->stack_b = NULL;
	temp = array_sort(data, arr);
	printf("\ntemp\n");
	print_array(temp, data);
	
	n = 0;
	while (n < data->size)
	{
		temp1 = ft_newnode(arr[n], index_finder(temp, arr[n]));
		ft_list_add_back(data->stack_a, temp1);
		n++;
	}
	free(temp);
}
