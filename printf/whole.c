/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whole.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkeli <rkeli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 14:16:02 by rkeli             #+#    #+#             */
/*   Updated: 2019/07/19 14:16:18 by rkeli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_bigint	pow_of_two(int pow)
{
	t_bigint	b;
	int			i;
	int			p;

	p = -1;
	b.len = pow / 59 + 1;
	if (!(b.num = (size_t *)ft_memalloc(sizeof(size_t) * b.len)))
		exit(0);
	b.num[0] = ZERO + 1;
	b.start = 0;
	i = 0;
	while (++i < b.len)
		b.num[i] = ZERO;
	while ((++p < pow) && ((i = b.start + 1) || 1))
		while ((--i >= 0)
		&& ((b.num[i] = ((b.num[i] - ZERO) << 1) + ZERO) || 1))
			if (b.num[i] >= LIM)
			{
				b.num[i + 1] = (b.num[i + 1] - ZERO) + ((b.num[i] - ZERO) / DIV)
						+ ZERO;
				b.num[i] = (b.num[i] - ZERO) % DIV + ZERO;
				if (i + 1 > b.start)
					b.start++;
			}
	return (b);
}

static void		while_i_less_biggestlen(int i, t_bigint *res, t_bigint a,
															t_bigint b)
{
	char		biggest;
	int			biggestlen;
	int			lowestlen;

	biggest = a.start > b.start ? 'a' : 'b';
	biggestlen = (biggest == 'a' ? a.start + 1 : b.start + 1);
	lowestlen = (biggest == 'a' ? b.start + 1 : a.start + 1);
	while (i < biggestlen)
	{
		if (i < lowestlen)
			res->num[i] = (res->num[i] - ZERO) + (a.num[i] - ZERO) + (b.num[i]
					- ZERO) + ZERO;
		else
			res->num[i] = (biggest == 'a' ? ((res->num[i] - ZERO) + (a.num[i]
		- ZERO) + ZERO) : ((res->num[i] - ZERO) + (b.num[i] - ZERO) + ZERO));
		if (res->num[i] > LIM)
		{
			res->num[i + 1] = (res->num[i + 1] - ZERO) + ((res->num[i] - ZERO)
					/ DIV) + ZERO;
			res->num[i] = (res->num[i] - ZERO) % DIV + ZERO;
			i + 1 > res->start ? (res->start)++ : 0;
			i + 1 == biggestlen ? biggestlen++ : 0;
		}
		(i++ > res->start) ? res->start++ : 0;
	}
}

static t_bigint	bigint_add(t_bigint a, t_bigint b)
{
	t_bigint	res;
	char		biggest;
	int			biggestlen;
	int			i;

	biggest = a.start > b.start ? 'a' : 'b';
	biggestlen = (biggest == 'a' ? a.start + 1 : b.start + 1);
	if (!(res.num = ft_memalloc(sizeof(size_t) * (biggestlen + 1))))
		exit(0);
	res.len = biggestlen + 1;
	i = 0;
	res.start = 0;
	while (i < res.len)
	{
		res.num[i] = ZERO;
		i++;
	}
	while_i_less_biggestlen(0, &res, a, b);
	free(a.num);
	return (res);
}

static t_bigint	bigint_multy_two(t_bigint b)
{
	t_bigint	res;
	int			i;

	res.len = b.start + 2;
	if (!(res.num = (size_t *)ft_memalloc(sizeof(size_t) * res.len)))
		exit(0);
	res.start = b.start;
	i = b.start + 1;
	while (i >= 0)
	{
		res.num[i] = ZERO;
		i--;
	}
	i = b.start;
	multy_two(&res, b, i);
	free(b.num);
	return (res);
}

t_bigint		get_whole(size_t man, int pow)
{
	t_bigint	res;
	t_bigint	two;
	size_t		mant;
	char		bit;

	if (!(res.num = (size_t *)ft_memalloc(8)))
		exit(0);
	res.len = 0;
	res.start = 0;
	res.num[0] = ZERO;
	mant = man;
	pow = pow - 63;
	two = pow_of_two(pow);
	while (mant)
	{
		bit = mant & 1;
		if (bit)
			res = bigint_add(res, two);
		mant >>= 1;
		pow++;
		two = bigint_multy_two(two);
	}
	res.num[res.start] -= ZERO;
	free(two.num);
	return (res);
}
