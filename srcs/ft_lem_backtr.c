/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lem_backtr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 11:30:23 by gbrandon          #+#    #+#             */
/*   Updated: 2019/11/06 15:54:17 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h> // printf!

static t_path_agr	*clean_pathagr(t_path_agr *paths, t_path_agr *tp_pths, size_t this_k, size_t this_len)
{
	t_list	*path;
	t_list	*head_tp_path;
	t_list	*temp;
	t_path_l	*tempp;
	size_t	cntr;

	head_tp_path = NULL;
	temp = NULL;
	cntr = 0;
	while (this_len < paths->path_l->len)
	{
		path = paths->path_l->path;
		if (!head_tp_path)
			head_tp_path = path;
		paths->path_l->path = paths->path_l->path->next;
		path->next = temp;
		temp = path;
		cntr++;
		(paths->len)--;
		(paths->path_l->len)--;
	}
	//reverse list?
	if (paths->path_l->len == 0)
	{
		tempp = paths->path_l;
		paths->path_l = paths->path_l->next;
		free(tempp);
	}
	tp_pths->path_l = ek_alg_mk_path_l(tp_pths->path_l, head_tp_path, cntr);
	tp_pths->len += cntr;
	return (tp_pths);
}

static void			chnge_end_parent(t_sinfo *rooms, t_list **end_prns)
{
	rooms->graph[rooms->end]->parent = (*end_prns)->content_size;
	*end_prns = (*end_prns)->next;
}

t_path_agr		*ft_lem_back(t_sinfo *rooms, t_path_agr *paths)
{
	size_t		this_len;
	size_t		this_k;
	t_list		*end_prns;
	t_path_agr	*temp_paths;

	int er = 0;

	if (!(end_prns = ft_bfs(rooms)))
		return (NULL);
	end_prns = ft_rev_lst(end_prns);
	//while (end_prns)
	//{
	//	printf("par: %zu\n", end_prns->content_size);
	//	end_prns = end_prns->next;
	//}
	temp_paths = init_path_agr(0, rooms->lems, 0);
	this_len = paths->len;
	this_k = paths->pths;
	while (end_prns)
	{
		chnge_end_parent(rooms, &end_prns);
		er = 0;
		ft_bfs_clear_all(rooms->graph, rooms->size);
		if ((paths = edm_karp_alg(rooms, paths, &er, 0)))
		{
			print_paths(paths); // !
			temp_paths = clean_pathagr(paths, temp_paths, this_k, this_len);
		}
	}
	lem_del_paths(&temp_paths);
	return (paths);
}
