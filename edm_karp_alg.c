/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edm_karp_alg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 20:52:55 by gbrandon          #+#    #+#             */
/*   Updated: 2019/10/27 22:04:49 by gbrandon         ###   ########.fr       */
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

int				edm_karp_alg(t_room **graph, int start, int end)
{
	t_room		*par;
	t_rlist		*to;
	int			cur;

	while(1)
	{
		ft_bfs_int(graph, start, end);
		if (graph[end]->parent = -1)
			break;
		par = graph[end]->parent;
		cur = end;
		while(par != -1)
		{
			if (!(to = find_adj(par, cur)))
				return (-2);
			to->flow = 1;
			if (!(to = find_adj(graph[cur], par->id)))
				return (-2);
			to->flow -= 1;
			par = graph[par->id]->parent;
			//assembly path here
		}
	}
	return (0);
}