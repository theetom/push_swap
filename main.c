/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etom <etom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:51:03 by toferrei          #+#    #+#             */
/*   Updated: 2024/09/23 23:41:07 by etom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void list_maker(data_t *data, char **input)
{
	int		n;
	
	n = 0;
	while (input[n])
		n++;
	data->temp = malloc(sizeof * data->temp * n);
	n = 0;
	while (input[n])
	{
		data->temp[n] = ft_atoi(input[n]);
		n++;
	}
}

int	main(int argc, char **argv)
{
	data_t	data;
	char	**temp;
	int		n;

	init(&data);
	if (argc > 1)
	{
		if (argc == 2)
		{
			temp = ft_split(argv[1], ' ');
		}
		list_maker(&data, temp);
		n = -1;
		while(temp[++n])
			free(temp[n]);
		free(temp);
	}
	n = 0;
	while(data.temp[n])
	{
		printf("%d\n", data.temp[n++]);
	}
	free(data.temp);
	// ft_print_list(data->stack_a);
	return (0);
}
