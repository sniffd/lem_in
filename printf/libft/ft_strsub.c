/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaryn-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 06:17:43 by fdaryn-h          #+#    #+#             */
/*   Updated: 2019/02/04 12:32:24 by fdaryn-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!s || !(str = (char *)ft_memalloc(len + 1)))
		return (0);
	str[len] = '\0';
	while (len--)
		str[len] = s[start + len];
	return (str);
}
