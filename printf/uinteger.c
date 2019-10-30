/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uinteger.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkeli <rkeli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 14:15:57 by rkeli             #+#    #+#             */
/*   Updated: 2019/07/19 14:15:57 by rkeli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	uint_char(va_list ap)
{
	char			*in;
	int				tmplen;
	int				len;
	unsigned int	arg;

	arg = (unsigned char)va_arg(ap, unsigned int);
	in = ft_stoa(arg);
	len = (int)ft_strlen(in);
	tmplen = (g_f->plu || g_f->spc) ? g_f->wid - len - 1 +
			(arg == 0 && g_f->dot) : g_f->wid - len + (arg == 0 && g_f->dot);
	if (tmplen <= 0)
	{
		u_print_sign(g_f->plu, g_f->spc);
		tmplen = g_f->pre - len;
		addcharn('0', tmplen);
		if (!(!g_f->pre && !arg && g_f->dot))
			g_vector = ft_vector(g_vector, in, 5, 0);
	}
	else if (g_f->min)
		u_minus(arg, len, in);
	else if (g_f->dot)
		u_precision(arg, len, in);
	else
		u_zero_and_else(arg, in, tmplen);
	free(in);
}

void	uint_short(va_list ap)
{
	char			*in;
	int				tmplen;
	int				len;
	unsigned int	arg;

	arg = (unsigned short)va_arg(ap, unsigned int);
	in = ft_stoa(arg);
	len = (int)ft_strlen(in);
	tmplen = (g_f->plu || g_f->spc) ? g_f->wid - len - 1 +
			(arg == 0 && g_f->dot) : g_f->wid - len + (arg == 0 && g_f->dot);
	if (tmplen <= 0)
	{
		u_print_sign(g_f->plu, g_f->spc);
		tmplen = g_f->pre - len;
		addcharn('0', tmplen);
		if (!(!g_f->pre && !arg && g_f->dot))
			g_vector = ft_vector(g_vector, in, 5, 0);
	}
	else if (g_f->min)
		u_minus(arg, len, in);
	else if (g_f->dot)
		u_precision(arg, len, in);
	else
		u_zero_and_else(arg, in, tmplen);
	free(in);
}

void	uint_int(va_list ap)
{
	char			*in;
	int				tmplen;
	int				len;
	unsigned int	arg;

	arg = va_arg(ap, unsigned int);
	in = ft_stoa((unsigned int)arg);
	len = (int)ft_strlen(in);
	tmplen = (g_f->plu || g_f->spc) ? g_f->wid - len - 1 +
			(arg == 0 && g_f->dot) : g_f->wid - len + (arg == 0 && g_f->dot);
	if (tmplen <= 0)
	{
		u_print_sign(g_f->plu, g_f->spc);
		tmplen = g_f->pre - len;
		addcharn('0', tmplen);
		if (!(!g_f->pre && !arg && g_f->dot))
			g_vector = ft_vector(g_vector, in, 5, 0);
	}
	else if (g_f->min)
		u_minus(arg, len, in);
	else if (g_f->dot)
		u_precision(arg, len, in);
	else
		u_zero_and_else(arg, in, tmplen);
	free(in);
}

void	uint_long(va_list ap)
{
	char			*in;
	int				tmplen;
	int				len;
	unsigned long	arg;

	arg = va_arg(ap, unsigned long);
	in = ft_stoa((unsigned long)arg);
	len = (int)ft_strlen(in);
	tmplen = (g_f->plu || g_f->spc) ? g_f->wid - len - 1 +
			(arg == 0 && g_f->dot) : g_f->wid - len + (arg == 0 && g_f->dot);
	if (tmplen <= 0)
	{
		u_print_sign(g_f->plu, g_f->spc);
		tmplen = g_f->pre - len;
		addcharn('0', tmplen);
		if (!(!g_f->pre && !arg && g_f->dot))
			g_vector = ft_vector(g_vector, in, 5, 0);
	}
	else if (g_f->min)
		u_minus(arg, len, in);
	else if (g_f->dot)
		u_precision(arg, len, in);
	else
		u_zero_and_else(arg, in, tmplen);
	free(in);
}

void	uint_long_long(va_list ap)
{
	char				*in;
	int					tmplen;
	int					len;
	unsigned long long	arg;

	arg = va_arg(ap, unsigned long long);
	in = ft_stoa(arg);
	len = (int)ft_strlen(in);
	tmplen = (g_f->plu || g_f->spc) ? g_f->wid - len - 1 +
			(arg == 0 && g_f->dot) : g_f->wid - len + (arg == 0 && g_f->dot);
	if (tmplen <= 0)
	{
		u_print_sign(g_f->plu, g_f->spc);
		tmplen = g_f->pre - len;
		addcharn('0', tmplen);
		if (!(!g_f->pre && !arg && g_f->dot))
			g_vector = ft_vector(g_vector, in, 5, 0);
	}
	else if (g_f->min)
		u_minus(arg, len, in);
	else if (g_f->dot)
		u_precision(arg, len, in);
	else
		u_zero_and_else(arg, in, tmplen);
	free(in);
}
