/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edm_karp_alg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 20:52:55 by gbrandon          #+#    #+#             */
/*   Updated: 2019/10/28 15:11:36 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "avlt.h"

static t_rlist  *find_adj(t_room *cur, int id)
{
	t_rlist		*to;

	to = cur->lst;
	while(to)
	{
		if (to->id == id)
			return (to);
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
	to->flow -= 1;
	return (0);
}

static t_room		*next_parant(t_room **graph, t_room *par, int *cur)
{
	*cur = par->id;
	return (graph[graph[*cur]->parent]);
}

int				edm_karp_alg(t_room **graph, int start, int end)
{
	t_room		*par;
	int			cur;

	while(1)
	{
		ft_bfs_int(graph, start, end);
		if (graph[end]->parent == -1)
			break;
		cur = end;
		par = graph[graph[end]->parent];
		while(graph[cur]->parent -1)
		{
			if (inc_flow(par, cur) < 0)
				return (-1);
			if (dec_flow(graph[cur], par->id) < 0)
				return (-1);
			par = next_parant(graph, par, &cur);
			ek_alg_mk_twin(par, start);
			//assembly path here
		}
	}
	return (0);
}