/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edm_karp_alg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 20:52:55 by gbrandon          #+#    #+#             */
/*   Updated: 2019/11/08 02:20:10 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "avlt.h"

t_rlist				*find_adj(t_room *cur, int id)
{
	t_rlist		*to;
	t_rlist		*toto;

	to = cur->lst;
	while (to)
	{
		if (to->id == id)
			return (to);
		else if (to->twin && ((t_room*)to->twin)->lst)
		{
			toto = ((t_room*)to->twin)->lst;
			while (toto)
			{
				if (toto->id == id)
					return (toto);
				toto = toto->next;
			}
		}
		to = to->next;
	}
	return (NULL);
}

static t_room		*next_parent(t_room **graph, t_room *par, int *cur)
{
	*cur = par->id;
	if (graph[*cur]->parent == -1)
		return (NULL);
	return (graph[graph[*cur]->parent]);
}

static	void		end_of_edm_karp(t_sinfo *rooms, t_ek_info *box, int *er)
{
	box->path = ek_alg_mk_path(box->par, box->path, rooms);
	box->par = next_parent(rooms->graph, box->par, &(box->cur));
	(box->i)++;
	if (!*er)
		*er = box->is_ed_del;
}

t_path_agr			*edm_karp_alg(t_sinfo *rooms, int *er)
{
	t_ek_info	*box;
	t_path_agr	*pthagr;

	pthagr = init_path_agr(0, rooms->lems, 0);
	//while (pthagr->dx > 0)
	while(1)
	{
		ft_lem_log("starting bfs...\n", 2, 2, 1);
		ft_bfs(rooms);
		ft_lem_log("finish bfs.\n", 2, 2, 1);
		if (rooms->graph[rooms->end]->parent == -1)
			break ;
		box = init_ek_info(rooms->graph, rooms->end, 0);
		while (rooms->graph[box->cur]->parent != -1)
		{
			if (!ek_alg_del_edg(rooms->graph, box, pthagr))
			{
				if (!edm_karp_edgew(rooms, box))
					return (NULL);
			}
			end_of_edm_karp(rooms, box, er);
		}
		if (!box->is_ed_del)
			pthagr = ek_alg_mk_pagr(pthagr, box);
		else
		{
			ft_lstdel(&(box->path), del_lst);
			break;
		}
		print_paths(pthagr);//
		free(box);
	}
	return (pthagr);
}
