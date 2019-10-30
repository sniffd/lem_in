/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkeli <rkeli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 14:13:13 by rkeli             #+#    #+#             */
/*   Updated: 2019/07/19 14:13:13 by rkeli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	norm_or_denorm(t_double d)
{
	t_bigint	whole;
	t_bigint	fraction;

	if (normal_check(d.s) == DENORM)
		d.s.e = 1;
	if (d.s.e - 16383 >= 63)
	{
		whole = get_whole(d.s.m, d.s.e - 16383);
		fraction = get_null();
		fraction.num[0] = 10;
	}
	else if (d.s.e - 16383 < 0)
	{
		fraction = get_fraction(d.s.m, d.s.e - 16383);
		whole = get_null();
	}
	else
	{
		whole = get_whole((d.s.m >> (64 - (d.s.e - 16383 + 1))),
				(d.s.e - 16383 + 64 - (d.s.e - 16383 + 1)));
		fraction = get_fraction((d.s.m << (64 - (64 - (d.s.e - 16383 + 1))))
				, d.s.e - 16383 - (d.s.e - 16383 + 1));
	}
	whole.sign = d.s.s;
	f_round(whole, fraction);
}

void	f_double(va_list ap)
{
	t_double	d;

	d.d = va_arg(ap, double);
	if (!g_f->dot)
	{
		g_f->dot = 1;
		g_f->pre = 6;
	}
	if (normal_check(d.s) == NAN || normal_check(d.s) == INF)
		print_nan(normal_check(d.s), d.s.s);
	else
		norm_or_denorm(d);
}

void	f_long_double(va_list ap)
{
	t_double	d;

	d.d = va_arg(ap, long double);
	if (!g_f->dot)
	{
		g_f->dot = 1;
		g_f->pre = 6;
	}
	if (normal_check(d.s) == NAN || normal_check(d.s) == INF)
		print_nan(normal_check(d.s), d.s.s);
	else
		norm_or_denorm(d);
}

void	f_f(va_list ap)
{
	if (g_f->bl)
		f_long_double(ap);
	else
		f_double(ap);
}
