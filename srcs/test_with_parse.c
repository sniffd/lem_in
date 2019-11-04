#include <stdlib.h>
#include <stdio.h>
#include "lem_in.h"

void		print_paths(t_path_agr *paths)
{
	t_list		*path;
	t_path_l	*path_list;

	path_list = paths->path_l;
	printf("Paths: \n");
	while(path_list)
	{
		path = path_list->path;
		printf("size: %zu\n", path_list->len);
		while(path)
		{
			printf("%d", ((t_room*)path->content)->id);
			//printf("%s", ((t_room*)path->content)->name);
			if (path->next)
				printf("->");
			path = path->next;
		}
		printf("\n");
		path_list = path_list->next;
	}
	printf("\n\n");
}

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

int main(void)
{
	t_sinfo		*box;
	t_path_agr	*paths;
	int		err = 0;

	//t_path_l	*temp;
	//t_path_l	*a;
	//t_path_l	*ah;

	//		***
	//		***

	box = parse_lem();
	//printf("size: %zu\n", size);
	//print_info(rooms, size);
	//find_del_adj(box->graph[0], 808);
	//paths = edm_karp_alg(box->graph, box->start, box->end, box->size, box->lems, &err, 0);
	//print_info(box->graph, box->size);
	//print_paths(paths);
	//printf("deleted? :%d\n", err);
	err = 1;
	while(err)
	{
	err = 0;
	ft_bfs_clear_all(box->graph, box->size);
	paths = edm_karp_alg(box->graph, box->start, box->end, box->size, box->lems, &err, 0);
	//print_info(box->graph, box->size);
	print_paths(paths);
	//printf("deleted? :%d\n", err);
	}
	err = 0;
	ft_bfs_clear_all(box->graph, box->size);
	paths = edm_karp_alg(box->graph, box->start, box->end, box->size, box->lems, &err, 0);
	//print_info(box->graph, box->size);
	print_paths(paths);

	/*ah = NULL;
	while(paths->path_l)
	{
		temp = paths->path_l->next;
		a = paths->path_l;
		a->next = ah;
		ah = a;
		paths->path_l = temp;
	}
	paths->path_l = ah;
	print_paths(paths);*/

	release_antsi(paths, box->end);
	lem_del_paths(&paths);
	lem_del_rooms(&(box->graph), box->size);
	return (0);
}