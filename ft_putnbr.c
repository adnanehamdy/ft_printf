/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdy <ahamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:07:57 by ahamdy            #+#    #+#             */
/*   Updated: 2021/11/28 15:11:11 by ahamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s, int sum)
{
	if (s)
	{
		while (*s)
			sum = ft_putchar(*s++, sum);
	}
	return (sum);
}

int	ft_string(va_list ap, int sum)
{
	char	*s;

	s = va_arg(ap, char *);
	if (!s)
		sum = ft_putstr("(null)", sum);
	else
		sum = ft_putstr(s, sum);
	return (sum);
}

int	ft_putnbr_address(unsigned long nbr, char *base, int sum)
{
	unsigned long	len;

	len = ft_len(base);
	if (nbr >= len)
	{
		sum = ft_putnbr_address(nbr / len, base, sum);
		return (ft_putchar(base[nbr % len], sum));
	}
	else
		return (ft_putchar(base[nbr], sum));
}

int	ft_hex(va_list ap, char *base, int sum)
{
	unsigned long	i;

	i = (unsigned long)va_arg(ap, void *);
	sum = ft_putstr("0x", sum);
	sum = ft_putnbr_address(i, base, sum);
	return (sum);
}
