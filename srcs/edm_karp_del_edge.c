/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edm_karp_del_edge.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 19:43:57 by gbrandon          #+#    #+#             */
/*   Updated: 2019/11/08 04:11:03 by gbrandon         ###   ########.fr       */
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

int				ek_alg_del_edg(t_room **graph, t_ek_info *box)
{
	t_rlist		*temp;
	t_room		*cur;

	cur = graph[box->cur];
	if ((temp = find_adj_not_tw(box->par, box->cur)))
	{
		if (temp->cap == 0)
		{
			find_del_adj(cur, box->par->id);
			find_del_adj(box->par, box->cur);
			box->is_ed_del = 1;
			return (1);
		}
	}
	return (0);
}
