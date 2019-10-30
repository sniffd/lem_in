/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uflags.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkeli <rkeli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 14:15:46 by rkeli             #+#    #+#             */
/*   Updated: 2019/07/19 14:15:46 by rkeli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	u_print_sign(int plu, int spc)
{
	if (plu)
		g_vector = ft_vector(g_vector, "+", 5, 0);
	else if (spc)
		g_vector = ft_vector(g_vector, " ", 5, 0);
}

void	u_minus(unsigned long long arg, int len, char *in)
{
	int	tmplen;

	u_print_sign(g_f->plu, g_f->spc);
	tmplen = g_f->pre - len;
	oktotorp(arg);
	if (tmplen <= 0)
	{
		in = !(g_f->dot && !arg) ? in : " ";
		g_vector = ft_vector(g_vector, in, 5, 0);
		tmplen = (g_f->plu || g_f->spc) ? g_f->wid - len - 1 :
				g_f->wid - len;
		addcharn(' ', tmplen);
	}
	else
	{
		addcharn('0', tmplen);
		g_vector = ft_vector(g_vector, in, 5, 0);
		tmplen = (g_f->plu || g_f->spc) ? g_f->wid - g_f->pre - 1 :
				g_f->wid - g_f->pre;
		addcharn(' ', tmplen);
	}
}

void	u_precision(unsigned long long arg, int len, char *in)
{
	int	tmplen;

	if (g_f->pre >= len)
		tmplen = (g_f->plu || g_f->spc) ? g_f->wid - g_f->pre - 1 :
				g_f->wid - g_f->pre;
	else
		tmplen = (g_f->plu || g_f->spc) ? g_f->wid - len - 1 +
			(arg == 0 && g_f->dot) : g_f->wid - len + (arg == 0 && g_f->dot);
	if (tmplen <= 0 && oktotorp(arg))
	{
		tmplen = g_f->pre - len;
		u_print_sign(g_f->plu, g_f->spc);
		addcharn('0', tmplen);
		g_vector = ft_vector(g_vector, in, 5, 0);
	}
	else
	{
		addcharn(' ', tmplen);
		tmplen = g_f->pre - len;
		u_print_sign(g_f->plu, g_f->spc);
		oktotorp(arg);
		addcharn('0', tmplen);
		in = !(!g_f->pre && !arg) ? in : "";
		g_vector = ft_vector(g_vector, in, 5, 0);
	}
}

void	u_zero_and_else(unsigned long long arg, char *in, int tmplen)
{
	if (g_f->zer && !(g_f->dot))
	{
		u_print_sign(g_f->plu, g_f->spc);
		oktotorp(arg);
		addcharn('0', tmplen);
		g_vector = ft_vector(g_vector, in, 5, 0);
	}
	else
	{
		addcharn(' ', tmplen);
		u_print_sign(g_f->plu, g_f->spc);
		oktotorp(arg);
		g_vector = ft_vector(g_vector, in, 5, 0);
	}
}
