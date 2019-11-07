/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bfs_clear_all.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 20:28:29 by gbrandon          #+#    #+#             */
/*   Updated: 2019/11/07 14:47:28 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		flow_to_zero(t_room *room)
{
	t_rlist	*adj;

	adj = room->lst;
	while (adj)
	{
		adj->flow = 0;
		if (adj->twin)
		{
			flow_to_zero(adj->twin);
		}
		adj = adj->next;
	}
}

void			ft_bfs_clear_all(t_sinfo *rooms)
{
	size_t		i;

	i = 0;
	while (i < rooms->size)
	{
		if (rooms->graph[i])
		{
			flow_to_zero(rooms->graph[i]);
			rooms->graph[i]->is_in_path = 0;
		}
		i++;
	}
}
