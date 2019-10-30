/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avlt_tranc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:58:17 by gbrandon          #+#    #+#             */
/*   Updated: 2019/10/23 19:19:54 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "avlt.h"

void		pre_order(t_avlt *root, void (*appt)(void *))
{
	if (!root)
		return ;
	appt(root->item);
	pre_order(root->left, appt);
	pre_order(root->right, appt);
}

void		in_order(t_avlt *root, void (*appt)(void *))
{
	if (!root)
		return ;
	in_order(root->left, appt);
	appt(root->item);
	in_order(root->right, appt);
}

void		post_order(t_avlt *root, void (*appt)(void *))
{
	if (!root)
		return ;
	post_order(root->left, appt);
	post_order(root->right, appt);
	appt(root->item);
}
