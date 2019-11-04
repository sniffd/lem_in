/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lem_cnstrctrs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 13:10:28 by gbrandon          #+#    #+#             */
/*   Updated: 2019/11/04 14:08:34 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room		*init_room(int id, char *name, int x, int y)
{
	t_room	*room;

	room = ft_memalloc(sizeof(t_room));
	room->id = id;
	room->name = ft_strdup(name);
	room->mark = -1;
	room->parent = -1;
	room->x = x;
	room->y = y;
	room->lst = NULL;
	room->is_in_path = 0;
	return (room);
}

t_rlist		*init_rlist(int id)
{
	t_rlist	*adj;

	adj = (t_rlist*)malloc(sizeof(t_rlist));
	adj->id = id;
	adj->flow = 0;
	adj->cap = 1;
	adj->twin = NULL;
	adj->next = NULL;
	return (adj);
}

t_path_agr	*init_path_agr(int l, int n, int k)
{
	t_path_agr		*pathagr;

	pathagr = (t_path_agr*)malloc(sizeof(t_path_agr));
	pathagr->pths = k;
	pathagr->L = l;
	pathagr->ants = n;
	pathagr->dx = 2147483647;
	pathagr->path_l = NULL;
	return (pathagr);
}

t_ek_info	*init_ek_info(t_room **graph, int end, int cntr)
{
	t_ek_info		*box;

	box = (t_ek_info*)malloc(sizeof(t_ek_info));
	box->cur = end;
	box->par = graph[graph[end]->parent];
	box->path = ft_lstnew(NULL, 0);
	box->path->content = graph[end];
	box->i = cntr;
	box->is_ed_del = 0;
	return (box);
}
