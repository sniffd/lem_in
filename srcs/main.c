/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 05:22:16 by gbrandon          #+#    #+#             */
/*   Updated: 2019/11/08 05:24:47 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "lem_in.h"

int g_fl = 0;

static void	release_antss(t_sinfo *box, t_path_agr *paths)
{
	int			stra_num;

	stra_num = 0;
	if (paths && paths->path_l)
	{
		ft_lem_log("releasing ants...\n", 3, 2, 1);
		release_antsi(paths, box->end, &stra_num);
		print_lems(stra_num);
	}
}

static void	find_paths(t_sinfo *box, t_path_agr **paths)
{
	int		err;

	ft_lem_log("finding paths...\n", 0, 2, 0);
	err = 1;
	while (err)
	{
		err = 0;
		ft_bfs_clear_all(box);
		ft_lem_log("starting edm_karp...\n", 1, 2, 1);
		if (!(*paths = edm_karp_alg(box, &err)))
			break ;
		ft_lem_log("finish edm_karp.\n", 1, 2, 1);
		print_paths(*paths);
		if (err)
			lem_del_paths(paths);
	}
	if (*paths && !((*paths)->path_l))
		error();
}

void		parse_flags(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-')
		{
			if (ft_strchr(argv[i], 'v'))
				g_fl |= 2;
			if (ft_strchr(argv[i], 'd'))
				g_fl |= 1;
			if (ft_strchr(argv[i], 'p'))
				g_fl |= 4;
		}
		i++;
	}
}

int			main(int argc, char **argv)
{
	t_sinfo		*box;
	t_path_agr	*paths;

	if (argc > 1)
		parse_flags(argc, argv);
	if (!(box = parse_lem()))
		error();
	find_paths(box, &paths);
	release_antss(box, paths);
	lem_del_paths(&paths);
	lem_del_rooms(&(box->graph), box->size);
	exit(0);
}
