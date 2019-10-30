/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fraction.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkeli <rkeli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 14:13:25 by rkeli             #+#    #+#             */
/*   Updated: 2019/07/19 14:16:18 by rkeli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_bigint	bigint_add_f(t_bigint a, t_bigint b)
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
	while_i_less_biggistlen(&res, a, b, 0);
	free(a.num);
	return (res);
}

static t_bigint	bigint_multy_ten(t_bigint b)
{
	t_bigint	res;
	int			i;

	res.start = b.start;
	res.len = b.len + 1;
	if (!(res.num = ft_memalloc(sizeof(size_t) * res.len)))
		exit(0);
	i = b.start;
	while (i > 0)
	{
		res.num[i] = b.num[i];
		i--;
	}
	i = b.start + 1;
	while (i < res.len)
	{
		res.num[i] = ZERO;
		i++;
	}
	res.num[0] = ((b.num[0] - ZERO) * 10) + ZERO;
	res = check_overflow(res, 0);
	free(b.num);
	return (res);
}

t_bigint		get_null(void)
{
	t_bigint	res;

	res.num = ft_memalloc(8);
	res.num[0] = 0;
	res.start = 0;
	res.len = 1;
	res.sign = 0;
	return (res);
}

void			experiment(size_t mant, t_bigint *res, int pow)
{
	t_bigint	five;
	size_t		bit;
	int			f;

	f = 0;
	five = pow_of_five(pow);
	while (mant)
	{
		*res = bigint_multy_ten(*res);
		bit = (mant & 0x8000000000000000);
		if (bit)
		{
			*res = bigint_add_f(*res, five);
			f = 1;
		}
		mant <<= 1;
		five = bigint_multy_five(five);
		pow++;
	}
	if (!f)
		res->num[0] = ZERO;
	res->num[res->start] -= ZERO;
	free(five.num);
}

t_bigint		get_fraction(size_t man, int pow)
{
	t_bigint	res;
	int			i;
	size_t		mant;

	pow = -pow;
	if (!(res.num = (size_t *)ft_memalloc(sizeof(size_t) * (pow / 18 + 1))))
		exit(0);
	res.num[0] = 1 + ZERO;
	res.len = pow / 18 + 1;
	res.start = 0;
	i = 1;
	mant = man;
	while (i < pow)
	{
		res = bigint_multy_ten(res);
		i++;
	}
	experiment(mant, &res, pow);
	return (res);
}
