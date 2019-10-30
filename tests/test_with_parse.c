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

	i = 0;
	printf("General info:\n");
	while (i < size)
	{
		printf("mark in room %zu: %d\n", i, rooms[i]->mark);
		printf("parent in room %zu: %d\n", i, rooms[i]->parent);
		printf("list in room %zu: %p\n", i, rooms[i]->lst);
		list = rooms[i]->lst;
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
	int			start;
	int			end;
	size_t		size;
	size_t		ants;
	t_room		**rooms;
	t_path_agr	*paths;

	//t_path_l	*temp = NULL;
	//t_path_l	*a;


	//		***
	//		***
	//		5 rooms

	//rooms = create_graph_2(&start, &end, &size);
	parse(&rooms, &size, &ants);
	start = 0;
	end = 1;
	//printf("size: %zu\n", size);
	//print_info(rooms, size);
	paths = edm_karp_alg(rooms, start, end, size, ants);
	//temp = paths->path_l;
	//while(paths->path_l)
	//{
	//	a = temp;
	//	temp = paths->path_l;
	//	paths->path_l = paths->path_l->next;
	//	temp->next = a;
	//}
	//paths->path_l = temp;
	print_paths(paths);
	//release_antsi(paths, end);
	lem_del_paths(&paths);
	lem_del_rooms(&rooms, size);
	return (0);
}