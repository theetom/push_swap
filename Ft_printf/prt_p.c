/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etom <etom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 17:53:29 by toferrei          #+#    #+#             */
/*   Updated: 2024/10/04 02:08:35 by etom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	putnbr(size_t nb, char *base)
{
	size_t	b;
	size_t	x;

	x = 0;
	b = ft_strlen_pf(base);
	if (nb > b - 1)
		x += putnbr(nb / b, base);
	x += write(1, &base[nb % b], 1);
	return (x);
}

size_t	prt_p(unsigned long vaarg)
{
	size_t	x;

	x = 0;
	if (vaarg <= 0)
		return (x += (write(1, "(nil)", 5)));
	x += write (1, "0x", 2);
	x += putnbr(vaarg, "0123456789abcdef");
	return (x);
}
