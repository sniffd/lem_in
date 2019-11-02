/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edm_karp_mk_twin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 12:42:29 by gbrandon          #+#    #+#             */
/*   Updated: 2019/11/02 17:13:31 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "avlt.h"

void		ek_alg_mk_twin(t_room *room, int start)
{
	t_rlist	*temp;

	if (room->id == start || room->lst->twin)
		return ;
	temp = room->lst;
	room->lst = init_rlist(room->id);
	room->lst->flow = 1;
	room->lst->twin = init_room(room->id, "dup", room->x, room->y);
	((t_room*)(room->lst->twin))->parent = room->id;
	((t_room*)(room->lst->twin))->lst = temp;
}

void		ek_alg_neg_e(t_room *cur, t_room *par, int start)
{
	t_rlist	*temp;

	if (cur->id == start)
		return ;
	temp = cur->lst;
	while(temp->next)
		temp = temp->next;
	temp->next = init_rlist(par->id);
	temp->next->cap = 0;
	temp->next->flow = -1;
}