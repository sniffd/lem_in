/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkeli <rkeli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 14:14:02 by rkeli             #+#    #+#             */
/*   Updated: 2019/07/19 14:14:02 by rkeli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	int_char(va_list ap)
{
	char	*in;
	int		tmplen;
	int		len;
	int		arg;

	arg = (char)va_arg(ap, int);
	in = ft_stoa(ft_abs(arg));
	len = (int)ft_strlen(in);
	tmplen = (g_f->plu || g_f->spc || arg < 0) ? g_f->wid - len - 1 +
			(arg == 0 && g_f->dot) : g_f->wid - len + (arg == 0 && g_f->dot);
	if (tmplen <= 0)
	{
		print_sign(arg, g_f->plu, g_f->spc);
		tmplen = g_f->pre - len;
		addcharn('0', tmplen);
		if (!(!g_f->pre && !arg && g_f->dot))
			g_vector = ft_vector(g_vector, in, 5, 0);
	}
	else if (g_f->min)
		minus(arg, len, in);
	else if (g_f->dot)
		precision(arg, len, in);
	else
		zero_and_else(arg, in, tmplen);
	free(in);
}

void	int_short(va_list ap)
{
	char	*in;
	int		tmplen;
	int		len;
	int		arg;

	arg = (short)va_arg(ap, int);
	in = ft_stoa(ft_abs(arg));
	len = (int)ft_strlen(in);
	tmplen = (g_f->plu || g_f->spc || arg < 0) ? g_f->wid - len - 1 +
			(arg == 0 && g_f->dot) : g_f->wid - len + (arg == 0 && g_f->dot);
	if (tmplen <= 0)
	{
		print_sign(arg, g_f->plu, g_f->spc);
		tmplen = g_f->pre - len;
		addcharn('0', tmplen);
		if (!(!g_f->pre && !arg && g_f->dot))
			g_vector = ft_vector(g_vector, in, 5, 0);
	}
	else if (g_f->min)
		minus(arg, len, in);
	else if (g_f->dot)
		precision(arg, len, in);
	else
		zero_and_else(arg, in, tmplen);
	free(in);
}

void	int_int(va_list ap)
{
	char	*in;
	int		tmplen;
	int		len;
	int		arg;

	arg = va_arg(ap, int);
	in = ft_stoa(ft_abs(arg));
	len = (int)ft_strlen(in);
	tmplen = (g_f->plu || g_f->spc || arg < 0) ? g_f->wid - len - 1 +
			(arg == 0 && g_f->dot) : g_f->wid - len + (arg == 0 && g_f->dot);
	if (tmplen <= 0)
	{
		print_sign(arg, g_f->plu, g_f->spc);
		tmplen = g_f->pre - len;
		addcharn('0', tmplen);
		if (!(!g_f->pre && !arg && g_f->dot))
			g_vector = ft_vector(g_vector, in, 5, 0);
	}
	else if (g_f->min)
		minus(arg, len, in);
	else if (g_f->dot)
		precision(arg, len, in);
	else
		zero_and_else(arg, in, tmplen);
	free(in);
}

void	int_long(va_list ap)
{
	char	*in;
	int		tmplen;
	int		len;
	long	arg;

	arg = va_arg(ap, long);
	in = ft_stoa(ft_abs(arg));
	len = (int)ft_strlen(in);
	tmplen = (g_f->plu || g_f->spc || arg < 0) ? g_f->wid - len - 1 +
			(arg == 0 && g_f->dot) : g_f->wid - len + (arg == 0 && g_f->dot);
	if (tmplen <= 0)
	{
		print_sign(arg, g_f->plu, g_f->spc);
		tmplen = g_f->pre - len;
		addcharn('0', tmplen);
		if (!(!g_f->pre && !arg && g_f->dot))
			g_vector = ft_vector(g_vector, in, 5, 0);
	}
	else if (g_f->min)
		minus(arg, len, in);
	else if (g_f->dot)
		precision(arg, len, in);
	else
		zero_and_else(arg, in, tmplen);
	free(in);
}

void	int_long_long(va_list ap)
{
	char		*in;
	int			tmplen;
	int			len;
	long long	arg;

	arg = va_arg(ap, long long);
	in = ft_stoa(ft_abs(arg));
	len = (int)ft_strlen(in);
	tmplen = (g_f->plu || g_f->spc || arg < 0) ? g_f->wid - len - 1 +
			(arg == 0 && g_f->dot) : g_f->wid - len + (arg == 0 && g_f->dot);
	if (tmplen <= 0)
	{
		print_sign(arg, g_f->plu, g_f->spc);
		tmplen = g_f->pre - len;
		addcharn('0', tmplen);
		if (!(!g_f->pre && !arg && g_f->dot))
			g_vector = ft_vector(g_vector, in, 5, 0);
	}
	else if (g_f->min)
		minus(arg, len, in);
	else if (g_f->dot)
		precision(arg, len, in);
	else
		zero_and_else(arg, in, tmplen);
	free(in);
}
