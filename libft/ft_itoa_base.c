/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkeli <rkeli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 14:17:45 by rkeli             #+#    #+#             */
/*   Updated: 2019/07/19 14:17:45 by rkeli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(__uint128_t n, int base)
{
	char				*dic;
	char				*res;
	int					i;
	__uint128_t			nb;

	dic = ft_strdup("0123456789ABCDEF");
	i = 1;
	nb = n;
	while ((nb = nb / base))
		i++;
	if (!(res = (char *)ft_memalloc(i-- + 1)))
		return (0);
	if (n == 0)
		res[0] = '0';
	while (n != 0)
	{
		res[i--] = dic[n % base];
		n = n / base;
	}
	free(dic);
	return (res);
}
