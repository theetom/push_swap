/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etom <etom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:51:03 by toferrei          #+#    #+#             */
/*   Updated: 2024/09/25 13:31:41 by etom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	main(int argc, char **argv)
{
	t_data	data;
	int		*temp;
	int		n = 0;

	init(&data);
	first_verifs(argc, argv);
	temp = parser(&data, argc, argv);
	if (is_list_valid(&data, temp) == 0)
		error_message(4);
	list_maker(&data, temp);
	// print_array(temp, &data);
	ft_print_list(*(data.stack_a), data.size);
	free(temp);
	free(data.stack_a);
	return (0);
}
