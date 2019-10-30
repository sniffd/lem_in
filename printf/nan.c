/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nan.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkeli <rkeli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 14:14:23 by rkeli             #+#    #+#             */
/*   Updated: 2019/07/19 14:14:23 by rkeli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			all_ones(struct s_double d)
{
	if (!(d.m & (3UL << 62)))
	{
		if (!(d.m & ((~0UL) >> 2)))
			return (INF);
		else
			return (NAN);
	}
	else if (((d.m & (3UL << 62)) >> 62) == 1)
		return (NAN);
	else if (((d.m & (3UL << 62)) >> 62) == 2)
	{
		if (!(d.m & (~(3UL << 62))))
			return (INF);
		else
			return (NAN);
	}
	else
		return (NAN);
}

int			normal_check(struct s_double d)
{
	if (d.e == 0)
	{
		if (d.m & (1UL << 63))
			return (DENORM);
		else if (d.m & (~(1UL << 63)))
			return (DENORM);
		else
			return (NORM);
	}
	else if (d.e == 32767)
		return (all_ones(d));
	else
		return (NORM);
}

void		wid(char sign, char *s)
{
	if (g_f->min)
	{
		f_print_sign(sign, g_f->plu, g_f->spc);
		g_vector = ft_vector(g_vector, s, 5, 0);
		addcharn(' ', (g_f->wid - (3 + (sign || g_f->plu || g_f->spc))));
	}
	else
	{
		addcharn(' ', (g_f->wid - (3 + (sign || g_f->plu || g_f->spc))));
		f_print_sign(sign, g_f->plu, g_f->spc);
		g_vector = ft_vector(g_vector, s, 5, 0);
	}
}

void		print_nan(int nan, char sign)
{
	char	*s;

	if (nan == NAN)
	{
		s = "nan";
		sign = 0;
		g_f->plu = 0;
		g_f->spc = 0;
	}
	else
		s = "inf";
	if (g_f->wid)
		wid(sign, s);
	else
	{
		f_print_sign(sign, g_f->plu, g_f->spc);
		g_vector = ft_vector(g_vector, s, 5, 0);
	}
}
