/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avlt_services.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 17:25:05 by gbrandon          #+#    #+#             */
/*   Updated: 2019/10/26 17:48:33 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "avlt.h"
#include "lem_in.h"

t_room		*get_v(t_avlt *tr, char *name)
{
	if(!tr)
		return (NULL);
	if (ft_strcmp(((t_room*)tr->item)->name, name) == 0)
		return ((t_room*)tr->item);
	else if (ft_strcmp(((t_room*)tr->item)->name, name) < 0)
		return (get_v(tr->left, name));
	else if (ft_strcmp(((t_room*)tr->item)->name, name) > 0)
		return (get_v(tr->right, name));
}