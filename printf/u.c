/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkeli <rkeli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 14:15:41 by rkeli             #+#    #+#             */
/*   Updated: 2019/07/19 14:15:41 by rkeli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	uinteger(va_list ap)
{
	g_f->plu = 0;
	g_f->spc = 0;
	if (g_f->hh)
		uint_char(ap);
	else if (g_f->h)
		uint_short(ap);
	else if (g_f->ll)
		uint_long_long(ap);
	else if (g_f->l)
		uint_long(ap);
	else
		uint_int(ap);
}
