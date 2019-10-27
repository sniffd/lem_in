/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bfs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 16:20:42 by gbrandon          #+#    #+#             */
/*   Updated: 2019/10/27 20:56:57 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "avlt.h"
#include "ft_queue.h"

/*
int		ft_bfs(t_avlt *graph, char *start, char *end)
{
	t_fque		*qhead;
	t_fque		*qtail;
	t_room		*hroom;
	t_room		*w;

	qhead = NULL;
	qtail = NULL;

	if (!(hroom = get_v(graph, start)))
		return (-1);
	hroom->mark = 0;
	add_qnode(&qhead, &qtail, hroom, q_input);
	while (qhead)
	{
		while (((t_room*)qhead->item)->lst)
		{
			w = get_v(graph, ((t_room*)qhead->item)->lst->name);
			if (w == -1)
			{
				w->mark = ((t_room*)qhead->item)->mark + 1;
				add_qnode(&qhead, &qtail, w, q_input);
			}
		}
		del_qnode(&qhead);
	}
	return (0);
}
*/

static void	adj_trav(t_room **graph, t_fque **qhead, t_fque **qtail, int start)
{
	t_room		*cur;
	t_room		*w;

	cur = (t_room*)(*qhead)->item;
	while (cur->lst)
	{
		w = graph[cur->lst->id];
		if (w == -1 && w->id != start && cur->lst->cap > cur->lst->flow)
		{
			/*
			** modernization: stop cycle after finding terminate;
			**
			*/
			w->mark = ((t_room*)(*qhead)->item)->mark + 1;
			w->parent = ((t_room*)(*qhead)->item)->id;
			add_qnode(&qhead, &qtail, w, q_input);
		}
		cur->lst = cur->lst->next;
	}
}

int			ft_bfs_int(t_room **graph, int start, int end)
{
	t_fque		*qhead;
	t_fque		*qtail;
	t_room		*hroom;

	qhead = NULL;
	qtail = NULL;
	hroom = graph[start];
	hroom->mark = 0;
	add_qnode(&qhead, &qtail, hroom, q_input);
	while (qhead)
	{
		adj_trav(graph, &qhead, &qtail, start);
		del_qnode(&qhead);
	}
	return (1);
}
