/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:03:44 by toferrei          #+#    #+#             */
/*   Updated: 2024/10/14 16:19:22 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	string_argument_chkr(char *str, int sit)
{
	size_t	n;

	n = 0;
	while (str[n])
	{
		if (sit == 1)
		{
			if (ft_isdigit(str[n]) == 0 && str[n] != ' ' \
			&& str[n] != '-' && str[n] != '+')
				error_message(2);
		}
		else
			if (ft_isdigit(str[n]) == 0 && str[n] != '-' && str[n] != '+')
				error_message(2);
		n++;
	}
}

int	is_list_valid(t_data *data, long *lst)
{
	size_t	n;
	size_t	m;

	n = 0;
	while (n < data->size)
	{
		m = n + 1;
		while (m < data->size)
		{
			if (lst[n] == lst[m] | lst[n] > 2147483647 | lst[n] < -2147483648)
				return (0);
			m++;
		}
		n++;
	}
	return (1);
}

void	first_verifs(int argc, char **argv)
{
	size_t	n;

	n = 1;
	if (argc < 2)
		error_message(1);
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
