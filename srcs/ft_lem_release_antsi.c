/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lem_release_antsi.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 15:38:28 by gbrandon          #+#    #+#             */
/*   Updated: 2019/11/05 20:17:57 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //!!printf
#include "lem_in.h"

static int		calc_cap(t_path_agr *paths, t_path_l *path_l)
{
	int		val;

	val = (paths->L + paths->ants) / paths->pths - path_l->len;
	if (((paths->L + paths->ants) % paths->pths) != 0)
		val++;
	return (val);
}

void			print_ants(t_list *ants)
{
	while (ants)
	{
		printf("L%zu-%s", ants->content_size, ((t_room*)((t_list*)ants->content)->content)->name); // !!printf
		if (ants->next)
			printf(" "); //! printf
		ants = ants->next;
	}
	printf("\n");
}

t_list			*init_ant(size_t id, t_list *path)
{
	t_list	*ant;

	ant = ft_lstnew(NULL, 0);
	ant->content = path;
	ant->content_size = id;
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

int				release_antsi(t_path_agr *paths, int end)
{
	t_list		*ants;
	t_path_l	*path_l;
	size_t		ants_num;

	ants_num = 0;
	ants = NULL;
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
			//printf("\n%d/%d\n", path_l->flow, path_l->cap);
			path_l = path_l->next;
		}
		print_ants(ants);
	}
	release_antsi_pr_end(ants, end);
	return (0);
}
