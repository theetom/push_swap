/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 00:46:39 by etom              #+#    #+#             */
/*   Updated: 2024/10/07 16:37:51 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void init(t_data *data)
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