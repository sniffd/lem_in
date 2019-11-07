#include <stdlib.h>
#include <stdio.h>
#include "lem_in.h"

void		print_info(t_room **rooms, size_t size)
{
	size_t		i;
	t_rlist 	*list;
	t_rlist		*tw_list;

	i = 0;
	printf("General info:\n");
	while (i < size)
	{
		printf("mark in room %zu: %d\n", i, rooms[i]->mark);
		printf("parent in room %zu: %d\n", i, rooms[i]->parent);
		printf("list in room %zu: %p\n", i, rooms[i]->lst);
		list = rooms[i]->lst;
		if (list->twin)
		{
			tw_list = ((t_room*)list->twin)->lst;
			printf("--TWIN--\n");
			while(tw_list)
			{
				printf("-->id: %d\n", tw_list->id);
				printf("-->float: %d\n", tw_list->flow);
				printf("-->capacity: %d\n", tw_list->cap);
				printf("-->twin: %p\n", tw_list->twin);
				tw_list = tw_list->next;
			}
			printf("--**--\n");
		}
		while(list)
		{
			printf("->id: %d\n", list->id);
			printf("->float: %d\n", list->flow);
			printf("->capacity: %d\n", list->cap);
			printf("->twin: %p\n", list->twin);
			list = list->next;
		}
		i++;
	}
	printf("\n\n");
}

int g_fl = 4; // 1 - easy dg 10 - hard dg 11 - together 100 - print num

int main(void)
{
	t_sinfo		*box;
	t_path_agr	*paths;
	int		err = 0;
	int			stra_num = 0;

	box = parse_lem();
	ft_lem_log("finding paths...\n", 0, 2, 0);
	err = 1;
	while(err)
	{
		err = 0;
		ft_bfs_clear_all(box);
		ft_lem_log("starting edm_karp...\n", 1, 2, 1);
		paths = edm_karp_alg(box, &err);
		ft_lem_log("finish edm_karp.\n", 1, 2, 1);
		print_paths(paths);
		if (err)
			lem_del_paths(&paths);
	}
	//err = 0;
	//ft_bfs_clear_all(box);
	//ft_lem_log("starting edm_karp...\n", 1, 2, 1);
	//paths = edm_karp_alg(box, &err);
	//ft_lem_log("finish edm_karp.\n", 1, 2, 1);
	//print_paths(paths);

	ft_lem_log("releasing ants...\n", 3, 2, 1);
	release_antsi(paths, box->end, &stra_num);
	print_lems(stra_num);
	lem_del_paths(&paths);
	lem_del_rooms(&(box->graph), box->size);
	return (0);
}