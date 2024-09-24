/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:51:20 by toferrei          #+#    #+#             */
/*   Updated: 2024/09/24 17:05:27 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>

# include <string.h>
# include <stdlib.h>
# include <string.h>
# include "Libft/libft.h"
# include "Ft_printf/ft_printf.h"

typedef struct node_s
{
	void				*content;
	struct node_s		*next;
	struct node_s		*prev;
}						t_node;

typedef struct s_data
{
	t_node		**stack_a;
	t_node		**stack_b;
	int			*temp;
	size_t		size_temp;
}				t_data;


void	ft_lstprnt(t_node **lst);

void	init(t_data *data);

void	error_message(size_t err);

void	first_verifs(int argc, char **argv);
int		is_list_valid(t_data *data, int *lst);

int		*parser(t_data *data, int argc, char **argv);

#endif