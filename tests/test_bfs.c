#include <stdlib.h>
#include <stdio.h>
#include "lem_in.h"

int main(void)
{
	int			start;
	int			end;
	int			i;
	t_room		**rooms;
	t_rlist		*adj;

	//		***
	//		***
	//		5 rooms

	i = 0;
	start = 0;
	end = 4;
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


	ft_bfs_int(rooms, start, end);
	while (i < 5)
	{
		printf("mark in room %d: %d\n", i, rooms[i]->mark);
		printf("parent in room %d: %d\n", i, rooms[i]->parent);
		i++;
	}

	//		***
	//		***
	//		s->1->t 3 rooms

	i = 0;
	start = 0;
	end = 2;
	rooms = (t_room**)malloc(sizeof(t_room*) * 3);

	rooms[0] = init_room(0, "s", 0, 0);
	adj = init_rlist(1);
	rooms[0]->lst = adj;

	rooms[1] = init_room(1, "1", 0, 0);
	adj = init_rlist(end);
	rooms[1]->lst = adj;

	rooms[2] = init_room(2, "t", 0, 0);
	adj = NULL;
	rooms[2]->lst = adj;

	ft_bfs_int(rooms, start, end);

	//		***
	//		***
	//		s->t 2 rooms

	i = 0;
	start = 0;
	end = 1;
	rooms = (t_room**)malloc(sizeof(t_room*) * 2);

	rooms[0] = init_room(start, "s", 0, 0);
	adj = init_rlist(end);
	rooms[0]->lst = adj;

	rooms[1] = init_room(end, "t", 0, 0);
	adj = NULL;
	rooms[1]->lst = adj;

	ft_bfs_int(rooms, start, end);
}