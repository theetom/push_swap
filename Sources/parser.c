/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:21:53 by toferrei          #+#    #+#             */
/*   Updated: 2024/10/14 16:10:04 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	*string_parser(t_data *data, char *str)
{
	char	**temp;
	long	*result;
	size_t	n;

	n = 0;
	temp = ft_split(str, ' ');
	while (temp[n])
		n++;
	result = malloc(sizeof * result * n);
	if (!result)
		error_message(0);
	n = 0;
	while (temp[n])
	{
		result[n] = ft_atol(temp[n]);
		if (result[n] > data->max_value)
			data->max_value = result[n];
		n++;
	}
	data->size = n;
	n = 0;
	while (temp[n])
		free(temp[n++]);
	free(temp);
	return (result);
}

static long	*args_parser(t_data *data, int argc, char **argv)
{
	long	*result;
	size_t	n;

	n = 0;
	result = malloc(sizeof * result * argc);
	if (!result)
		error_message(0);
	n = 1;
	while (argv[n])
	{
		result[n - 1] = ft_atol(argv[n]);
		if (result[n - 1] > data->max_value)
			data->max_value = result[n - 1];
		n++;
	}
	data->size = n - 1;
	return (result);
}

long	*parser(t_data *data, int argc, char **argv)
{
	long	*result;

	if (argc == 2)
		result = string_parser(data, argv[1]);
	else
		result = args_parser(data, argc, argv);
	return (result);
}
