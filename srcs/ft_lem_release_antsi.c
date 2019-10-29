/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lem_release_antsi.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 15:38:28 by gbrandon          #+#    #+#             */
/*   Updated: 2019/10/29 17:15:52 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //!!printf
#include "lem_in.h"

static void		print_ants(t_list *ants)
{
	while(ants)
	{
		printf("L%d-%s", ants->content_size, ((t_room*)ants->content)->name); // !!printf
		if (ants->next)
			printf(" ");
		ants = ants->next;
	}
}

static t_list	*init_ant(size_t id, t_list *room)
{
	t_list	*ant;

	ant = ft_lstnew(NULL, 0);
	ant->content = room;
	ant->content_size = id;
	ant->next = NULL;
	return (ant);
}

static void		move_ants(t_list **ans, int end)
{
	t_list		*temp;
	t_list		*ants;

	ants = *ans;
	while (ants)
	{
		if (((t_room*)((t_list*)ants->content)->content)->id != end)
			ants->content = ((t_list*)ants->content)->next;
		else
		{
			temp = ants;
			ants = ants->next;
			if (temp == ans)
				*ans = ants;
			free(temp);
			continue;
		}
		ants = ants->next;
	}
}

int				release_antsi(t_path_agr *paths, int end)
{
	t_list		*ants;
	t_list		*new_ant;
	t_path_l	*path_l;
	size_t		ants_num;

	ants_num = paths->ants;
	ants = NULL;
	while (ants_num < paths->ants)
	{
		move_ants(&ants, end);
		path_l = paths->path_l;
		while (path_l)
		{
			if (path_l->cap < 0)
				path_l->cap = (paths->L + paths->ants) / paths->pths - path_l->len;
			if (path_l->cap > path_l->flow)
			{
				new_ant = init_ant(ants_num, path_l->path);
				ft_lstadd(&ants, new_ant);
				(path_l->flow)++;
				ants_num++;
			}
			path_l = path_l->next;
		}
		print_ants(ants);
	}
	while (ants)
	{
		move_ants(&ants, end);
		print_ants(ants);
	}
}
