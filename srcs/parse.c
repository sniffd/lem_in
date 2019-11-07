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

t_sinfo		*parse_lem(void)
{
	char	*line;
	char	*name;
	char	**link;
	char	start;
	char	end;
	int		f;
	int		id;
	int		ret;
	t_avlt	*root;
	t_room	*room;
	t_room	*room_one;
	t_room	*room_two;
	t_rlist	*tmp;
	t_sinfo	*info;

	line = NULL;
	root = NULL;
	f = 0;
	id = 0;
	ret = 1;
	start = 0;
	end = 0;
	if (!(info = (t_sinfo *)ft_memalloc(sizeof(t_sinfo))))
		return (NULL);
	info->start = -1;
	info->end = -1;
	if (get_next_line(0, &line) <= 0)
		return (NULL);
	name = line;
	info->lems = atoi_lem_in(&name, &f);
	if (*name != '\0' || info->lems <= 0 || f)
	{
		free(line);
		free(info);
		return (NULL);
	}
	while (get_next_line(0, &line) > 0 && line && (ft_strchr(line, ' ') || ft_strchr(line, '#')))
	{
		if (*line == '\0')
			return (NULL);
		if (*line == '#')
		{
			if (!ft_strcmp(line, "##start"))
			{
				if (start || end || info->start >= 0)
					return (NULL);
				else
					start = 1;
			}
			else if (!ft_strcmp(line, "##end"))
			{
				if (start || end || info->end >= 0)
					return (NULL);
				else
					end = 1;
			}
			continue;
		}
		link = ft_strsplit(line, ' ');
		if (!link[0] || !link[1] || !link[2] || link[3])
		{
			return (NULL);
		}
		atoi_lem_in(&(link[1]), &f);
		atoi_lem_in(&(link[2]), &f);
		if (link[1][0] != '\0' || link[2][0] != '\0' || f)
		{
			return (NULL);
		}
		name = ft_memalloc(ft_strlen(link[0]) + 1);
		room = init_room(id, ft_memcpy(name, line, ft_strlen(link[0])), 0, 0);
		if (get_room(root, name))
			return (NULL);
		if (start)
			info->start = id;
		else if (end)
			info->end = id;
		add_node(&root, room, cmp, ins);
		free(name);
		free(line);
		start = 0;
		end = 0;
		id++;
	}
	if (!(info->graph = (t_room**)ft_memalloc(sizeof(t_room*) * id)))
	{
		free(line);
		free(info);
		return (NULL);
	}
	start = 0;
	end = 0;
	while (ret && line && *line)
	{
		if (*line == '\0')
			return (NULL);
		if (*line != '#')
		{
			link = ft_strsplit(line, '-');
			if (!(link[1]) || link[2] || !(get_room(root, link[0]) && get_room(root, link[1])))
				return (NULL);
			room_one = get_room(root, link[0]);
			info->graph[room_one->id] = room_one;
			room_two = get_room(root, link[1]);
			info->graph[room_two->id] = room_two;
			if (room_one == room_two)
				return (NULL);
			if (room_one->id == info->start || room_two->id == info->start)
				start = 1;
			if (room_one->id == info->end || room_two->id == info->end)
				end = 1;
			if (!(room_one->lst))
				room_one->lst = init_rlist(room_two->id);
			else
			{
				tmp = room_one->lst;
				while (tmp->next)
					tmp = tmp->next;
				tmp->next = init_rlist(room_two->id);
			}
			if (!(room_two->lst))
				room_two->lst = init_rlist(room_one->id);
			else
			{
				tmp = room_two->lst;
				while (tmp->next)
					tmp = tmp->next;
				tmp->next = init_rlist(room_one->id);
			}
			free(link);
		}
		ret = get_next_line(0, &line);
	}
	info->size = id;
	ft_printf("all\n");
	post_order(root, appt_adj);
	if (info->start == -1 || info->end == -1 || !(start && end))
	{
		free(info);
		return (NULL);
	}
	return (info);
}