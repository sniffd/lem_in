/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oktotorp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkeli <rkeli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 14:14:55 by rkeli             #+#    #+#             */
/*   Updated: 2019/07/19 14:14:55 by rkeli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	oktotorp(unsigned long long arg)
{
	if (g_f->okt || g_f->f == 'p')
	{
		if (g_f->f == 'x' || g_f->f == 'p')
		{
			if (arg || g_f->f == 'p')
				g_vector = ft_vector(g_vector, "0x", 5, 0);
		}
		else if (g_f->f == 'X')
		{
			if (arg)
				g_vector = ft_vector(g_vector, "0X", 5, 0);
		}
		else if (g_f->f == 'o')
			g_f->of = 1;
	}
	return (1);
}
