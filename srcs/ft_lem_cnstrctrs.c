/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lem_cnstrctrs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 13:10:28 by gbrandon          #+#    #+#             */
/*   Updated: 2019/10/28 21:22:05 by fdaryn-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*init_room(int id, char *name, int x, int y)
{
	t_room	*room;

	room = ft_memalloc(sizeof(t_room));
	room->id = id;
	room->name = ft_strdup(name);
	room->mark = -1;
	room->parent = -1;
	room->x = x;
	room->y = y;
	room->lst = NULL;
	return (room);
}

t_rlist	*init_rlist(int id)
{
	t_rlist	*adj;

	adj = (t_rlist*)malloc(sizeof(t_rlist));
	adj->id = id;
	adj->flow = 0;
	adj->cap = 1;
	adj->twin = NULL;
	adj->next = NULL;
	return (adj);
}

void	*ins(void *ins)
{
	return (ins);
}

int		cmp(void *p1, void *p2)
{
	return (ft_strcmp(p1, p2));
}
