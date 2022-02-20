/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdy <ahamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:15:21 by ahamdy            #+#    #+#             */
/*   Updated: 2021/11/24 20:03:34 by ahamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include<unistd.h>
# include<stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_check(const char *str, va_list ap, int sum);
int		ft_putchar(char c, int sum);
int		ft_char(va_list ap, int sum);
int		ft_putnbr(unsigned int nbr, char *base, int sum);
int		ft_putstr(char *s, int sum);
int		ft_int(va_list ap, int sum);
int		ft_len(char *base);
int		ft_putnbr_base(int nbr, char *base, int sum);
int		ft_uphex(va_list ap, char *base, int sum);
int		ft_lwhex(va_list ap, char *base, int sum);
int		ft_string(va_list ap, int sum);
int		ft_hex(va_list ap, char *base, int sum);
int		ft_putnbr_address(unsigned long nbr, char *base, int sum);
int		ft_unsigned(va_list ap, int sum);
#endif