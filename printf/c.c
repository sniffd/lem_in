/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkeli <rkeli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 14:12:56 by rkeli             #+#    #+#             */
/*   Updated: 2019/07/19 14:12:56 by rkeli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	character(va_list ap, const char *ch)
{
	char	c;

	c = ch ? *ch : (char)va_arg(ap, int);
	if (c == '\0')
		g_f->flg = 1;
	if (g_f->wid)
	{
		if (g_f->min)
		{
			g_vector = ft_vector(g_vector, &c, 5, 1);
			addcharn(' ', (g_f->wid - 1));
		}
		else
		{
			if (g_f->zer)
				addcharn('0', (g_f->wid - 1));
			else
				addcharn(' ', (g_f->wid - 1));
			g_vector = ft_vector(g_vector, &c, 5, 1);
		}
	}
	else
		g_vector = ft_vector(g_vector, &c, 5, 1);
}
