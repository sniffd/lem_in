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

int			check_command(char *line, char *start, char *end, t_sinfo *info)
{
	if (!ft_strcmp(line, "##start"))
	{
		if (*start || *end || info->start >= 0)
			error();
		else
			*start = 1;
	}
	else if (!ft_strcmp(line, "##end"))
	{
		if (*start || *end || info->end >= 0)
			error();
		else
			*end = 1;
	}
	return (1);
}

void		check_coord(char *line, char ***link, int *f)
{
	*link = ft_strsplit(line, ' ');
	if (*line == '\0' || !(*link)[0] || !(*link)[1] || !(*link)[2] || (*link)[3])
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

void		parse_links(char *line, t_avlt *root, t_sinfo *info, char *start, char *end)
{
	t_room	*room_one;
	t_room	*room_two;
	char	**link;

	link = ft_strsplit(line, '-');
	if (!(link[1]) || link[2] || !(get_room(root, link[0]) && get_room(root, link[1])) || link[0] == link[1])
		error();
	room_one = get_room(root, link[0]);
	info->graph[room_one->id] = room_one;
	room_two = get_room(root, link[1]);
	info->graph[room_two->id] = room_two;
	if (room_one->id == info->start || room_two->id == info->start)
		*start = 1;
	if (room_one->id == info->end || room_two->id == info->end)
		*end = 1;
	add_link(room_one, room_two);
	add_link(room_two, room_one);
	free_arr(link);
}

void		check_lems(char	**line, int *f, t_sinfo *info)
{
	char	*str;

	if (get_next_line(0, line) <= 0)
		error();
	str = *line;
	info->lems = atoi_lem_in(&str, f);
	if (*str != '\0' || info->lems <= 0 || *f)
		error();
}

t_sinfo		*parse_lem(void)
{
	char	*line;
	char	**link;
	char	start;
	char	end;
	int		f;
	int		id;
	t_avlt	*root;
	t_room	*room;
	t_sinfo	*info;

	line = NULL;
	root = NULL;
	f = 0;
	id = 0;
	start = 0;
	end = 0;
	if (!(info = (t_sinfo *)ft_memalloc(sizeof(t_sinfo))))
		error();
	info->start = -1;
	info->end = -1;
	check_lems(&line, &f, info);
	while (get_next_line(0, &line) > 0 && line && (ft_strchr(line, ' ') || ft_strchr(line, '#')))
	{
		if (*line == '#' && check_command(line, &start, &end, info))
			continue;
		check_coord(line, &link, &f);
		room = init_room(id, link[0], 0, 0);
		if (get_room(root, link[0]))
			error();
		if (start)
			info->start = id;
		else if (end)
			info->end = id;
		add_node(&root, room, cmp, ins);
		free(line);
		free_arr(link);
		start = 0;
		end = 0;
		id++;
	}
	if (!(info->graph = (t_room**)ft_memalloc(sizeof(t_room*) * id)))
		error();
	start = 0;
	end = 0;
	f = 1;
	while (f && line && *line)
	{
		if (*line == '\0')
			error();
		if (*line != '#')
			parse_links(line, root, info, &start, &end);
		f = get_next_line(0, &line);
	}
	post_order(root, appt_adj);
	info->size = id;
	ft_printf("all\n");
	if (info->start == -1 || info->end == -1 || !(start && end))
		error();
	return (info);
}