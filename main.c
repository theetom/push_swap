/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:51:03 by toferrei          #+#    #+#             */
/*   Updated: 2024/10/01 16:40:08 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_quick_sort(t_data *data)
{
	size_t	n;

	n = 0;
	while (*data->stack_a)
	{
		while ((*data->stack_a)->index != n)
		{
			ra(data);
		}
		pb(data);
		n++;
	}
	while (*data->stack_b)
		pa(data);
}

// void	ft_insertion_sort(t_data *data, t_node **s_a, t_node **s_b)
// {
// 	pb(data);
// 	while (*s_a)
// 	{
// 		if ((*s_b)->content < (*s_a)->content)
// 			pb(data);
// 		else
// 			rr(data);
// 	}
// 	while (*s_b)
// 	{
// 		if ((*s_a)->content < (*s_b)->content)
// 			pa(data);
// 		else
// 			rr(data);
// 	}
// }

// void	ft_bubble_sort(t_data *data)
// {
// 	size_t 	n;
// 	// t_node	*tempa;
// 	// t_node	*tempb;

// 	n = 0;
// 	while (data->size < n)
// 	{
// 		while ((*data->stack_a)->content > (*data->stack_b)->content)
// 		{
// 			pa(data);
// 		}
// 		n++;
// 	}
// }

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
	// ft_bubble_sort(&data);
	ft_printf("\nbefore a\n");
	ft_print_list(*(data.stack_a));
	// ft_printf("\nbefore b\n");
	// ft_print_list(*(data.stack_b));
	// ft_insertion_sort(&data, data.stack_a, data.stack_b);
	ft_quick_sort(&data);
	free(temp);
	// ft_printf("\nafter a\n");
	// ft_print_list(*(data.stack_a));
	// ft_printf("\nafter b\n");
	// ft_print_list(*(data.stack_b));
	clean_list(data.stack_a);//, data.size);
	clean_list(data.stack_b);
	return (0);
}
