/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_check_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkeli <rkeli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 14:16:11 by rkeli             #+#    #+#             */
/*   Updated: 2019/07/19 14:16:11 by rkeli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	chck_flags(unsigned int arg, int len, char *in, int tmplen)
{
	if (tmplen <= 0)
	{
		tmplen = g_f->pre - len;
		oktotorp(arg);
		addcharn('0', tmplen);
		if (!(!arg && g_f->dot && !g_f->pre))
			g_vector = ft_vector(g_vector, in, 5, 0);
	}
	else if (g_f->min)
		x_minus(arg, len, in);
	else if (g_f->dot)
		x_precision(arg, len, in);
	else
		x_zero_and_else(in, tmplen, arg);
	free(in);
}
