/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkeli <rkeli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 14:15:09 by rkeli             #+#    #+#             */
/*   Updated: 2019/07/19 14:15:09 by rkeli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	f_print_sign(char sign, int plu, int spc)
{
	if (sign)
		g_vector = ft_vector(g_vector, "-", 5, 0);
	else if (plu)
		g_vector = ft_vector(g_vector, "+", 5, 0);
	else if (spc)
		g_vector = ft_vector(g_vector, " ", 5, 0);
}

void	print_part(t_bigint b, int i, int j)
{
	char	*cluster;

	while (i > j)
	{
		cluster = ft_stoa(b.num[i]);
		g_vector = ft_vector(g_vector, cluster + 1, 5, 0);
		i--;
		free(cluster);
	}
}

void	print_number(t_bigint f, t_bigint w, int index, int nmb_pos)
{
	char	*cluster;
	int		i;
	int		flen;

	flen = f.start * CLUSTER_SIZE + ft_numlen(f.num[f.start]) - 1;
	i = w.start;
	cluster = ft_stoa(w.num[i]);
	g_vector = ft_vector(g_vector, cluster, 5, 0);
	i--;
	free(cluster);
	print_part(w, i, -1);
	okt_and_dot_and_pre();
	if (g_f->pre > 0)
	{
		g_vector = ft_vector(g_vector, ".", 5, 0);
		i = f.start;
		print_part(f, i, index);
		cluster = ft_stoa(f.num[index]);
		if (index == 0 && nmb_pos == CLUSTER_SIZE)
			g_vector = ft_vector(g_vector, cluster + 1, 5, 0);
		else
			g_vector = ft_vector(g_vector, cluster + 1, 5, nmb_pos);
		free(cluster);
	}
	g_f->pre > flen ? addcharn('0', g_f->pre - flen) : 0;
}

void	select_condition(t_bigint f, t_bigint w, int nmb_pos, int index)
{
	int		wlen;
	int		len;

	wlen = w.start * CLUSTER_SIZE + ft_numlen(w.num[w.start]);
	len = g_f->wid - (wlen + g_f->pre + 1 * !(g_f->dot && !g_f->pre)
			+ (g_f->plu || g_f->spc || w.sign));
	if (g_f->min)
	{
		f_print_sign(w.sign, g_f->plu, g_f->spc);
		print_number(f, w, index, nmb_pos);
		addcharn(' ', len);
	}
	else if (g_f->zer)
	{
		f_print_sign(w.sign, g_f->plu, g_f->spc);
		addcharn('0', len);
		print_number(f, w, index, nmb_pos);
	}
	else
	{
		addcharn(' ', len);
		f_print_sign(w.sign, g_f->plu, g_f->spc);
		print_number(f, w, index, nmb_pos);
	}
}

void	print(t_bigint f, t_bigint w, int index, int nmb_pos)
{
	int		wlen;

	wlen = w.start * CLUSTER_SIZE + ft_numlen(w.num[w.start]) + w.sign;
	if (g_f->wid - (g_f->pre + wlen + 1 + (g_f->plu || g_f->spc || w.sign)) > 0)
		select_condition(f, w, nmb_pos, index);
	else
	{
		f_print_sign(w.sign, g_f->plu, g_f->spc);
		print_number(f, w, index, nmb_pos);
	}
	free(f.num);
	free(w.num);
}
