/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bfs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 16:20:42 by gbrandon          #+#    #+#             */
/*   Updated: 2019/11/04 15:40:55 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "avlt.h"
#include "ft_queue.h"
#include <stdio.h> // printf!

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
			i++;
		}
	}
}

static void	adj_trav(t_room **graph, t_fque **qhead, t_fque **qtail, int start)
{
	t_rlist		*cur;
	t_room		*w;

	cur = ((t_room*)(*qhead)->item)->lst;
	while (cur)
	{
		if (cur->cap > cur->flow)
		{
			w = graph[cur->id];
			if (w->mark == -1 && w->id != start)
			{
				/*
				** modernization: stop cycle after finding terminate;
				**
				*/
				w->mark = ((t_room*)(*qhead)->item)->mark + 1;
				w->parent = ((t_room*)(*qhead)->item)->id;
				if ((cur->cap == 0 && graph[cur->id]->lst->twin) || (w->lst->twin && w->lst->flow == 0))
				{
					((t_room*)w->lst->twin)->mark = w->mark;
					add_qnode(qhead, qtail, w->lst->twin, q_input);
					add_qnode(qhead, qtail, w, q_input);
				}
				else
					add_qnode(qhead, qtail, w, q_input);
			}
		}
		cur = cur->next;
	}
}

int			ft_bfs_int(t_room **graph, int start, int end, size_t s)
{
	t_fque		*qhead;
	t_fque		*qtail;
	t_room		*hroom;

	end--;	//
	qhead = NULL;
	qtail = NULL;
	init_arr_bfs(graph, s);
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
