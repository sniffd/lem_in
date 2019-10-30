/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oflags.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkeli <rkeli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 14:14:47 by rkeli             #+#    #+#             */
/*   Updated: 2019/07/19 14:14:47 by rkeli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	o_minus(unsigned long long arg, int len, char *in)
{
	int	tmplen;

	tmplen = g_f->pre - len;
	if (tmplen <= 0)
	{
		if (g_f->of)
			g_vector = ft_vector(g_vector, "0", 5, 1);
		if (!(!arg && g_f->dot && !g_f->pre) && !(!arg && g_f->of))
			g_vector = ft_vector(g_vector, in, 5, 0);
		tmplen = g_f->wid - len + (!arg && g_f->dot && !g_f->pre) - (g_f->of
				&& arg) - (!arg && g_f->of && g_f->dot && !g_f->pre);
		addcharn(' ', tmplen);
	}
	else
	{
		addcharn('0', tmplen);
		g_vector = ft_vector(g_vector, in, 5, 0);
		tmplen = g_f->wid - g_f->pre;
		addcharn(' ', tmplen);
	}
}

void	o_precision(unsigned long long arg, int len, char *in)
{
	int	tmplen;

	if (g_f->pre >= len)
		tmplen = g_f->wid - g_f->pre + (!arg && g_f->dot && !g_f->pre)
				- (g_f->of && g_f->dot && !g_f->pre);
	else
		tmplen = g_f->wid - len + (!arg && g_f->dot && !g_f->pre) - (g_f->of
				&& g_f->dot && !g_f->pre && !arg) - (g_f->of && arg);
	o_if_else_precison(tmplen, arg, len, in);
}

void	o_zero_and_else(char *in, int tmplen)
{
	if (g_f->zer && !(g_f->dot))
	{
		addcharn('0', tmplen);
		g_vector = ft_vector(g_vector, in, 5, 0);
	}
	else
	{
		addcharn(' ', tmplen);
		if (g_f->of)
			g_vector = ft_vector(g_vector, "0", 5, 1);
		g_vector = ft_vector(g_vector, in, 5, 0);
	}
}
