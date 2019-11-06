/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bfs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 16:20:42 by gbrandon          #+#    #+#             */
/*   Updated: 2019/11/06 14:19:15 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "avlt.h"
#include "ft_queue.h"
#include <stdio.h> // printf!

static void		init_end_par(t_list **end_parns, int id)
{
	t_list	*new_par;

	new_par = ft_lstnew(NULL, 0);
	new_par->content_size = id;
	ft_lstadd(end_parns, new_par);
}

static void		init_arr_bfs(t_room **graph, size_t s)
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

static void		adj_trav(t_sinfo *rooms, t_fque **qhead, t_fque **qtail, t_list **end_par)
{
	t_rlist		*cur;
	t_room		*w;

	//extern int gl;
	//end--;


	cur = ((t_room*)(*qhead)->item)->lst;
	while (cur)
	{
		if (cur->cap > cur->flow)
		{
			w = rooms->graph[cur->id];

			/*if (gl < 1 && (w->id == end))
			{
				gl += 1;
				cur = cur->next;
				printf("hi!\n");
				continue;
			}*/
			if (w->id == rooms->end)
				init_end_par(end_par, ((t_room*)(*qhead)->item)->id);
			if (w->mark == -1 && w->id != rooms->start)
			{
				/*
				** modernization: stop cycle after finding terminate;
				**
				*/
				w->mark = ((t_room*)(*qhead)->item)->mark + 1;
				w->parent = ((t_room*)(*qhead)->item)->id;
				if ((cur->cap == 0 && w->lst->twin) || (w->lst->twin && w->lst->flow == 0))
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

t_list				*ft_bfs(t_sinfo *rooms)
{
	t_fque		*qhead;
	t_fque		*qtail;
	t_room		*hroom;
	t_list		*end_par;

	/*extern int gl_2;
	extern int gl;

	if (gl_2++ < 3)
	{
		gl = 0;
	}*/

	qhead = NULL;
	qtail = NULL;
	end_par = NULL;
	init_arr_bfs(rooms->graph, rooms->size);
	hroom = rooms->graph[rooms->start];
	hroom->mark = 0;
	add_qnode(&qhead, &qtail, hroom, q_input);
	while (qhead)
	{
		adj_trav(rooms, &qhead, &qtail, &end_par);
		del_qnode(&qhead);
	}
	return (end_par);
}
