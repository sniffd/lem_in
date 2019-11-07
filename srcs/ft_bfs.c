/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bfs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 16:20:42 by gbrandon          #+#    #+#             */
/*   Updated: 2019/11/07 21:16:04 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "avlt.h"
#include "ft_queue.h"
#include <stdio.h>

static void	init_arr_bfs(t_room **graph, size_t s)
{
	size_t		i;

	i = 0;
	while (i < s)
	{
		if (graph[i])
		{
			graph[i]->mark = -1;
			graph[i]->parent = -1;
		}
		i++;
	}
}

static void	adj_trav(t_sinfo *rooms, t_fque **qhead, t_fque **qtail)
{
	t_rlist		*cur;
	t_room		*w;

	cur = ((t_room*)(*qhead)->item)->lst;
	while (cur)
	{
		if (cur->cap > cur->flow)
		{
			w = rooms->graph[cur->id];
			if (w->mark == -1 && w->id != rooms->start)
			{
				w->mark = ((t_room*)(*qhead)->item)->mark + 1;
				w->parent = ((t_room*)(*qhead)->item)->id;
				if ((cur->cap == 0 && w->lst->twin) ||
					(w->lst->twin && w->lst->flow == 0))
				{
					((t_room*)w->lst->twin)->mark = w->mark;
					add_qnode(qhead, qtail, w->lst->twin, q_input);
				}
				add_qnode(qhead, qtail, w, q_input);
			}
		}
		cur = cur->next;
	}
}

int			ft_bfs(t_sinfo *rooms)
{
	t_fque		*qhead;
	t_fque		*qtail;
	t_room		*hroom;

	qhead = NULL;
	qtail = NULL;
	init_arr_bfs(rooms->graph, rooms->size);
	hroom = rooms->graph[rooms->start];
	hroom->mark = 0;
	add_qnode(&qhead, &qtail, hroom, q_input);
	while (qhead)
	{
		if (((t_room*)qhead->item)->id != rooms->end)
			adj_trav(rooms, &qhead, &qtail);
		del_qnode(&qhead);
	}
	return (1);
}
