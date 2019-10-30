/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkeli <rkeli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 14:13:42 by rkeli             #+#    #+#             */
/*   Updated: 2019/07/19 14:13:42 by rkeli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int g_len;

void		nullcpy(char *s1, const char *s2, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		s1[i] = s2[i];
		i++;
	}
	if (g_f && g_f->flg)
	{
		g_eos++;
		g_f->flg = 0;
	}
}

void		nullcat(char *s1, const char *s2, size_t len)
{
	nullcpy(s1 + g_len, s2, len);
}

char		*ft_if(char **vector, const char *str, size_t *size, size_t len)
{
	char	*ret;

	while (g_len + 1 + ft_strlen(str) + (g_f && g_f->flg) >= *size)
		*size *= 2;
	if (!(ret = ft_memalloc(*size)))
		exit(0);
	nullcpy(ret, *vector, g_len);
	if (!len)
	{
		nullcat(ret, str, ft_strlen(str) + (g_f && g_f->flg));
		g_len += ft_strlen(str) + (g_f && g_f->flg);
	}
	else
	{
		nullcat(ret, str, len);
		g_len += len;
	}
	free(*vector);
	return (ret);
}

char		*ft_else(char **vector, const char *str, size_t *size, size_t len)
{
	if (g_len + 1 + ft_strlen(str) + (g_f && g_f->flg) >= *size)
		return (ft_if(vector, str, size, len));
	else
	{
		if (!len)
		{
			nullcat(*vector, str, ft_strlen(str) + (g_f && g_f->flg));
			g_len += ft_strlen(str) + (g_f && g_f->flg);
		}
		else
		{
			nullcat(*vector, str, len);
			g_len += len;
		}
		return (*vector);
	}
}

char		*ft_vector(char *vector, const char *str, size_t i_size, size_t len)
{
	static size_t	size;
	char			*ret;

	if (!size)
		size = i_size;
	if (!vector)
	{
		size = ft_strlen(str) + (g_f && g_f->flg) >= size ? ft_strlen(str)
				+ (g_f && g_f->flg) : size;
		if (!(ret = ft_memalloc(size + 1)))
			exit(0);
		if (!len)
		{
			nullcpy(ret, str, ft_strlen(str) + (g_f && g_f->flg));
			g_len += ft_strlen(str) + (g_f && g_f->flg);
		}
		else
		{
			nullcpy(ret, str, len);
			g_len += len;
		}
		return (ret);
	}
	else
		return (ft_else(&vector, str, &size, len));
}
