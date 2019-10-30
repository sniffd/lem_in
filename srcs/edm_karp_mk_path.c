/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edm_karp_mk_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 19:28:19 by gbrandon          #+#    #+#             */
/*   Updated: 2019/10/30 21:37:56 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "avlt.h"

t_list		*ek_alg_mk_path(t_room *parent,  t_list *lst)
{
	t_list		*path_t;

	path_t = ft_lstnew(NULL, 0);
	path_t->content = parent;
	ft_lstadd(&lst, path_t);
	return (lst);
}

t_path_l		*ek_alg_mk_path_l(t_path_l *path_l, t_list *path, size_t length)
{
	t_path_l		*temp;

	temp = (t_path_l*)malloc(sizeof(t_path_l));
	temp->path = path;
	temp->len = length;
	temp->flow = 0;
	temp->cap = -1;
	temp->next = path_l;
	path_l = temp;
	return (path_l);
}

t_path_agr	*ek_alg_mk_pagr(t_path_agr *pagr, t_ek_info *box)
{
	int		temp;

	pagr->L += box->i;
	(pagr->pths)++;
	temp = ((pagr->L) + (pagr->ants)) / pagr->pths;
	if (((pagr->L) + (pagr->ants)) % pagr->pths != 0)
		temp++;
	else
		temp--;
	if (pagr->dx > temp)
	{
		pagr->dx = temp;
		pagr->path_l = ek_alg_mk_path_l(pagr->path_l, box->path, box->i);
	}
	else
	{
		pagr->L -= box->i;
		(pagr->pths)--;
		pagr->dx = -1;
		ft_lstdel(&(box->path), del_lst);
	}
	return(pagr);
}