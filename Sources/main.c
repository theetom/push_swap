/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:51:03 by toferrei          #+#    #+#             */
/*   Updated: 2024/10/21 14:16:24 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// https://push-swap-visualizer.vercel.app/

#include "push_swap.h"

void	second_verifs(t_data *data, long *temp)
{
	if (data->size < 2)
	{
		free(temp);
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	t_data	data;
	long	*temp;

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
