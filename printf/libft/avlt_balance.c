/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avlt_balance.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 16:16:36 by gbrandon          #+#    #+#             */
/*   Updated: 2019/10/23 19:06:23 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "avlt.h"

int		balancef(t_avlt *node)
{
	return (height(node->right) - height(node->left));
}

void	balance(t_avlt **node)
{
	int	bf;

	set_height(*node);
	bf = balancef(*node);
	if (bf == 2)
	{
		if (balancef((*node)->right) < 0)
			(*node)->right = rotater((*node)->right);
		*node = rotatel(*node);
	}
	else if (bf == -2)
	{
		if (balancef((*node)->left) > 0)
			(*node)->left = rotatel((*node)->left);
		*node = rotater(*node);
	}
}

t_avlt	*rotater(t_avlt *node)
{
	t_avlt	*s;

	s = node->left;
	node->left = s->right;
	s->right = node;
	set_height(node);
	set_height(s);
	return (s);
}

t_avlt	*rotatel(t_avlt *node)
{
	t_avlt	*q;

	q = node->right;
	node->right = q->left;
	q->left = node;
	set_height(node);
	set_height(q);
	return (q);
}
