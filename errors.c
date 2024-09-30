/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:59:44 by toferrei          #+#    #+#             */
/*   Updated: 2024/09/26 14:21:50 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// error message handler

void error_message(size_t err)
{
	if (err == 0)
		ft_printf("Malloc error\n");
	if (err == 1)
		ft_printf("Wrong number of arguments\n");
	if (err == 2)
		ft_printf("Wrong argument input\n");
	if (err == 3)
		ft_printf("Not enough numbers to sort\n");
	if (err == 4)
		ft_printf("Repeated number\n");
	if (err == 5)
		ft_printf("The list is empty.\n");
	exit (1);
}
