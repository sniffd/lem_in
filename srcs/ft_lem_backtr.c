/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lem_backtr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 11:30:23 by gbrandon          #+#    #+#             */
/*   Updated: 2019/11/06 19:05:34 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h> // printf!

static void			fill_graph_wpths(t_sinfo *rooms, t_path_agr *paths)
{
	t_path_l	*head;
	t_list		*path_head;
	int			id_a;
	int			id_b;

	head = paths->path_l;
	while (head)
	{
		path_head = head->path;
		while (path_head && path_head->next)
		{
			id_a = ((t_room*)path_head->content)->id;
			id_b = ((t_room*)path_head->next->content)->id;
			inc_flow(rooms->graph[id_a], id_b);
			dec_flow(rooms->graph[id_b], id_a);
			ek_alg_neg_e(rooms->graph[id_b], rooms->graph[id_a], 2147483647);
			path_head = path_head->next;
		}
		head = head->next;
	}
}

static t_path_agr	*clean_pathagr(t_path_agr *paths, t_path_agr *tp_pths, size_t this_k, size_t this_len)
{
	t_list		*path;
	t_list		*temp;
	t_path_l	*tempp;
	size_t		cntr;

	temp = NULL;
	cntr = 0;
	(paths->path_l->len)++;
	while (this_len < paths->path_l->len)
	{
		path = paths->path_l->path;
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
	tp_pths->path_l = ek_alg_mk_path_l(tp_pths->path_l, path, cntr);
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

	t_list	*tmp;
	int er = 0;

	if (!(end_prns = ft_bfs(rooms)))
		return (NULL);
	end_prns = ft_rev_lst(end_prns);

	tmp = end_prns;
	while (end_prns)
	{
		printf("par: %zu\n", end_prns->content_size);
		end_prns = end_prns->next;
	}
	end_prns = tmp;
	
	temp_paths = init_path_agr(0, rooms->lems, 0);
	this_len = paths->len;
	this_k = paths->pths;
	while (end_prns)
	{
		chnge_end_parent(rooms, &end_prns);
		er = 0;
		ft_bfs_clear_all(rooms->graph, rooms->size);
		fill_graph_wpths(rooms, paths);
		//print_info(rooms->graph, rooms->size);
		if ((paths = edm_karp_alg(rooms, paths, &er, 0)))
		{
			print_paths(paths); // !
			temp_paths = clean_pathagr(paths, temp_paths, this_k, this_len);
		}
			//print_paths(temp_paths); // !
	}
	lem_del_paths(&temp_paths);
	ft_lstdel(&end_prns, del_lst);
	return (paths);
}
