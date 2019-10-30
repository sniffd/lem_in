/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkeli <rkeli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 14:17:12 by rkeli             #+#    #+#             */
/*   Updated: 2019/07/19 14:17:12 by rkeli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_stoa(size_t n)
{
	size_t	nb;
	int		i;
	char	*res;

	nb = n;
	i = 1;
	while ((nb = nb / 10))
		i++;
	i = n == 0 ? 1 : i;
	if (!(res = (char *)ft_memalloc(i + 1)))
		return (0);
	res[i--] = '\0';
	nb = n;
	if (n == 0)
		res[0] = '0';
	while (nb != 0)
	{
		res[i--] = nb % 10 + '0';
		nb = nb / 10;
	}
	return (res);
}
