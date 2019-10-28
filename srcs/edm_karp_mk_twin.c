/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edm_karp_mk_twin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 12:42:29 by gbrandon          #+#    #+#             */
/*   Updated: 2019/10/28 14:12:16 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "avlt.h"

void			ek_alg_mk_twin(t_room *room, int start)
{
	t_rlist	*temp;

	if (room->id == start)
		return ;
	temp = room->lst;
	room->lst = init_rlist(2147483647);
	room->lst->flow = 1;
	room->lst->twin = init_room(2147483647, "dup", room->x, room->y);
	((t_room*)(room->lst->twin))->parent = room->id;
	((t_room*)(room->lst->twin))->lst = temp;
}