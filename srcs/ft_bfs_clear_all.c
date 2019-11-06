/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bfs_clear_all.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 20:28:29 by gbrandon          #+#    #+#             */
/*   Updated: 2019/11/06 16:53:16 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		flow_to_zero(t_room *room)
{
	t_rlist	*adj;

	adj = room->lst;
	while(adj)
	{
		adj->flow = 0;
		if (adj->twin)
		{
			flow_to_zero(adj->twin);
		}
		adj = adj->next;
	}
}

void	ft_bfs_clear_all(t_room **graph, size_t s)
{
	size_t		i;

	i = 0;
	while (i < s)
	{
		if (graph[i])
		{
			flow_to_zero(graph[i]);
			graph[i]->is_in_path = 0;
		}
		i++;
	}
}