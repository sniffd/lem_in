/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edm_karp_edge_work.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 14:54:54 by gbrandon          #+#    #+#             */
/*   Updated: 2019/11/07 22:36:03 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "avlt.h"

static int	inc_flow(t_room *room, int connect)
{
	t_rlist		*to;

	if (!(to = find_adj(room, connect)))
		return (-2);
	to->flow += 1;
	return (0);
}

static int	dec_flow(t_room *room, int connect)
{
	t_rlist		*to;

	if (!(to = find_adj(room, connect)))
		return (-2);
	to->flow += 1;
	return (0);
}

 int		edm_karp_edgew(t_sinfo *rooms, t_ek_info *box)
{
	if (inc_flow(box->par, box->cur) < 0)
		return (0);
	if (dec_flow(rooms->graph[box->cur], box->par->id) < 0)
		return (0);
	ek_alg_mk_twin(box->par, rooms->start);
	ek_alg_neg_e(rooms->graph[box->cur], box->par, rooms->start);
	return (1);
}
