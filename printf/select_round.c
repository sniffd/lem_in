/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_round.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkeli <rkeli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 14:15:36 by rkeli             #+#    #+#             */
/*   Updated: 2019/07/19 14:15:36 by rkeli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern char		g_flag;

size_t	get_mask(int i)
{
	size_t	mask[19];

	mask[1] = 10;
	mask[2] = 100;
	mask[3] = 1000;
	mask[4] = 10000;
	mask[5] = 100000;
	mask[6] = 1000000;
	mask[7] = 10000000;
	mask[8] = 100000000;
	mask[9] = 1000000000;
	mask[10] = 10000000000;
	mask[11] = 100000000000;
	mask[12] = 1000000000000;
	mask[13] = 10000000000000;
	mask[14] = 100000000000000;
	mask[15] = 1000000000000000;
	mask[16] = 10000000000000000;
	mask[17] = 100000000000000000;
	mask[18] = 1000000000000000000;
	return (mask[i]);
}

void	fraction_select_round(t_bigint *f, t_bigint *w, t_round *r, char flag)
{
	int	len;

	g_flag = flag;
	len = ft_numlen(f->num[r->index]) - 1;
	r->mask = get_mask(len - r->nmb_pos);
	r->next_digit = (r->nmb_pos == len) ?
					f->num[r->index - 1] / 100000000000000000 % 10 :
					f->num[r->index] % r->mask / (r->mask / 10);
	if (r->next_digit != 5)
		math_round(f, w, r, g_flag);
	else
		check_zero(f, w, r, len);
}

void	whole_select_round(t_bigint *f, t_bigint *w, t_round *r, char flag)
{
	int f_digit;

	g_flag = flag;
	if (ft_numlen(f->num[f->start]) == 1 && f->start)
		f->start--;
	r->mask = get_mask(ft_numlen(f->num[f->start]) - 1);
	f_digit = f->num[f->start] % r->mask / (r->mask / 10);
	r->next_digit = f_digit;
	if (f_digit != 5)
		math_round(w, w, r, g_flag);
	else
		check_zero(w, w, r, -255);
}
