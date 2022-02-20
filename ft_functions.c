/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdy <ahamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:50:54 by ahamdy            #+#    #+#             */
/*   Updated: 2021/11/25 10:05:50 by ahamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c, int sum)
{
	write(1, &c, 1);
	sum++;
	return (sum);
}

int	ft_char(va_list ap, int sum)
{
	char	c;

	c = va_arg(ap, int);
	sum = ft_putchar(c, sum);
	return (sum);
}

int	ft_int(va_list ap, int sum)
{
	int	i;
	int	d;

	i = va_arg(ap, int);
	d = 0;
	sum = ft_putnbr_base(i, "0123456789", sum);
	return (sum);
}

int	ft_uphex(va_list ap, char *base, int sum)
{
	int	i;

	i = va_arg(ap, int);
	sum = ft_putnbr_base(i, base, sum);
	return (sum);
}

int	ft_lwhex(va_list ap, char *base, int sum)
{
	int	i;

	i = va_arg(ap, int);
	sum = ft_putnbr_base(i, base, sum);
	return (sum);
}
