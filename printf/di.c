/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   di.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkeli <rkeli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 14:13:04 by rkeli             #+#    #+#             */
/*   Updated: 2019/07/19 14:13:04 by rkeli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_sign(long long number, int plu, int spc)
{
	if (number < 0)
		g_vector = ft_vector(g_vector, "-", 5, 0);
	else if (plu)
		g_vector = ft_vector(g_vector, "+", 5, 0);
	else if (spc)
		g_vector = ft_vector(g_vector, " ", 5, 0);
}

void	minus(long long arg, int len, char *in)
{
	int	tmplen;

	print_sign(arg, g_f->plu, g_f->spc);
	tmplen = g_f->pre - len;
	oktotorp(arg);
	if (tmplen <= 0)
	{
		if (g_f->of)
			g_vector = ft_vector(g_vector, "0", 5, 1);
		in = (arg || (!g_f->dot && !g_f->okt) || g_f->pre) ? in : " ";
		if (!(g_f->of && !arg && g_f->dot && !g_f->pre)
		|| (arg || (!g_f->dot && !g_f->okt) || g_f->pre))
			g_vector = ft_vector(g_vector, in, 5, 0);
		tmplen = (g_f->plu || g_f->spc || arg < 0) ? g_f->wid - len - 1 :
			g_f->wid - len;
		addcharn(' ', tmplen);
	}
	else
	{
		addcharn('0', tmplen);
		g_vector = ft_vector(g_vector, in, 5, 0);
		tmplen = (g_f->plu || g_f->spc || arg < 0) ? g_f->wid - g_f->pre - 1 :
			g_f->wid - g_f->pre;
		addcharn(' ', tmplen);
	}
}

void	precision(long long arg, int len, char *in)
{
	int	tmplen;

	if (g_f->pre >= len)
		tmplen = (g_f->plu || g_f->spc || arg < 0) ? g_f->wid - g_f->pre - 1 :
			g_f->wid - g_f->pre;
	else
		tmplen = (g_f->plu || g_f->spc || arg < 0) ? g_f->wid - len - 1 +
			(arg == 0 && g_f->dot) : g_f->wid - len + (arg == 0 && g_f->dot) -
			(g_f->f == 'o' && g_f->okt);
	if_else_precision(tmplen, arg, len, in);
}

void	zero_and_else(long long arg, char *in, int tmplen)
{
	if (g_f->zer && !(g_f->dot))
	{
		print_sign(arg, g_f->plu, g_f->spc);
		oktotorp(arg);
		addcharn('0', tmplen);
		g_vector = ft_vector(g_vector, in, 5, 0);
	}
	else
	{
		addcharn(' ', tmplen);
		print_sign(arg, g_f->plu, g_f->spc);
		oktotorp(arg);
		g_vector = ft_vector(g_vector, in, 5, 0);
	}
}

void	integer(va_list ap)
{
	if (g_f->hh)
		int_char(ap);
	else if (g_f->h)
		int_short(ap);
	else if (g_f->ll)
		int_long_long(ap);
	else if (g_f->l)
		int_long(ap);
	else
		int_int(ap);
}
