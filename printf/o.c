/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkeli <rkeli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 14:14:28 by rkeli             #+#    #+#             */
/*   Updated: 2019/07/19 14:14:28 by rkeli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	octal(va_list ap)
{
	if (g_f->hh)
		o_char(ap);
	else if (g_f->h)
		o_short(ap);
	else if (g_f->ll)
		o_long_long(ap);
	else if (g_f->l)
		o_long(ap);
	else
		o_int(ap);
}
