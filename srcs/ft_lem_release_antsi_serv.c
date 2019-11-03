/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lem_release_antsi_serv.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 22:05:00 by gbrandon          #+#    #+#             */
/*   Updated: 2019/11/03 18:14:13 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		release_antsi_do(size_t *ants_num, t_path_l *path_l, t_list **ants)
{
	t_list		*new_ant;

	new_ant = init_ant(*ants_num, path_l->path->next);
	ft_lstadd(ants, new_ant);
	(path_l->flow)++;
	(*ants_num)++;
}

void		release_antsi_pr_end(t_list *ants, int end)
{
	while (ants)
	{
		move_ants(&ants, end);
		if (ants)
			print_ants(ants);
	}
}
