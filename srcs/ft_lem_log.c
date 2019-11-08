/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lem_log.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 15:59:10 by gbrandon          #+#    #+#             */
/*   Updated: 2019/11/08 02:58:23 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "ft_printf.h"

void		print_lems(int str_num)
{
	extern int	g_fl;

	if ((((g_fl >> 2) & 1) == 1) || (g_fl > 0 && g_fl < 4))
	{
		ft_printf("\x1b[92m");
		ft_printf("->lines number: %d\n", str_num);
		ft_printf("\x1b[0m");
	}
}

void		print_paths(t_path_agr *paths)
{
	extern int	g_fl;
	t_list		*path;
	t_path_l	*path_list;

	if (g_fl > 0 && g_fl <= 3)
	{
		ft_printf("\x1b[90m");
		path_list = paths->path_l;
		ft_printf("Paths: \n");
		while (path_list)
		{
			path = path_list->path;
			ft_printf("size: %d\n", path_list->len);
			while (path)
			{
				ft_printf("%s", ((t_room*)path->content)->name);
				if (path->next)
					ft_printf("->");
				path = path->next;
			}
			ft_printf("\n");
			path_list = path_list->next;
		}
		ft_printf("\n\n\x1b[0m");
	}
}

void		ft_lemi_log(int lvl, int clr, t_path_l *path_l)
{
	extern int	g_fl;
	int			i;

	if ((g_fl == 2 || g_fl == 3))
	{
		i = -1;
		clr == 1 ? ft_printf("\x1b[90m") : 0;
		clr == 2 ? ft_printf("\x1b[94m") : 0;
		while (i++ < lvl)
		{
			ft_printf("-");
		}
		ft_printf(">");
		ft_printf("%d/%d\n", path_l->flow, path_l->cap);
		if (clr > 0)
			ft_printf("\x1b[0m");
	}
}

void		ft_lem_log(char *mes, int lvl, int clr, char imp)
{
	extern int	g_fl;
	int			i;

	if ((imp == 0 && g_fl > 0 && g_fl <= 3) ||
	(imp == 1 && (g_fl == 2 || g_fl == 3)))
	{
		i = -1;
		clr == 1 ? ft_printf("\x1b[90m") : 0;
		clr == 2 ? ft_printf("\x1b[94m") : 0;
		while (i++ < lvl)
		{
			ft_printf("-");
		}
		ft_printf(">");
		ft_printf("%s", mes);
		if (clr > 0)
			ft_printf("\x1b[0m");
	}
}
