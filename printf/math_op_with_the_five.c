/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_op_with_the_five.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkeli <rkeli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 14:14:09 by rkeli             #+#    #+#             */
/*   Updated: 2019/07/19 14:16:18 by rkeli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_bigint	bigint_multy_five(t_bigint b)
{
	t_bigint	res;
	int			i;

	res.len = b.start + 2;
	if (!(res.num = (size_t *)ft_memalloc(sizeof(size_t) * res.len)))
		exit(0);
	res.start = b.start;
	i = b.start + 1;
	while (i < res.len)
	{
		res.num[i] = ZERO;
		i++;
	}
	i = b.start;
	while (i >= 0)
	{
		res.num[i] = (b.num[i] - ZERO) * 5 + ZERO;
		res = check_overflow_five(res, i);
		i--;
	}
	free(b.num);
	return (res);
}

void		power_of_five(int pow, int p, int i, t_bigint *b)
{
	while (p < pow)
	{
		i = b->start;
		while (i >= 0)
		{
			b->num[i] = (b->num[i] - ZERO) * 5 + ZERO;
			if (b->num[i] > LIM)
			{
				b->num[i + 1] = (b->num[i + 1] - ZERO) + ((b->num[i] - ZERO)
						/ DIV) + ZERO;
				b->num[i] = ((b->num[i] - ZERO) % DIV) + ZERO;
				if (i + 1 > b->start)
					b->start++;
			}
			i--;
		}
		p++;
	}
}

t_bigint	pow_of_five(int pow)
{
	t_bigint	b;
	int			i;
	int			p;

	p = 0;
	b.len = (ft_abs(pow) / 18) + 2;
	if (!(b.num = (size_t *)ft_memalloc(sizeof(size_t) * b.len)))
		exit(0);
	b.num[0] = 1 + ZERO;
	b.start = 0;
	i = 1;
	while (i < b.len)
	{
		b.num[i] = ZERO;
		i++;
	}
	power_of_five(pow, p, i, &b);
	return (b);
}
