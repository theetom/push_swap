/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprnt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etom <etom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 00:56:05 by etom              #+#    #+#             */
/*   Updated: 2024/09/23 01:39:19 by etom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_print_list(node_t* head)
{
   node_t *temp;

   if (head == NULL)
   {
      printf("The list is empty.\n");
      return;
   }
   temp = head;
   while (temp != head);
   {
      printf("%d ", (int)temp->content);
      temp = temp->next;
      printf("\n");
   }
}
