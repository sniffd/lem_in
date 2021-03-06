/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lem_release_antsi.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 15:38:28 by gbrandon          #+#    #+#             */
/*   Updated: 2019/11/08 07:27:18 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "ft_printf.h"

static int		calc_cap(t_path_agr *paths, t_path_l *path_l)
{
	int		val;

	val = (paths->len + paths->ants) / paths->pths - path_l->len;
	if (((paths->len + paths->ants) % paths->pths) != 0)
		val++;
	return (val);
}

void			print_ants(t_list *ants, int *stra_num)
{
	while (ants)
	{
		ft_printf("L%d-%s", ants->content_size,
		((t_room*)((t_list*)ants->content)->content)->name);
		if (ants->next)
			ft_printf(" ");
		ants = ants->next;
	}
	ft_printf("\n");
	(*stra_num)++;
}

t_list			*init_ant(size_t id, t_list *path)
{
	t_list	*ant;

	ant = ft_lstnew(NULL, 0);
	ant->content = path;
	ant->content_size = id + 1;
	ant->next = NULL;
	return (ant);
}

void			move_ants(t_list **ans, int end)
{
	t_list		*temp;
	t_list		*ants;
	t_list		*prev;

	ants = *ans;
	prev = NULL;
	while (ants)
	{
		if (((t_room*)((t_list*)ants->content)->content)->id != end)
			ants->content = ((t_list*)ants->content)->next;
		else
		{
			temp = ants;
			ants = ants->next;
			if (temp == *ans)
				*ans = ants;
			if (prev != NULL)
				prev->next = ants;
			free(temp);
			temp = NULL;
			continue;
		}
		prev = ants;
		ants = ants->next;
	}
}

int				release_antsi(t_path_agr *paths, int end, int *stra_num)
{
	t_list		*ants;
	t_path_l	*path_l;
	size_t		ants_num;

	ants = NULL;
	ants_num = 0;
	while (ants_num < paths->ants)
	{
		move_ants(&ants, end);
		path_l = paths->path_l;
		while (path_l)
		{
			if (path_l->cap < 0)
				path_l->cap = calc_cap(paths, path_l);
			if (path_l->cap > path_l->flow)
				release_antsi_do(&ants_num, path_l, &ants);
			ft_lemi_log(1, 1, path_l);
			path_l = path_l->next;
		}
		print_ants(ants, stra_num);
	}
	release_antsi_pr_end(ants, end, stra_num);
	return (0);
}
