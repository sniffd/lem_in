/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avlt.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 20:05:01 by gbrandon          #+#    #+#             */
/*   Updated: 2019/10/23 19:32:00 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "avlt.h"

t_avlt		*create_node(void *item, void *(*ins)(void *))
{
	t_avlt		*new_node;

	if (!(new_node = (t_avlt*)malloc(sizeof(t_avlt))))
		return (NULL);
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->item = ins(item);
	new_node->height = 1;
	return (new_node);
}

void		add_node(t_avlt **root, void *item, int (*cmp)(void *, void *),\
void *(*ins)(void *))
{
	if (!root)
		return ;
	if (!*root)
	{
		if (!(*root = create_node(item, ins)))
			return ;
	}
	else
	{
		if (cmp(item, (*root)->item) >= 0)
			add_node(&(*root)->right, item, cmp, ins);
		else
			add_node(&(*root)->left, item, cmp, ins);
	}
	balance(root);
}

int			height(t_avlt *node)
{
	return (node ? node->height : 0);
}

void		set_height(t_avlt *node)
{
	int		hl;
	int		hr;

	if (!node)
		return ;
	hl = height(node->left);
	hr = height(node->right);
	node->height = (hl >= hr ? hl : hr) + 1;
}
