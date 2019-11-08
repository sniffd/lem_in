#include "lem_in.h"
#include "ft_printf.h"

static int	pres(char **str, int *f)
{
	int	res;

	res = 0;
	while (**str >= '0' && **str <= '9')
	{
		if (((res * 10 + (**str - '0'))) / 10 != res)
		{
			*f = 1;
			return (-1);
		}
		res = res * 10 + (**str - '0');
		(*str)++;
	}
	return (res);
}

static int	mres(char **str, int *f)
{
	int	res;

	res = 0;
	while (**str >= '0' && **str <= '9')
	{
		if (((res * 10 + (**str - '0'))) / 10 != res)
		{
			*f = 1;
			return (0);
		}
		res = res * 10 + (**str - '0');
		(*str)++;
	}
	return (-res);
}

int			atoi_lem_in(char **str, int *f)
{
	int			sign;

	if (!ft_strcmp(*str, "-2147483648"))
		return (-2147483648);
	sign = 0;
	if (**str == ' ')
		*f = 1;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign = 1;
		(*str)++;
		if (**str == '-' || **str == '+' || **str == ' ' || **str == '\0')
		{
			*f = 1;
			return (0);
		}
	}
	if (sign)
		return (mres(str, f));
	else
		return (pres(str, f));
}

void		appt(void *aa)      // for tree printing
{
	t_room *a;

	a = aa;
	ft_printf("name: %s\n", a->name);
}

void		appt_adj(void *aa)      // for tree printing
{
	t_room 	*a;
	t_rlist	*adj;

	a = aa;
	adj = a->lst;
	ft_printf("->node: %s", a->name);
	ft_printf("-->list: ");
	while (adj)
	{
		ft_printf("%d", adj->id);
		if (adj->next)
			ft_printf(" ");
		adj = adj->next;
	}
	ft_printf("\n");
}

void		error(void)
{
	ft_printf("ERROR\n");
	exit(0);
}

void		free_arr(char **ar)
{
	char	**tmp;

	tmp = ar;
	while (*ar && **ar != '\0')
	{
		free(*ar);
		ar++;
	}
	free(tmp);
}

int			check_command(t_vars *vars)
{
	if (!ft_strcmp(vars->line, "##start"))
	{
		if (vars->start || vars->end || vars->info->start >= 0)
			error();
		else
			vars->start = 1;
	}
	else if (!ft_strcmp(vars->line, "##end"))
	{
		if (vars->start || vars->end || vars->info->end >= 0)
			error();
		else
			vars->end = 1;
	}
	return (1);
}

void		check_coord(char *line, char ***link, int *f)
{
	*link = ft_strsplit(line, ' ');
	if (*line == '\0' || !(*link)[0] || !(*link)[1] || !(*link)[2] ||
	(*link)[3])
		error();
	atoi_lem_in(&((*link)[1]), f);
	atoi_lem_in(&((*link)[2]), f);
	if ((*link)[1][0] != '\0' || (*link)[2][0] != '\0' || *f)
		error();
}

void		add_link(t_room *room_one, t_room *room_two)
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

void		links_parse(t_vars *vars)
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

void		parse_links(t_vars *vars)
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

void		check_lems(t_vars *vars)
{
	char	*str;

	if (get_next_line(0, &(vars->line)) <= 0)
		error();
	str = vars->line;
	if (!(vars->last = (t_list *)ft_memalloc(sizeof(t_list))))
		error();
	vars->last->content = vars->line;
	vars->last->content_size = (size_t)vars->last;
	vars->info->lems = atoi_lem_in(&str, &(vars->f));
	if (*str != '\0' || vars->info->lems <= 0 || vars->f)
		error();
}

void		cycle_end(t_vars *vars)
{
	free_arr(vars->link);
	vars->start = 0;
	vars->end = 0;
}

void		parse_rooms(t_vars *vars)
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

void		print_map(t_vars *vars)
{
	t_list	*lst;
	t_list	*tmp;

	lst = (t_list *)vars->last->content_size;
	while (lst != vars->last)
	{
		ft_putendl(lst->content);
		tmp = lst;
		lst = lst->next;
		free(tmp->content);
		free(tmp);
	}
	ft_putendl(lst->content);
	free(lst->content);
	free(lst);
}

t_sinfo		*parse_lem(void)
{
	t_vars	*vars;

	if (!(vars = (t_vars *)ft_memalloc(sizeof(t_vars))))
		error();
	if (!(vars->info = (t_sinfo *)ft_memalloc(sizeof(t_sinfo))))
		error();
	vars->info->start = -1;
	vars->info->end = -1;
	check_lems(vars);
	parse_rooms(vars);
	if (!(vars->info->graph =
		(t_room**)ft_memalloc(sizeof(t_room*) * vars->id)))
		error();
	vars->start = 0;
	vars->end = 0;
	vars->f = 1;
	parse_links(vars);
	vars->info->size = vars->id;
	ft_printf("all\n");
	if (vars->info->start == -1 || vars->info->end == -1 ||
	!(vars->start && vars->end))
		error();
	print_map(vars);
	return (vars->info);
}
