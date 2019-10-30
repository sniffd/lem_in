/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkeli <rkeli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 14:12:35 by rkeli             #+#    #+#             */
/*   Updated: 2019/07/19 14:12:35 by rkeli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	big_x_char(va_list ap)
{
	char			*in;
	int				tmplen;
	int				len;
	unsigned int	arg;

	arg = (unsigned char)va_arg(ap, unsigned int);
	in = ft_itoa_base(arg, 16);
	len = (int)ft_strlen(in);
	tmplen = g_f->wid - (len * !(!arg && g_f->dot && !g_f->pre)) + (!arg
	&& g_f->dot && !g_f->pre) - (g_f->okt && arg) * 2 - (!arg && g_f->okt
	&& g_f->dot && !g_f->pre) - (g_f->pre - len * (g_f->pre - 1 > 0))
			* (g_f->pre > len + (g_f->okt && arg) * 2);
	chck_flags(arg, len, in, tmplen);
}

void	big_x_short(va_list ap)
{
	char			*in;
	int				tmplen;
	int				len;
	unsigned int	arg;

	arg = (unsigned short)va_arg(ap, unsigned int);
	in = ft_itoa_base(arg, 16);
	len = (int)ft_strlen(in);
	tmplen = g_f->wid - (len * !(!arg && g_f->dot && !g_f->pre)) + (!arg
	&& g_f->dot && !g_f->pre) - (g_f->okt && arg) * 2 - (!arg && g_f->okt
	&& g_f->dot && !g_f->pre) - (g_f->pre - len * (g_f->pre - 1 > 0))
			* (g_f->pre > len + (g_f->okt && arg) * 2);
	chck_flags(arg, len, in, tmplen);
}

void	big_x_int(va_list ap)
{
	char			*in;
	int				tmplen;
	int				len;
	unsigned int	arg;

	arg = va_arg(ap, unsigned int);
	in = ft_itoa_base(arg, 16);
	len = (int)ft_strlen(in);
	tmplen = g_f->wid - (len * !(!arg && g_f->dot && !g_f->pre)) + (!arg
	&& g_f->dot && !g_f->pre) - (g_f->okt && arg) * 2 - (!arg && g_f->okt
	&& g_f->dot && !g_f->pre) - (g_f->pre - len * (g_f->pre - 1 > 0))
			* (g_f->pre > len + (g_f->okt && arg) * 2);
	chck_flags(arg, len, in, tmplen);
}

void	big_x_long(va_list ap)
{
	char			*in;
	int				tmplen;
	int				len;
	unsigned long	arg;

	arg = va_arg(ap, unsigned long);
	in = ft_itoa_base(arg, 16);
	len = (int)ft_strlen(in);
	tmplen = g_f->wid - (len * !(!arg && g_f->dot && !g_f->pre)) + (!arg
	&& g_f->dot && !g_f->pre) - (g_f->okt && arg) * 2 - (!arg && g_f->okt
	&& g_f->dot && !g_f->pre) - (g_f->pre - len * (g_f->pre - 1 > 0))
			* (g_f->pre > len + (g_f->okt && arg) * 2);
	chck_flags(arg, len, in, tmplen);
}

void	big_x_long_long(va_list ap)
{
	char			*in;
	int				tmplen;
	int				len;
	unsigned long	arg;

	arg = va_arg(ap, unsigned long long);
	in = ft_itoa_base(arg, 16);
	len = (int)ft_strlen(in);
	tmplen = g_f->wid - (len * !(!arg && g_f->dot && !g_f->pre)) + (!arg
	&& g_f->dot && !g_f->pre) - (g_f->okt && arg) * 2 - (!arg && g_f->okt
	&& g_f->dot && !g_f->pre) - (g_f->pre - len * (g_f->pre - 1 > 0))
			* (g_f->pre > len + (g_f->okt && arg) * 2);
	chck_flags(arg, len, in, tmplen);
}
