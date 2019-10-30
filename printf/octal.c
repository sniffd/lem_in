/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkeli <rkeli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 14:14:33 by rkeli             #+#    #+#             */
/*   Updated: 2019/07/19 14:14:33 by rkeli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	o_char(va_list ap)
{
	char			*in;
	int				tmplen;
	int				len;
	unsigned int	arg;

	arg = (unsigned char)va_arg(ap, unsigned int);
	in = ft_itoa_base(arg, 8);
	len = (int)ft_strlen(in);
	oktotorp(arg);
	tmplen = g_f->wid - len + (!arg && g_f->dot && !g_f->pre) - (g_f->of && arg
			&& !g_f->zer) - (!arg && g_f->of && g_f->dot && !g_f->pre);
	octl_chck_flags(tmplen, arg, len, in);
}

void	o_short(va_list ap)
{
	char			*in;
	int				tmplen;
	int				len;
	unsigned int	arg;

	arg = (unsigned short)va_arg(ap, unsigned int);
	in = ft_itoa_base(arg, 8);
	len = (int)ft_strlen(in);
	oktotorp(arg);
	tmplen = g_f->wid - len + (!arg && g_f->dot && !g_f->pre) - (g_f->of && arg
			&& !g_f->zer) - (!arg && g_f->of && g_f->dot && !g_f->pre);
	octl_chck_flags(tmplen, arg, len, in);
}

void	o_int(va_list ap)
{
	char			*in;
	int				tmplen;
	int				len;
	unsigned int	arg;

	arg = va_arg(ap, unsigned int);
	in = ft_itoa_base(arg, 8);
	len = (int)ft_strlen(in);
	oktotorp(arg);
	tmplen = g_f->wid - len + (!arg && g_f->dot && !g_f->pre) - (g_f->of && arg
			&& !g_f->zer) - (!arg && g_f->of && g_f->dot && !g_f->pre);
	octl_chck_flags(tmplen, arg, len, in);
}

void	o_long(va_list ap)
{
	char			*in;
	int				tmplen;
	int				len;
	unsigned long	arg;

	arg = va_arg(ap, unsigned long);
	in = ft_itoa_base(arg, 8);
	len = (int)ft_strlen(in);
	oktotorp(arg);
	tmplen = g_f->wid - len + (!arg && g_f->dot && !g_f->pre) - (g_f->of && arg
			&& !g_f->zer) - (!arg && g_f->of && g_f->dot && !g_f->pre);
	octl_chck_flags(tmplen, arg, len, in);
}

void	o_long_long(va_list ap)
{
	char			*in;
	int				tmplen;
	int				len;
	unsigned long	arg;

	arg = va_arg(ap, unsigned long long);
	in = ft_itoa_base(arg, 8);
	len = (int)ft_strlen(in);
	oktotorp(arg);
	tmplen = g_f->wid - len + (!arg && g_f->dot && !g_f->pre) - (g_f->of && arg
			&& !g_f->zer) - (!arg && g_f->of && g_f->dot && !g_f->pre);
	octl_chck_flags(tmplen, arg, len, in);
}
