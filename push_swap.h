/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:51:20 by toferrei          #+#    #+#             */
/*   Updated: 2024/10/03 17:30:14 by toferrei         ###   ########.fr       */
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

typedef struct s_node
{
	int					content;
	size_t				index;
	struct s_node		*next;
	struct s_node		*prev;
}						t_node;

typedef struct s_data
{
	t_node		**stack_a;
	t_node		**stack_b;
	int			*temp;
	int			max_value;
	size_t		size; //size of array aka qtt of nbs to sort
	size_t		s_s_b; // size stack b
}				t_data;

void	print_array(int *arr, t_data *data);

//	All functions

//		Initialization

void	init(t_data *data);

//		Error Messages

void	error_message(size_t err);

//		Verifications

void	first_verifs(int argc, char **argv);
int		is_list_valid(t_data *data, int *lst); // are there any doubles?

//		Parsing (args to int array)

int		*parser(t_data *data, int argc, char **argv);

//		Int array to double circular linked list

void	list_maker(t_data *data, int *arr);

//		Utils for lists

t_node	*ft_newnode(int content, size_t index);
void	ft_list_add_back(t_node **lst, t_node *new);
void	ft_list_add_front(t_node **lst, t_node *new);
t_node	*ft_listlast(t_node *lst);

void	ft_print_list(t_node *lst);

void	clean_list(t_node **lst);

//		Subject Functions

//			swap fx

void	sa(t_data *data);
void	sb(t_data *data);
void	ss(t_data *data);

//			push fx

void	pa(t_data *data);
void	pb(t_data *data);

//			rotate up fx

void	ra(t_data *data);
void	rb(t_data *data);
void	rr(t_data *data);

//			rotate down fx

void	rra(t_data *data);
void	rrb(t_data *data);
void	rrr(t_data *data);

#endif