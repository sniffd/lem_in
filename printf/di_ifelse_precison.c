/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   di_ifelse_precison.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkeli <rkeli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 14:13:08 by rkeli             #+#    #+#             */
/*   Updated: 2019/07/19 14:13:08 by rkeli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	if_else_precision(int tmplen, long long arg, int len, char *in)
{
	if (tmplen <= 0 && oktotorp(arg))
	{
		tmplen = (g_f->of && g_f->pre - len < 0) ? 1 : g_f->pre - len;
		print_sign(arg, g_f->plu, g_f->spc);
		addcharn('0', tmplen);
		if (!(!g_f->pre && !arg && g_f->dot))
			g_vector = ft_vector(g_vector, in, 5, 0);
	}
	else
	{
		addcharn(' ', tmplen);
		tmplen = (g_f->of && g_f->pre - len < 0) ? 1 : g_f->pre - len;
		print_sign(arg, g_f->plu, g_f->spc);
		oktotorp(arg);
		addcharn('0', tmplen);
		in = (arg || (!g_f->dot && !g_f->okt) || g_f->pre) ? in : "";
		g_vector = ft_vector(g_vector, in, 5, 0);
	}
}

void	o_if_else_precison(int tmplen, unsigned long long arg, int len,
			char *in)
{
	if (tmplen <= 0)
	{
		if (g_f->of)
			g_vector = ft_vector(g_vector, "0", 5, 1);
		tmplen = g_f->pre - len - g_f->of;
		addcharn('0', tmplen);
		if (!(!arg && g_f->dot && !g_f->pre))
			g_vector = ft_vector(g_vector, in, 5, 0);
	}
	else
	{
		addcharn(' ', tmplen);
		if (g_f->of)
			g_vector = ft_vector(g_vector, "0", 5, 1);
		tmplen = g_f->pre - len - g_f->of;
		addcharn('0', tmplen);
		if (!(!arg && g_f->dot && !g_f->pre))
			g_vector = ft_vector(g_vector, in, 5, 0);
	}
}

void	if_wid_less_zero(void)
{
	if (g_f->wid < 0)
	{
		g_f->wid = -g_f->wid;
		g_f->min = 1;
	}
}

void	okt_and_dot_and_pre(void)
{
	if (g_f->okt && g_f->dot && !g_f->pre)
		g_vector = ft_vector(g_vector, ".", 5, 0);
}
