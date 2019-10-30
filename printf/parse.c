/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkeli <rkeli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 14:15:00 by rkeli             #+#    #+#             */
/*   Updated: 2019/07/19 14:15:00 by rkeli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	parse_flags(const char s, t_f *f)
{
	if (s == '#')
		f->okt = 1;
	else if (s == '-')
		f->min = 1;
	else if (s == '+')
		f->plu = 1;
	else if (s == ' ')
		f->spc = 1;
	else if (s == '0')
		f->zer = 1;
}

static void	parse_size(const char s, t_f *f)
{
	if (s == 'L')
		f->bl = 1;
	if (s == 'l')
	{
		f->ll = f->l == 1 ? 1 : 0;
		f->l = 1;
	}
	if (s == 'h')
	{
		f->hh = f->h == 1 ? 1 : 0;
		f->h = 1;
	}
}

static void	parse_pre_or_wid(const char *s, t_f *f, va_list ap, int flag)
{
	if (flag)
	{
		if (S == '.')
		{
			f->dot = 1;
			f->pre = (*(s + 1) == '*' ? va_arg(ap, int) : ft_atoi(s + 1));
			if (f->pre < 0)
			{
				f->dot = 0;
				f->pre = 0;
			}
		}
	}
	else
	{
		if (S == '*')
		{
			f->wid = va_arg(ap, int);
			g_f->flg = 1;
		}
		else if (!((f->wid) && !f->flg))
			f->wid = ft_atoi(s);
		if_wid_less_zero();
	}
}

static int	parse_zone(const char s, int zone)
{
	if (zone < 1 && ((s >= 49 && s <= 57) || s == '*'))
		zone = 1;
	else if (zone < 2 && s == '.')
		zone = 2;
	else if (zone < 3 && (s == 'l' || s == 'h' || s == 'L'))
		zone = 3;
	return (zone);
}

void		parse(const char **s, va_list ap)
{
	int	zone;

	if (!(g_f = (t_f *)ft_memalloc(sizeof(t_f))))
		exit(0);
	zone = 0;
	while ((*S >= '0' && *S <= '9') || *S == '-' || *S == '#' || *S == ' ' ||
	*S == '.' || *S == '+' || *S == '*' || *S == 'l' || *S == 'L' || *S == 'h')
	{
		zone = parse_zone(*S, zone);
		if (zone == 0)
			parse_flags(**s, g_f);
		else if (zone == 1)
			parse_pre_or_wid(S, g_f, ap, 0);
		else if (zone == 2)
			parse_pre_or_wid(S, g_f, ap, 1);
		else
			parse_size(**s, g_f);
		(S)++;
	}
	finish(s);
}
