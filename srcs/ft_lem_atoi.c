/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lem_atoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 07:22:36 by gbrandon          #+#    #+#             */
/*   Updated: 2019/11/08 07:22:39 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	pres(char **str, int *f)
{
	int	res;

	res = 0;
	while (**str >= '0' && **str <= '9')
	{
		if (((res * 10 + (**str - '0'))) / 10 != res)
		{
			*f = 1;
			return (-1);
		}
		res = res * 10 + (**str - '0');
		(*str)++;
	}
	return (res);
}

static int	mres(char **str, int *f)
{
	int	res;

	res = 0;
	while (**str >= '0' && **str <= '9')
	{
		if (((res * 10 + (**str - '0'))) / 10 != res)
		{
			*f = 1;
			return (0);
		}
		res = res * 10 + (**str - '0');
		(*str)++;
	}
	return (-res);
}

int			atoi_lem_in(char **str, int *f)
{
	int			sign;

	if (!ft_strcmp(*str, "-2147483648"))
		return (-2147483648);
	sign = 0;
	if (**str == ' ')
		*f = 1;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign = 1;
		(*str)++;
		if (**str == '-' || **str == '+' || **str == ' ' || **str == '\0')
		{
			*f = 1;
			return (0);
		}
	}
	if (sign)
		return (mres(str, f));
	else
		return (pres(str, f));
}
