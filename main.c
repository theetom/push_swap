/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etom <etom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:51:03 by toferrei          #+#    #+#             */
/*   Updated: 2024/09/22 00:59:16 by etom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_data	*data;
	char	**temp;
	int		*temp2;
	int		n;
	int		o;

	n = 0;
	o = 1;
	if (argc > 1)
	{
		if (argc == 2)
		{
			temp = ft_split(argv[1], ' ');
			if (ft_strlen)
			data->stack_a = ;
			while (temp[n])
			{
				temp2[n] = ft_atoi(temp[n]);
				n++;
			}
		}
		// if (argc > 2)
		// {
		// 	while (argv[o])
		// 	{
		// 		temp2[n++] = ft_atoi(argv[o++]);
		// 	}
		// }
	}
	ft_print_list(data->stack_a);
	else
		return (0);
}