/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xflags.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkeli <rkeli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 14:16:16 by rkeli             #+#    #+#             */
/*   Updated: 2019/07/19 14:16:16 by rkeli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	x_minus(unsigned long long arg, int len, char *in)
{
	int	tmplen;

	tmplen = g_f->pre - len;
	if (tmplen <= 0)
	{
		oktotorp(arg);
		if (!(!arg && g_f->dot && !g_f->pre))
			g_vector = ft_vector(g_vector, in, 5, 0);
		tmplen = g_f->wid - (len * !(!arg && g_f->dot && !g_f->pre))
				- (g_f->f == 'p' || (g_f->okt && arg)) * 2;
		addcharn(' ', tmplen);
	}
	else
	{
		oktotorp(arg);
		addcharn('0', tmplen);
		g_vector = ft_vector(g_vector, in, 5, 0);
		tmplen = g_f->wid - g_f->pre - ((g_f->okt || g_f->f == 'p') && arg) * 2;
		addcharn(' ', tmplen);
	}
}

void	x_precision(unsigned long long arg, int len, char *in)
{
	int	tmplen;

	if (g_f->pre >= len)
		tmplen = g_f->wid - g_f->pre + (!arg && g_f->dot && !g_f->pre)
				- ((g_f->okt || g_f->f == 'p') && g_f->dot && arg) * 2;
	else
		tmplen = g_f->wid - len + (!arg && g_f->dot && !g_f->pre)
				- ((g_f->okt || g_f->f == 'p') && g_f->dot && arg) * 2;
	if (tmplen <= 0)
	{
		oktotorp(arg);
		tmplen = g_f->pre - len - g_f->okt;
		addcharn('0', tmplen);
		if (!(!arg && g_f->dot && !g_f->pre))
			g_vector = ft_vector(g_vector, in, 5, 0);
	}
	else
	{
		addcharn(' ', tmplen);
		oktotorp(arg);
		tmplen = g_f->pre - len;
		addcharn('0', tmplen);
		if (!(!arg && g_f->dot && !g_f->pre))
			g_vector = ft_vector(g_vector, in, 5, 0);
	}
}

void	x_zero_and_else(char *in, int tmplen, unsigned long long arg)
{
	if (g_f->zer && !(g_f->dot))
	{
		oktotorp(arg);
		addcharn('0', tmplen);
		g_vector = ft_vector(g_vector, in, 5, 0);
	}
	else
	{
		addcharn(' ', tmplen);
		oktotorp(arg);
		g_vector = ft_vector(g_vector, in, 5, 0);
	}
}
