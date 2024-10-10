/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etom <etom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 01:54:34 by etom              #+#    #+#             */
/*   Updated: 2024/10/10 01:55:05 by etom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init(t_data *data)
{
	data->stack_a = NULL;
	data->stack_b = NULL;
	data->temp = NULL;
	data->max_value = 0;
	data->max_b = 0;
	data->min_b = 0;
	data->mv_a = 0;
	data->mv_b = 0;
	data->mv_a_b = 0;
}