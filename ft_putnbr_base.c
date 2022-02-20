/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdy <ahamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 08:58:29 by ahamdy            #+#    #+#             */
/*   Updated: 2021/11/25 10:10:07 by ahamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_len(char *base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

int	ft_putnbr(unsigned int nbr, char *base, int sum)
{
	unsigned int	len;

	len = ft_len(base);
	if (nbr >= len)
	{
		sum = ft_putnbr(nbr / len, base, sum);
		return (ft_putchar(base[nbr % len], sum));
	}
	else
		return (ft_putchar(base[nbr], sum));
}

int	ft_putnbr_base(int nbr, char *base, int sum)
{
	int				len;
	unsigned int	nbr_plus;

	len = ft_len(base);
	if (nbr == -2147483648 || (nbr < 0 && len == 16))
	{
		if (nbr == -2147483648 && len != 16)
			sum = ft_putchar('-', sum);
		nbr_plus = (unsigned int)nbr;
		return (ft_putnbr(nbr_plus, base, sum));
	}
	if (nbr < 0)
	{
		sum = ft_putchar('-', sum);
		return (ft_putnbr_base(nbr * (-1), base, sum));
	}
	else if (nbr >= len)
	{
		sum = ft_putnbr_base(nbr / len, base, sum);
		return (ft_putchar(base[nbr % len], sum));
	}
	else
		return (ft_putchar(base[nbr], sum));
}

int	ft_unsigned(va_list ap, int sum)
{
	unsigned int	i;

	i = va_arg(ap, unsigned int);
	sum = ft_putnbr(i, "0123456789", sum);
	return (sum);
}
