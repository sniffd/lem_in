/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaryn-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 08:59:51 by fdaryn-h          #+#    #+#             */
/*   Updated: 2018/12/03 08:59:51 by fdaryn-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	part(size_t num)
{
	if (num >= 1000000000)
		return (10);
	else if (num >= 100000000)
		return (9);
	else if (num >= 10000000)
		return (8);
	else if (num >= 1000000)
		return (7);
	else if (num >= 100000)
		return (6);
	else if (num >= 10000)
		return (5);
	else if (num >= 1000)
		return (4);
	else if (num >= 100)
		return (3);
	else if (num >= 10)
		return (2);
	else if (num >= 1 || num == 0)
		return (1);
	else
		return (20);
}

int			ft_numlen(size_t num)
{
	if (num >= 1000000000000000000)
		return (19);
	else if (num >= 100000000000000000)
		return (18);
	else if (num >= 10000000000000000)
		return (17);
	else if (num >= 1000000000000000)
		return (16);
	else if (num >= 100000000000000)
		return (15);
	else if (num >= 10000000000000)
		return (14);
	else if (num >= 1000000000000)
		return (13);
	else if (num >= 100000000000)
		return (12);
	else if (num >= 10000000000)
		return (11);
	else
		return (part(num));
}
