/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal_chck_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkeli <rkeli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 14:14:42 by rkeli             #+#    #+#             */
/*   Updated: 2019/07/19 14:14:42 by rkeli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	octl_chck_flags(int tmplen, unsigned arg, int len, char *in)
{
	if (tmplen <= 0)
	{
		if (g_f->of)
			g_vector = ft_vector(g_vector, "0", 5, 1);
		tmplen = g_f->pre - len - g_f->of + (g_f->pre > 0 && g_f->of && !arg);
		addcharn('0', tmplen);
		if (!(!arg && g_f->dot && !g_f->pre) && !(!arg && g_f->of))
			g_vector = ft_vector(g_vector, in, 5, 0);
	}
	else if (g_f->min)
		o_minus(arg, len, in);
	else if (g_f->dot)
		o_precision(arg, len, in);
	else
		o_zero_and_else(in, tmplen);
	free(in);
}
