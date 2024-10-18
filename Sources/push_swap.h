/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:51:20 by toferrei          #+#    #+#             */
/*   Updated: 2024/10/18 18:04:41 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>

# include <string.h>
# include <stdlib.h>
# include <string.h>
# include "../Libft/libft.h"
# include "../Ft_printf/ft_printf.h"

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
	long		*temp;
	int			max_value;
	size_t		size; //size of array aka qtt of nbs to sort
	size_t		s_s_b; // size stack b
	size_t		max_b;
	size_t		min_b;
	int			mv_a;
	int			mv_b;
	int			mv_a_b;
}				t_data;

//	All functions

//		Initialization

void	init(t_data *data);

//		Error Messages

void	error_message(size_t err);

//		Verifications

void	first_verifs(int argc, char **argv);
int		is_list_valid(t_data *data, long *lst); // are there any doubles?
int		is_list_sorted(t_data *data, t_node *lst);
void	string_argument_chkr(char *str, int sit);

//		Parsing (args to int array)

long	*parser(t_data *data, int argc, char **argv);

//		Int array to double circular linked list

void	list_maker(t_data *data, long *arr);

// 		Sort Algo

void	ft_sort(t_data *data);
void	turk_sort(t_data *data);
void	two_numbers(t_data *data);
void	three_numbers(t_data *data);
size_t	find_right_below(t_node *lst, size_t nb);
void	send_to_b(t_data *data);
int		fastest_route(t_node *lst, size_t n);
int		find_cheapest(t_data *data, t_node *lst);
void	from_b_to_a(t_data *data);

// 		Sort Utils

int		is_list_sorted(t_data *data, t_node *lst);
void	is_max_min(t_data *data, size_t nb);
void	rotate_a_b(t_data *data, int n);
void	rotate_a(t_data *data, int n);
void	rotate_b(t_data *data, int n);

//		Utils for lists

t_node	*ft_newnode(int content, size_t index);
void	ft_list_add_back(t_node **lst, t_node *new);
void	ft_list_add_front(t_node **lst, t_node *new);
t_node	*ft_listlast(t_node *lst);
size_t	list_size(t_node **lst);
void	ft_print_list(t_node *lst);
void	clean_list(t_node **lst);

//	Utils

int		ft_abs(int nb);
void	print_array(long *arr, t_data *data);
long	ft_atol(const char *nptr);

//		Subject Functions

//		swap fx

void	sa(t_data *data);
void	sb(t_data *data);
void	ss(t_data *data);

//		push fx

void	pa(t_data *data);
void	pb(t_data *data);

//		rotate up fx

void	ra(t_data *data);
void	rb(t_data *data);
void	rr(t_data *data);

//		rotate down fx

void	rra(t_data *data);
void	rrb(t_data *data);
void	rrr(t_data *data);

#endif