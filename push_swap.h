/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etom <etom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:51:20 by toferrei          #+#    #+#             */
/*   Updated: 2024/09/23 23:35:50 by etom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>

# include <string.h>
# include <stdlib.h>
# include <string.h>

typedef struct node_s
{
	void				*content;
	struct node_s		*next;
	struct node_s		*prev;
}						node_t;

typedef struct data_s
{
	node_t		**stack_a;
	node_t		**stack_b;
	int			*temp;
}				data_t;

int			ft_atoi(const char *nptr);
char		**ft_split(char const *s, char c);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
size_t		ft_strlen(const char *str);
void		ft_lstprnt(node_t **lst);
void		init(data_t *data);

#endif