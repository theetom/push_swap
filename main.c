/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etom <etom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:51:03 by toferrei          #+#    #+#             */
/*   Updated: 2024/10/08 00:59:51 by etom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// https://push-swap-visualizer.vercel.app/

#include "push_swap.h"

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
