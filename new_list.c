/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etom <etom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 03:16:53 by etom              #+#    #+#             */
/*   Updated: 2024/09/25 13:44:47 by etom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	list_maker(t_data *data, int *arr)
{
	size_t	n;
	t_node	*temp;
	data->stack_a = malloc(sizeof * data->stack_a);

	n = 0;
	while (n < data->size)
	{
		printf("list maker begining loop\n");
		temp = ft_newnode(arr[n]);
		printf("%d\n", temp->content);
		ft_list_add_back(data->stack_a, temp);
		n++;
	}
}