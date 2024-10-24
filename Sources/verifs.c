/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:03:44 by toferrei          #+#    #+#             */
/*   Updated: 2024/10/21 16:41:16 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_int_max(long *lst, size_t max)
{
	size_t	n;

	n = 0;
	while (n < max)
	{
		if (lst[n] > 2147483647 | lst[n] < -2147483648)
			return (0);
		n++;
	}
	return (1);
}

int	has_double(t_data *data, long *lst)
{
	size_t	n;
	size_t	m;

	n = 0;
	while (n < data->size)
	{
		m = n + 1;
		while (m < data->size)
		{
			if (lst[n] == lst[m])
				return (0);
			m++;
		}
		n++;
	}
	return (1);
}

int	is_list_valid(t_data *data, long *lst)
{
	if (has_double(data, lst) == 0)
		return (0);
	if (has_int_max(lst, data->size) == 0)
		return (0);
	return (1);
}

void	first_verifs(int argc, char **argv)
{
	size_t	n;

	n = 1;
	if (argc < 2)
		exit (1);
	if (argc == 2)
		string_argument_chkr(argv[1], 1);
	else
	{
		while (argv[n])
		{
			string_argument_chkr(argv[n], 0);
			n++;
		}
	}
}
