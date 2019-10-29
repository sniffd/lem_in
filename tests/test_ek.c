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

void		print_info(t_room **rooms)
{
	int			i;
	t_rlist *list;

	i = 0;
	printf("General info:\n");
	while (i < 5)
	{
		printf("mark in room %d: %d\n", i, rooms[i]->mark);
		printf("parent in room %d: %d\n", i, rooms[i]->parent);
		printf("list in room %d: %p\n", i, rooms[i]->lst);
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

t_room		**create_graph_1(int *st, int *ed)
{
	t_room		**rooms;
	t_rlist		*adj;
	int			start;
	int			end;

	start = 0;
	end = 4;
	*st = start;
	*ed = end;
	rooms = (t_room**)malloc(sizeof(t_room*) * 5);

	rooms[0] = init_room(0, "s", 0, 0);
	adj = init_rlist(1);
	adj->next = init_rlist(2);
	rooms[0]->lst = adj;

	rooms[1] = init_room(1, "1", 0, 0);
	adj = init_rlist(end);
	adj->next = init_rlist(start);
	adj->next->next = init_rlist(2); 
	rooms[1]->lst = adj;

	rooms[2] = init_room(2, "2", 0, 0);
	adj = init_rlist(1);
	adj->next = init_rlist(3);
	adj->next->next = init_rlist(start);
	rooms[2]->lst = adj;

	rooms[3] = init_room(3, "3", 0, 0);
	adj = init_rlist(end);
	adj->next = init_rlist(2);
	rooms[3]->lst = adj;

	rooms[4] = init_room(4, "t", 0, 0);
	adj = init_rlist(1);
	adj->next = init_rlist(3);
	rooms[4]->lst = adj;

	return (rooms);
}

t_room		**create_graph_2(int *st, int *ed, size_t *size)
{
	t_room		**rooms;
	t_rlist		*adj;
	int			start;
	int			end;

	start = 0;
	end = 10;
	*size = 12;
	*st = start;
	*ed = end;
	rooms = (t_room**)malloc(sizeof(t_room*) * *size);

	rooms[0] = init_room(0, "s", 0, 0);
	adj = init_rlist(1);
	adj->next = init_rlist(2);
	adj->next->next = init_rlist(3);
	adj->next->next->next = init_rlist(9);
	rooms[0]->lst = adj;

	rooms[1] = init_room(1, "1", 0, 0);
	adj = init_rlist(start);
	adj->next = init_rlist(2);
	adj->next->next = init_rlist(8);
	rooms[1]->lst = adj;

	rooms[2] = init_room(2, "2", 0, 0);
	adj = init_rlist(start);
	adj->next = init_rlist(1);
	adj->next->next = init_rlist(7);
	adj->next->next->next = init_rlist(3);
	rooms[2]->lst = adj;

	rooms[3] = init_room(3, "3", 0, 0);
	adj = init_rlist(2);
	adj->next = init_rlist(4);
	adj->next->next = init_rlist(0);
	rooms[3]->lst = adj;

	rooms[4] = init_room(4, "4", 0, 0);
	adj = init_rlist(3);
	adj->next = init_rlist(5);
	rooms[4]->lst = adj;

	rooms[5] = init_room(5, "5", 0, 0);
	adj = init_rlist(4);
	adj->next = init_rlist(6);
	adj->next->next = init_rlist(11);
	rooms[5]->lst = adj;

	rooms[6] = init_room(6, "6", 0, 0);
	adj = init_rlist(7);
	adj->next = init_rlist(end);
	adj->next->next = init_rlist(5);
	rooms[6]->lst = adj;

	rooms[11] = init_room(11, "11", 0, 0);
	adj = init_rlist(5);
	adj->next = init_rlist(end);
	rooms[11]->lst = adj;

	rooms[7] = init_room(7, "7", 0, 0);
	adj = init_rlist(2);
	adj->next = init_rlist(6);
	adj->next->next = init_rlist(8);
	rooms[7]->lst = adj;

	rooms[end] = init_room(end, "t", 0, 0);
	adj = init_rlist(9);
	adj->next = init_rlist(6);
	adj->next->next = init_rlist(11);
	rooms[end]->lst = adj;

	rooms[8] = init_room(8, "8", 0, 0);
	adj = init_rlist(7);
	adj->next = init_rlist(9);
	adj->next->next = init_rlist(1);
	rooms[8]->lst = adj;

	rooms[9] = init_room(9, "9", 0, 0);
	adj = init_rlist(8);
	adj->next = init_rlist(end);
	adj->next->next = init_rlist(start);
	rooms[9]->lst = adj;

	return (rooms);
}

t_room		**create_graph_3(int *st, int *ed, size_t *size)
{
	t_room		**rooms;
	t_rlist		*adj;
	int			start;
	int			end;

	start = 0;
	end = 1;
	*st = start;
	*ed = end;
	*size = 8;
	rooms = (t_room**)malloc(sizeof(t_room*) * *size);

	rooms[0] = init_room(0, "s", 0, 0);
	adj = init_rlist(5);
	adj->next = init_rlist(3);
	rooms[0]->lst = adj;

	rooms[5] = init_room(5, "5", 0, 0);
	adj = init_rlist(start);
	adj->next = init_rlist(5);
	adj->next->next = init_rlist(2);
	adj->next->next->next = init_rlist(4); 
	rooms[5]->lst = adj;

	rooms[3] = init_room(3, "3", 0, 0);
	adj = init_rlist(start);
	adj->next = init_rlist(4);
	adj->next->next = init_rlist(7);
	rooms[3]->lst = adj;

	rooms[2] = init_room(2, "2", 0, 0);
	adj = init_rlist(6);
	adj->next = init_rlist(5);
	adj->next->next = init_rlist(4);
	rooms[2]->lst = adj;

	rooms[4] = init_room(4, "4", 0, 0);
	adj = init_rlist(5);
	adj->next = init_rlist(3);
	adj->next->next = init_rlist(2);
	adj->next->next->next = init_rlist(end); 
	rooms[4]->lst = adj;

	rooms[end] = init_room(end, "t", 0, 0);
	adj = init_rlist(6);
	adj->next = init_rlist(4);
	adj->next->next = init_rlist(7);
	rooms[end]->lst = adj;

	rooms[6] = init_room(6, "6", 0, 0);
	adj = init_rlist(end);
	adj->next = init_rlist(2);
	rooms[6]->lst = adj;

	rooms[7] = init_room(7, "7", 0, 0);
	adj = init_rlist(end);
	adj->next = init_rlist(3);
	rooms[7]->lst = adj;

	return (rooms);
}

int main(void)
{
	int			start;
	int			end;
	size_t		size;
	t_room		**rooms;
	t_path_agr	*paths;


	//		***
	//		***
	//		5 rooms

	rooms = create_graph_3(&start, &end, &size);
	//print_info(rooms);
	paths = edm_karp_alg(rooms, start, end, size, 100000);
	//print_paths(paths);
	release_antsi(paths, end);
	return (0);
}