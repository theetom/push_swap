/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 17:38:45 by toferrei          #+#    #+#             */
/*   Updated: 2024/10/18 17:58:36 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	minus_plus_verif(char *str, size_t n)
{
	if ((str[n] == '-' | str[n] == '+') && ft_isdigit(str[n + 1]))
	{
		ft_printf ("deu qq coisa");
		return (1);
	}
	else
		return (0);
}

void	string_argument_chkr(char *str, int sit)
{
	size_t	n;

	n = 0;
	while (str[n])
	{
		if (sit == 1)
		{
			if (!(ft_isdigit(str[n])) && str[n] != ' ' \
			&& minus_plus_verif(str, n))
				error_message(2);
		}
		else
			if (ft_isdigit(str[n]) == 0 && minus_plus_verif(str, n))
				error_message(2);
		n++;
	}
}
