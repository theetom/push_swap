/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fx_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etom <etom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:47:16 by toferrei          #+#    #+#             */
/*   Updated: 2024/10/10 01:43:31 by etom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	take_from_src(t_node **src)
{
	t_node	*last_s;
	t_node	*scnd_s;

	last_s = (*src)->prev;
	scnd_s = (*src)->next;
	if ((*src)->next == (*src))
		*src = NULL;
	else
	{
		last_s->next = scnd_s;
		scnd_s->prev = last_s;
		*src = scnd_s;
	}
}

static void	put_in_dst(t_node **dst, t_node *temp)
{
	t_node	*frst_d;
	t_node	*last_d;

	if (!(*dst))
	{
		temp->next = temp;
		temp->prev = temp;
		*dst = temp;
	}
	else
	{
		frst_d = *dst;
		last_d = (*dst)->prev;
		temp->next = frst_d;
		temp->prev = last_d;
		frst_d->prev = temp;
		last_d->next = temp;
		*dst = temp;
	}
}

static void	push(t_node **src, t_node **dst)
{
	t_node	*temp;

	if (!(*src))
		return ;
	temp = (*src);
	take_from_src(src);
	put_in_dst(dst, temp);	
}

void	pa(t_data *data)
{
	push(data->stack_b, data->stack_a);
	ft_printf("pa\n");
}

void	pb(t_data *data)
{
	push(data->stack_a, data->stack_b);
	ft_printf("pb\n");
}
