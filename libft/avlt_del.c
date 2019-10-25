/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avlt_del.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 23:41:23 by gbrandon          #+#    #+#             */
/*   Updated: 2019/10/23 20:19:34 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "avlt.h"
#include <stdlib.h>

static t_avlt	*find_min(t_avlt **node)
{
	t_avlt		*min;

	if (!((*node)->left))
	{
		min = *node;
		*node = (*node)->right;
		return (min);
	}
	min = find_min(&(*node)->left);
	balance(node);
	return (min);
}

static t_avlt	**remove_n_sup(t_avlt **node, t_avlt *r, t_avlt *l)
{
	*node = find_min(&r);
	(*node)->left = l;
	(*node)->right = r;
	balance(node);
	return (node);
}

void			remove_n(t_avlt **node, void *item, int (*cmp)(void *, void *),\
void (*del)(void *))
{
	t_avlt		*r;
	t_avlt		*l;

	if (!node || !*node)
		return ;
	if (cmp(item, (*node)->item) > 0)
		remove_n(&(*node)->right, item, cmp, del);
	else if (cmp(item, (*node)->item) < 0)
		remove_n(&(*node)->left, item, cmp, del);
	else
	{
		r = (*node)->right;
		l = (*node)->left;
		del((*node)->item);
		free(*node);
		if (!r)
		{
			*node = l;
			return ;
		}
		node = remove_n_sup(node, r, l);
		return ;
	}
	balance(node);
}
