/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multy_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkeli <rkeli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 14:14:18 by rkeli             #+#    #+#             */
/*   Updated: 2019/07/19 14:14:18 by rkeli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	multy_two(t_bigint *res, t_bigint b, int i)
{
	while (i >= 0)
	{
		res->num[i] = ((b.num[i] - ZERO) << 1) + ZERO;
		if (res->num[i] > LIM)
		{
			res->num[i + 1] = (res->num[i + 1] - ZERO) + ((res->num[i] - ZERO)
					/ DIV) + ZERO;
			res->num[i] = (res->num[i] - ZERO) % DIV + ZERO;
			if (i + 1 > res->start)
				res->start++;
		}
		i--;
	}
}
