/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:51:03 by toferrei          #+#    #+#             */
/*   Updated: 2024/09/30 20:07:54 by toferrei         ###   ########.fr       */
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

	init(&data);
	first_verifs(argc, argv);
	temp = parser(&data, argc, argv);
	if (is_list_valid(&data, temp) == 0)
		error_message(4);
	list_maker(&data, temp);
	// print_array(temp, &data);
	
	ft_printf("lista a:\n");
	ft_print_list(*(data.stack_a));
	ft_printf("lista b:\n");
	ft_print_list(*(data.stack_b));
	ra(&data);

	ft_printf("lista a:\n");
	ft_print_list(*(data.stack_a));
	ft_printf("lista b:\n");
	ft_print_list(*(data.stack_b));
	free(temp);
	clean_list(data.stack_a);//, data.size);
	clean_list(data.stack_b);
	return (0);
}
