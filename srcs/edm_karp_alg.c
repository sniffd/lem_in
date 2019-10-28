/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edm_karp_alg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 20:52:55 by gbrandon          #+#    #+#             */
/*   Updated: 2019/10/28 21:01:00 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "avlt.h"

static t_rlist  *find_adj(t_room *cur, int id)
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
	to->flow -= 1;
	return (0);
}

static t_room		*next_parant(t_room **graph, t_room *par, int *cur)
{
	*cur = par->id;
	return (graph[graph[*cur]->parent]);
}

t_list				*edm_karp_alg(t_room **graph, int start, int end, size_t s)
{
	t_room		*par;
	t_list		*path;
	t_list		*path_l;
	int			cur;
	int			i;

	path_l = NULL;
	while(1)
	{
		ft_bfs_int(graph, start, end, s);
		if (graph[end]->parent == -1)
			break;
		cur = end;
		par = graph[graph[end]->parent];
		path = ft_lstnew(NULL, 0);
		path->content = graph[end];
		i = 0;
		while(graph[cur]->parent != -1)
		{
			if (inc_flow(par, cur) < 0)
				return (NULL);
			if (dec_flow(graph[cur], par->id) < 0)
				return (NULL);
			ek_alg_mk_twin(par, start);
			path = ek_alg_mk_path(par, path);
			par = next_parant(graph, par, &cur);
			i++;
		}
		path_l = ek_alg_mk_path_l(path_l, path, i);
	}
	return (path_l);
}