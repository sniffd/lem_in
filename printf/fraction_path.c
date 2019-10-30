/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fraction_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkeli <rkeli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 14:13:30 by rkeli             #+#    #+#             */
/*   Updated: 2019/07/19 14:13:30 by rkeli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_bigint	check_overflow(t_bigint b, int i)
{
	while (i <= b.start)
	{
		if (b.num[i] < LIM && i >= b.start)
			break ;
		b.num[i + 1] = ((b.num[i + 1] - ZERO) * 10) + ((b.num[i] - ZERO) / DIV)
				+ ZERO;
		b.num[i] = (b.num[i] - ZERO) % DIV + ZERO;
		if (i + 1 > b.start)
			b.start++;
		i++;
	}
	return (b);
}

t_bigint	check_overflow_five(t_bigint b, int i)
{
	while (i <= b.start)
	{
		if (b.num[i] < LIM)
			break ;
		b.num[i + 1] = (b.num[i + 1] - ZERO) + ((b.num[i] - ZERO) / DIV) + ZERO;
		b.num[i] = (b.num[i] - ZERO) % DIV + ZERO;
		if (i + 1 > b.start)
			b.start++;
		i++;
	}
	return (b);
}

int			if_ipo_equal_astart(t_bigint *res, t_bigint a, t_bigint b, int *i)
{
	size_t		mod;
	size_t		div;

	div = (res->num[*i] - ZERO) / DIV;
	mod = (res->num[*i] - ZERO) % DIV;
	if (*i + 1 == a.start)
	{
		res->num[*i + 1] = (res->num[*i + 1] - ZERO) + (a.num[*i + 1] - ZERO)
				+ ZERO;
		res->num[*i] = mod + ZERO;
		res->num[*i + 1] = (res->num[*i + 1] - ZERO) + (b.num[*i + 1] - ZERO)
				+ ZERO;
		res->num[*i + 1] = (res->num[*i + 1] - ZERO) + div + ZERO;
		(*i)++;
		return (0);
	}
	return (1);
}

int			if_lim(t_bigint *res, t_bigint a, t_bigint b, int *i)
{
	char		biggest;
	int			biggestlen;
	size_t		mod;
	size_t		div;
	int			f;

	biggest = a.start > b.start ? 'a' : 'b';
	biggestlen = (biggest == 'a' ? a.start + 1 : b.start + 1);
	f = 0;
	if (res->num[*i] > LIM)
	{
		div = (res->num[*i] - ZERO) / DIV;
		mod = (res->num[*i] - ZERO) % DIV;
		if (if_ipo_equal_astart(res, a, b, i))
		{
			res->num[*i + 1] = (res->num[*i + 1] - ZERO) + div + ZERO;
			res->num[*i] = mod + ZERO;
		}
		else
			f = 1;
		res->start = (!f && *i + 1 == biggestlen ? *i + 1 : *i);
		return (0);
	}
	return (1);
}

void		while_i_less_biggistlen(t_bigint *res, t_bigint a, t_bigint b,
								int i)
{
	char	biggest;
	int		biggestlen;
	int		lowestlen;

	biggest = a.start > b.start ? 'a' : 'b';
	biggestlen = (biggest == 'a' ? a.start + 1 : b.start + 1);
	lowestlen = (biggest == 'a' ? b.start + 1 : a.start + 1);
	while (i < biggestlen)
	{
		if (i < lowestlen)
			res->num[i] = (res->num[i] - ZERO) + (a.num[i] - ZERO) + (b.num[i]
					- ZERO) + ZERO;
		else
		{
			if (biggest == 'a')
				res->num[i] = (res->num[i] - ZERO) + (a.num[i] - ZERO) + ZERO;
			else
				res->num[i] = (res->num[i] - ZERO) + (b.num[i] - ZERO) + ZERO;
		}
		if (if_lim(res, a, b, &i) && i > res->start)
			res->start++;
		i++;
	}
}
