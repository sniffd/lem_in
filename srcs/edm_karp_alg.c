/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edm_karp_alg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 20:52:55 by gbrandon          #+#    #+#             */
/*   Updated: 2019/11/04 19:10:46 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "avlt.h"

t_rlist  *find_adj(t_room *cur, int id)
{
	t_rlist		*to;
	t_rlist		*toto;

	to = cur->lst;
	while(to)
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

static int		inc_flow(t_room *room, int connect)
{
	t_rlist		*to;
	
	if (!(to = find_adj(room, connect)))
		return (-2);
	to->flow += 1;
	return (0);
}

static int		dec_flow(t_room *room, int connect)
{

	t_rlist		*to;

	if (!(to = find_adj(room, connect)))
		return (-2);
	to->flow += 1;
	return (0);
}

static t_room		*next_parent(t_room **graph, t_room *par, int *cur)
{
	*cur = par->id;
	if (graph[*cur]->parent == -1)
		return (NULL);
	return (graph[graph[*cur]->parent]);
}

t_path_agr			*edm_karp_alg(t_room **graph, int start, int end, size_t s, size_t ants, int *er, int par)
{
	t_ek_info	*box;
	t_path_agr	*pthagr;
	int			ab;

	pthagr = init_path_agr(0, ants, 0);
	ab = (par ? 1 : pthagr->dx);
	while(ab > 0)
	//while(pthagr->dx > 0)
	//while(1)
	{
		ft_bfs_int(graph, start, end, s);
		if (graph[end]->parent == -1)
			break;
		box = init_ek_info(graph, end, 0);
		while(graph[box->cur]->parent != -1)
		{
			if (!ek_alg_del_edg(graph, box))
			{
			if (inc_flow(box->par, box->cur) < 0)
			// if cant find vertex in adjacency list than error do not forget to free box
			// the same for below dec_flow
				return (NULL);
			if (dec_flow(graph[box->cur], box->par->id) < 0)
				return (NULL);
			ek_alg_mk_twin(box->par, start);
			ek_alg_neg_e(graph[box->cur], box->par, start);
			}
			box->path = ek_alg_mk_path(box->par, box->path);
			box->par = next_parent(graph, box->par, &(box->cur));
			(box->i)++;
			if (!*er)
				*er = box->is_ed_del;
		}
		pthagr = ek_alg_mk_pagr(pthagr, box, par);
		free(box);
		ab = (par ? 1 : pthagr->dx);
	}
	return (pthagr);
}
