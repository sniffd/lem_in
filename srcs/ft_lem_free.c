/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lem_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 15:19:03 by gbrandon          #+#    #+#             */
/*   Updated: 2019/11/07 21:18:03 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	del_lst(void *it, size_t s)
{
	it = NULL;
	s++;
	return ;
}

void	lem_del_paths(t_path_agr **paths)
{
	t_path_l	*path_l;
	t_path_l	*temp;

	if (!paths || !(*paths))
		return ;
	path_l = (*paths)->path_l;
	while (path_l)
	{
		ft_lstdel(&(path_l->path), del_lst);
		temp = path_l;
		path_l = path_l->next;
		free(temp);
	}
	free(*paths);
	*paths = NULL;
}

void	lem_del_rlist(t_rlist *adj)
{
	t_room		*tw;
	t_rlist		*temp;

	while (adj)
	{
		if (adj->twin)
		{
			tw = adj->twin;
			if (tw->name)
				free(tw->name);
			lem_del_rlist(tw->lst);
			free(tw);
		}
		temp = adj;
		adj = adj->next;
		free(temp);
	}
}

void	lem_del_rooms(t_room ***graph, size_t s)
{
	size_t i;

	i = 0;
	if (!graph || !(*graph))
		return ;
	while (i < s)
	{
		if ((*graph)[i])
		{
			lem_del_rlist((*graph)[i]->lst);
			free((*graph)[i]->name);
			free((*graph)[i]);
		}
		i++;
	}
	free(*graph);
	*graph = NULL;
}

void	lem_del_tree(t_avlt **tr)
{
	// free alone vertex!
	if (!tr || !(*tr))
		return ;
	lem_del_tree(&((*tr)->left));
	lem_del_tree(&((*tr)->right));
	free(*tr);
	*tr = NULL;
}
