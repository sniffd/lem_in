/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edm_karp_mk_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 19:28:19 by gbrandon          #+#    #+#             */
/*   Updated: 2019/10/28 20:50:19 by gbrandon         ###   ########.fr       */
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

t_list		*ek_alg_mk_path_l(t_list *path_l, t_list *path, int length)
{
	t_list		*temp;

	temp = (t_list*)malloc(sizeof(t_list));
	temp->content = path;
	temp->content_size = length;
	ft_lstadd(&path_l, temp);
	return (path_l);
}