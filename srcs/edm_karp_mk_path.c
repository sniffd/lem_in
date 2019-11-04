/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edm_karp_mk_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 19:28:19 by gbrandon          #+#    #+#             */
/*   Updated: 2019/11/04 20:42:32 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //printf!!
#include "lem_in.h"
#include "avlt.h"

t_list		*ek_alg_mk_path(t_room *parent,  t_list *lst)
{
	t_list		*path_t;

	path_t = ft_lstnew(NULL, 0);
	if (parent->is_in_path && parent->id != 0 && parent->id != 1) // attent on this parent->id
		printf("\nATTENTION_%d\n", parent->id);
	parent->is_in_path = 1;
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

static void	free_path_connect(t_list *path)
{
	while (path)
	{
		((t_room*)path->content)->is_in_path = 0;
		path = path->next;
	}
}

t_path_agr	*ek_alg_mk_pagr(t_path_agr *pagr, t_ek_info *box, int par)
{
	int		temp;

	pagr->L += box->i;
	(pagr->pths)++;
	temp = ((pagr->L) + (pagr->ants)) / pagr->pths;
	if (((pagr->L) + (pagr->ants)) % pagr->pths != 0)
		temp++;
	else
		temp--;
	if (par)
	{
		pagr->dx = temp;
		pagr->path_l = ek_alg_mk_path_l(pagr->path_l, box->path, box->i);		
	}
	else
	{
	if (pagr->dx >= temp)
	{
		pagr->dx = temp;
		pagr->path_l = ek_alg_mk_path_l(pagr->path_l, box->path, box->i);
	}
	else
	{
		pagr->L -= box->i;
		(pagr->pths)--;
		pagr->dx = -1;
		free_path_connect(box->path);
		ft_lstdel(&(box->path), del_lst);
	}
	}
	return(pagr);
}