#include "lem_in.h"

static void		add_link(t_room *room_one, t_room *room_two)
{
	t_rlist	*tmp;

	if (!(room_one->lst))
		room_one->lst = init_rlist(room_two->id);
	else
	{
		tmp = room_one->lst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = init_rlist(room_two->id);
	}
}

static void		cycle_end(t_vars *vars)
{
	free_arr(vars->link);
	vars->start = 0;
	vars->end = 0;
}

void			parse_rooms(t_vars *vars)
{
	while (get_next_line(0, &(vars->line)) > 0 && vars->line &&
	(ft_strchr(vars->line, ' ') || ft_strchr(vars->line, '#')))
	{
		if (!(vars->last->next = (t_list *)ft_memalloc(sizeof(t_list))))
			error();
		vars->last->next->content_size = vars->last->content_size;
		vars->last = vars->last->next;
		vars->last->content = vars->line;
		if (*(vars->line) == '#' && check_command(vars))
			continue;
		check_coord(vars->line, &(vars->link), &(vars->f));
		vars->room = init_room(vars->id, (vars->link)[0], 0, 0);
		if (get_room(vars->root, (vars->link)[0]))
			error();
		if (vars->start)
			vars->info->start = vars->id;
		else if (vars->end)
			vars->info->end = vars->id;
		add_node(&(vars->root), vars->room, cmp, ins);
		cycle_end(vars);
		(vars->id)++;
	}
}

static void		links_parse(t_vars *vars)
{
	t_room	*room_one;
	t_room	*room_two;
	char	**link;

	link = ft_strsplit(vars->line, '-');
	if (!(link[1]) || link[2] || !(get_room(vars->root, link[0]) &&
	get_room(vars->root, link[1])) || link[0] == link[1])
		error();
	room_one = get_room(vars->root, link[0]);
	vars->info->graph[room_one->id] = room_one;
	room_two = get_room(vars->root, link[1]);
	vars->info->graph[room_two->id] = room_two;
	if (room_one->id == vars->info->start || room_two->id == vars->info->start)
		vars->start = 1;
	if (room_one->id == vars->info->end || room_two->id == vars->info->end)
		vars->end = 1;
	add_link(room_one, room_two);
	add_link(room_two, room_one);
	free_arr(link);
}

void			parse_links(t_vars *vars)
{
	while (vars->f && vars->line && *(vars->line))
	{
		if (!(vars->last->next = (t_list *)ft_memalloc(sizeof(t_list))))
			error();
		vars->last->next->content_size = vars->last->content_size;
		vars->last = vars->last->next;
		vars->last->content = vars->line;
		if (*(vars->line) == '\0')
			error();
		if (*(vars->line) != '#')
			links_parse(vars);
		vars->f = get_next_line(0, &(vars->line));
	}
}
