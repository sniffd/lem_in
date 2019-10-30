/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkeli <rkeli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 14:12:44 by rkeli             #+#    #+#             */
/*   Updated: 2019/07/19 14:12:44 by rkeli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	b_char(va_list ap)
{
	char			*in;
	int				tmplen;
	int				len;
	unsigned int	arg;

	arg = (unsigned char)va_arg(ap, unsigned int);
	in = ft_strtolower(ft_itoa_base(arg, 2));
	len = (int)ft_strlen(in);
	g_f->wid = (g_f->okt || g_f->f == 'p') && arg && ((--g_f->wid || 1) &&
	(!--g_f->wid || 1)) ? g_f->wid : g_f->wid;
	tmplen = g_f->wid - len;
	if (tmplen <= 0)
	{
		tmplen = g_f->pre - len;
		oktotorp(arg);
		addcharn('0', tmplen);
		if (!(!g_f->pre && !arg))
			g_vector = ft_vector(g_vector, in, 5, 0);
	}
	else if (g_f->min)
		minus(arg, len, in);
	else if (g_f->dot)
		precision(arg, len, in);
	else
		zero_and_else(arg, in, tmplen);
}

void	b_short(va_list ap)
{
	char			*in;
	int				tmplen;
	int				len;
	unsigned int	arg;

	arg = (unsigned short)va_arg(ap, unsigned int);
	in = ft_strtolower(ft_itoa_base(arg, 2));
	len = (int)ft_strlen(in);
	g_f->wid = (g_f->okt || g_f->f == 'p') && arg && ((--g_f->wid || 1) &&
	(!--g_f->wid || 1)) ? g_f->wid : g_f->wid;
	tmplen = g_f->wid - len;
	if (tmplen <= 0)
	{
		tmplen = g_f->pre - len;
		oktotorp(arg);
		addcharn('0', tmplen);
		if (!(!g_f->pre && !arg))
			g_vector = ft_vector(g_vector, in, 5, 0);
	}
	else if (g_f->min)
		minus(arg, len, in);
	else if (g_f->dot)
		precision(arg, len, in);
	else
		zero_and_else(arg, in, tmplen);
}

void	b_int(va_list ap)
{
	char			*in;
	int				tmplen;
	int				len;
	unsigned int	arg;

	arg = va_arg(ap, unsigned int);
	in = ft_strtolower(ft_itoa_base(arg, 2));
	len = (int)ft_strlen(in);
	g_f->wid = (g_f->okt || g_f->f == 'p') && arg && ((--g_f->wid || 1) &&
	(!--g_f->wid || 1)) ? g_f->wid : g_f->wid;
	tmplen = g_f->wid - len;
	if (tmplen <= 0)
	{
		tmplen = g_f->pre - len;
		oktotorp(arg);
		addcharn('0', tmplen);
		if (!(!g_f->pre && !arg))
			g_vector = ft_vector(g_vector, in, 5, 0);
	}
	else if (g_f->min)
		minus(arg, len, in);
	else if (g_f->dot)
		precision(arg, len, in);
	else
		zero_and_else(arg, in, tmplen);
}

void	b_long(va_list ap)
{
	char			*in;
	int				tmplen;
	int				len;
	unsigned long	arg;

	arg = va_arg(ap, unsigned long);
	in = ft_strtolower(ft_itoa_base(arg, 2));
	len = (int)ft_strlen(in);
	g_f->wid = (g_f->okt || g_f->f == 'p') && arg && ((--g_f->wid || 1) &&
	(!--g_f->wid || 1)) ? g_f->wid : g_f->wid;
	tmplen = g_f->wid - len;
	if (tmplen <= 0)
	{
		tmplen = g_f->pre - len;
		oktotorp(arg);
		addcharn('0', tmplen);
		if (!(!g_f->pre && !arg))
			g_vector = ft_vector(g_vector, in, 5, 0);
	}
	else if (g_f->min)
		minus(arg, len, in);
	else if (g_f->dot)
		precision(arg, len, in);
	else
		zero_and_else(arg, in, tmplen);
}

void	b_long_long(va_list ap)
{
	char			*in;
	int				tmplen;
	int				len;
	unsigned long	arg;

	arg = va_arg(ap, unsigned long long);
	in = ft_strtolower(ft_itoa_base(arg, 2));
	len = (int)ft_strlen(in);
	g_f->wid = (g_f->okt || g_f->f == 'p') && arg && ((--g_f->wid || 1) &&
	(!--g_f->wid || 1)) ? g_f->wid : g_f->wid;
	tmplen = g_f->wid - len;
	if (tmplen <= 0)
	{
		tmplen = g_f->pre - len;
		oktotorp(arg);
		addcharn('0', tmplen);
		if (!(!g_f->pre && !arg))
			g_vector = ft_vector(g_vector, in, 5, 0);
	}
	else if (g_f->min)
		minus(arg, len, in);
	else if (g_f->dot)
		precision(arg, len, in);
	else
		zero_and_else(arg, in, tmplen);
}
