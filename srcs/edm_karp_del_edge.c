/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edm_karp_del_edge.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 19:43:57 by gbrandon          #+#    #+#             */
/*   Updated: 2019/11/08 03:13:58 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "ft_printf.h"

static t_rlist	*find_adj_not_tw(t_room *cur, int id)
{
	t_rlist		*to;

	to = cur->lst;
	while (to)
	{
		if (to->id == id)
			return (to);
		to = to->next;
	}
	return (NULL);
}

static void		del_adj(t_room *cur, t_rlist **to, t_rlist **prev)
{
	cur->lst = cur->lst->next;
	free(*to);
	*to = cur->lst;
	*prev = *to;
}

void			find_del_adj(t_room *cur, int id)
{
	t_rlist		*to;
	t_rlist		*prev;

	to = cur->lst;
	prev = to;
	while (to)
	{
		if (to->id == id)
		{
			if (to == cur->lst)
			{
				del_adj(cur, &to, &prev);
				continue;
			}
			else
			{
				prev->next = to->next;
				free(to);
			}
		}
		else if (to->twin && ((t_room*)to->twin)->lst)
			find_del_adj(to->twin, id);
		prev = to;
		to = to->next;
	}
}

static void		del_path(t_ek_info *box, t_path_agr *paths)
{
	t_path_l	*p;
	t_list		*l;

	p = paths->path_l;
	while (p)
	{
		l = p->path;
		while(l->next)
		{
			if ((((t_room*)l->content)->id == box->cur) && ((t_room*)l->next->content)->id == box->par->id)
				ft_printf("!!size: %d\n", p->len);
			l = l->next;
		}
		p = p->next;
	}
}

int				ek_alg_del_edg(t_room **graph, t_ek_info *box, t_path_agr *paths)
{
	t_rlist		*temp;
	t_room		*cur;

	cur = graph[box->cur];
	if ((temp = find_adj_not_tw(box->par, box->cur)))
	//if ((temp = find_adj_not_tw(graph[box->cur], box->par->id)))
	{
		if (temp->cap == 0)
		{
			del_path(box, paths);
			find_del_adj(cur, box->par->id);
			find_del_adj(box->par, box->cur);
			box->is_ed_del = 1;
		ft_printf("edge: %s->%s\n", box->par->name, cur->name);
			return (1);
		}
	}
	return (0);
}
