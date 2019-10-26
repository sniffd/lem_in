#include "lem_in.h"

t_room	*init(char *name, int x, int y)
{
	t_room	*room;

	room = ft_memalloc(sizeof(t_room));
	room->x = x;
	room->y = y;
	room->name = ft_strdup(name);
	return (room);
}

int		main()
{
	return 0;
}