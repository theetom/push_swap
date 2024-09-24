/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:21:53 by toferrei          #+#    #+#             */
/*   Updated: 2024/09/24 16:35:51 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*string_parser(t_data *data, char *str)
{
	char	**temp;
	int		*result;
	size_t	n;

	n = 0;
	temp = ft_split(str, ' ');
	while (temp[n])
		n++;
	result = malloc(sizeof * result * (n + 1));
	if (!result)
		error_message(0);
	n = 0;
	while (temp[n])
	{
		result[n] = ft_atoi(temp[n]);
		n++;
	}
	data->size_temp = n;
	n = 0;
	while(temp[n])
		free(temp[n++]);
	free(temp);
	return (result);
}

int	*args_parser(t_data *data, int argc, char **argv)
{
	int		*result;
	size_t	n;

	n = 0;
	result = malloc(sizeof * result * argc);
	if (!result)
		error_message(0);
	n = 1;
	while (argv[n])
	{
		result[n - 1] = ft_atoi(argv[n]);
		n++;
	}
	data->size_temp = n - 1;
	return (result);
}

int	*parser(t_data *data, int argc, char **argv)
{
	int		*result;
	size_t	n;

	n = 0;
	if (argc == 2)
		result = string_parser(data, argv[1]);
	else
		result = args_parser(data, argc, argv);
	if (data->size_temp < 2)
		error_message(3);
	return (result);
}
