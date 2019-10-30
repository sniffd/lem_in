/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkeli <rkeli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 14:15:33 by rkeli             #+#    #+#             */
/*   Updated: 2019/07/19 14:15:33 by rkeli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	string(va_list ap)
{
	size_t	len;
	char	*s;

	s = va_arg(ap, char *);
	if (!s)
		s = "(null)";
	len = ft_strlen(s);
	len = (len > (size_t)g_f->pre) && g_f->dot ? g_f->pre : len;
	if (g_f->wid)
	{
		if (g_f->min)
		{
			g_vector = ft_vector(g_vector, s, 5, len);
			addcharn(' ', (g_f->wid - len));
		}
		else
		{
			g_f->zer ? addcharn('0', (g_f->wid - len))
			: addcharn(' ', (g_f->wid - len));
			if (len)
				g_vector = ft_vector(g_vector, s, 5, len);
		}
	}
	else if (len)
		g_vector = ft_vector(g_vector, s, 5, len);
}
