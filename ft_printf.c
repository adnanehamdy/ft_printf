/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdy <ahamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:02:05 by ahamdy            #+#    #+#             */
/*   Updated: 2021/11/28 14:52:14 by ahamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include<stdio.h>

int	ft_check(const char *str, va_list ap, int sum)
{
	int	i;

	i = 0;
	if (str[i] == 'c')
		sum = ft_char(ap, sum);
	else if (str[i] == 'd' || str[i] == 'i')
		sum = ft_int(ap, sum);
	else if (str[i] == 'X')
		sum = ft_uphex(ap, "0123456789ABCDEF", sum);
	else if (str[i] == 'x')
		sum = ft_lwhex(ap, "0123456789abcdef", sum);
	else if (str[i] == 's')
		sum = ft_string(ap, sum);
	else if (str[i] == 'u')
		sum = ft_unsigned(ap, sum);
	else if (str[i] == 'p')
		sum = ft_hex(ap, "0123456789abcdef", sum);
	else
		sum = ft_putchar(str[i], sum);
	return (sum);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		sum;

	i = 0;
	sum = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] != '%')
			sum = ft_putchar(str[i], sum);
		else
			sum = ft_check(&str[++i], ap, sum);
		i++;
	}
	va_end(ap);
	return (sum);
}
