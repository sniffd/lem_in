/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 13:09:10 by gbrandon          #+#    #+#             */
/*   Updated: 2019/10/28 21:49:02 by fdaryn-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	t_room	**gr;
	size_t	p1;
	size_t	p2;


	parse_lem(&gr, &p1, &p2);
	return 0;
}