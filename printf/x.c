/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkeli <rkeli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 14:16:07 by rkeli             #+#    #+#             */
/*   Updated: 2019/07/19 14:16:07 by rkeli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	big_hex(va_list ap)
{
	if (g_f->hh)
		big_x_char(ap);
	else if (g_f->h)
		big_x_short(ap);
	else if (g_f->ll)
		big_x_long_long(ap);
	else if (g_f->l)
		big_x_long(ap);
	else
		big_x_int(ap);
}

void	hex(va_list ap)
{
	if (g_f->hh)
		x_char(ap);
	else if (g_f->h)
		x_short(ap);
	else if (g_f->ll)
		x_long_long(ap);
	else if (g_f->l || g_f->f == 'p')
		x_long(ap);
	else
		x_int(ap);
}
