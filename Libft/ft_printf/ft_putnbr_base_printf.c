/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_printf.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 12:56:15 by bfaure            #+#    #+#             */
/*   Updated: 2023/01/11 16:32:44 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_strlen_printf(char *base)
{
	size_t	a;

	a = 0;
	while (base[a] != '\0')
		a++;
	return (a);
}

int	ft_putnbr_base_printf(unsigned int nbr, char *base)
{
	unsigned int		len;
	char				nbr_print;
	int					size;

	size = 0;
	len = ft_strlen_printf(base);
	if (nbr < 0)
	{
		size++;
		write(1, "-", 1);
		ft_putnbr_base_printf(nbr *= -1, base);
	}
	else if (nbr >= len)
	{
		size += ft_putnbr_base_printf(nbr / len, base);
		size += ft_putnbr_base_printf(nbr % len, base);
	}
	else
	{
		size++;
		nbr_print = base[nbr];
		write(1, &nbr_print, 1);
	}
	return (size);
}
