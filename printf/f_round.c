/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_round.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkeli <rkeli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 14:13:19 by rkeli             #+#    #+#             */
/*   Updated: 2019/07/19 14:13:19 by rkeli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	g_flag = 0;

void	math_round(t_bigint *b, t_bigint *w, t_round *r, char flag)
{
	size_t			mask;
	unsigned int	overflow;

	mask = get_mask(ft_numlen(b->num[r->index])) / 10;
	overflow = b->num[r->index] / mask;
	if (r->next_digit > 4)
	{
		b->num[r->index] = !flag ? b->num[r->index] + 1
				: b->num[r->index] + r->mask;
		if (flag && r->index == b->start && overflow != b->num[r->index] / mask)
			w->num[0]++;
		*b = check_overflow_five(*b, r->index);
	}
}

void	printf_round(t_bigint *b, int index, size_t mask, char flag)
{
	size_t	number;

	if (!flag)
		number = b->num[0];
	else
		number = b->num[index] / mask % 10;
	if (number % 2 == 1)
	{
		b->num[index] = !flag ? b->num[index] + 1 : b->num[index] + mask;
		*b = check_overflow_five(*b, index);
	}
}

void	check_zero(t_bigint *f, t_bigint *w, t_round *r, int len)
{
	int	i;

	i = r->index;
	if (r->nmb_pos != len && f->num[r->index] % (r->mask / 10))
		math_round(f, w, r, g_flag);
	else
	{
		while (i > 0)
		{
			if ((f->num[--i] - ZERO))
			{
				math_round(f, w, r, g_flag);
				return ;
			}
		}
		printf_round(f, r->index, r->mask, g_flag);
	}
}

void	fraction_round(t_bigint *f, t_bigint *w, t_round *r)
{
	int pre;
	int start_len;

	start_len = ft_numlen(f->num[f->start]) - 1;
	if (g_f->pre < f->start * CLUSTER_SIZE + start_len)
	{
		pre = ((g_f->pre - start_len > 0) ? g_f->pre - start_len : 0);
		r->index = f->start -
				(pre / CLUSTER_SIZE + ((pre % CLUSTER_SIZE != 0) * 1));
		if (r->index == f->start)
			r->nmb_pos = g_f->pre % (start_len + 1);
		else if (g_f->pre < CLUSTER_SIZE)
			r->nmb_pos = (g_f->pre - start_len) % CLUSTER_SIZE;
		else
		{
			r->nmb_pos = (g_f->pre - start_len) % CLUSTER_SIZE;
			if (r->nmb_pos == 0)
				r->nmb_pos = 18;
		}
		fraction_select_round(f, w, r, 1);
	}
	else
		r->nmb_pos = 18;
}

void	f_round(t_bigint w, t_bigint f)
{
	t_round	r;

	r.index = 0;
	if (g_f->pre > 0)
		fraction_round(&f, &w, &r);
	else
	{
		r.index = 0;
		r.nmb_pos = ft_numlen(f.num[0]) - 1;
		whole_select_round(&f, &w, &r, 0);
	}
	print(f, w, r.index, r.nmb_pos);
}
