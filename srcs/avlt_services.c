/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avlt_services.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 17:25:05 by gbrandon          #+#    #+#             */
/*   Updated: 2019/10/30 17:52:27 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "avlt.h"
#include "lem_in.h"

void	*ins(void *ins)
{
	return (ins);
}

int		cmp(void *p1, void *p2)
{
	return (ft_strcmp(((t_room*)p1)->name, ((t_room*)p2)->name));
}

t_room	*get_room(t_avlt *tr, char *name)
{
	if (!tr)
		return (NULL);
	if (ft_strcmp(name, ((t_room*)tr->item)->name) == 0)
		return (tr->item);
	else if (ft_strcmp(name, ((t_room*)tr->item)->name) < 0)
		return (get_room(tr->left, name));
	else if (ft_strcmp(name, ((t_room*)tr->item)->name) > 0)
		return (get_room(tr->right, name));
	return (NULL);
}

t_room	*get_room_id(t_avlt *tr, int id)
{
	if (!tr)
		return (NULL);
	if (id == ((t_room*)tr->item)->id)
		return (tr->item);
	else if (id < ((t_room*)tr->item)->id)
		return (get_room_id(tr->left, id));
	else if (id > ((t_room*)tr->item)->id)
		return (get_room_id(tr->right, id));
	return (NULL);
}
