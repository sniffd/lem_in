#include <stdio.h>
#include "lem_in.h"

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
	printf("name: %s\n", a->name);
}

void		appt_adj(void *aa)      // for tree printing
{
	t_room 	*a;
	t_rlist	*adj;

	a = aa;
	adj = a->lst;
	printf("->node: %s", a->name);
	printf("-->list: ");
	while (adj)
	{
		printf("%d", adj->id);
		if (adj->next)
			printf(" ");
		adj = adj->next;
	}
	printf("\n");
}

t_sinfo		*parse_lem(void)
{
	char	*line;
	char	*name;
	char	**link;
	char	start;
	char	end;
	int		f;
	int		lems;
	int		id;
	int		ret;
	t_avlt	*root;
	t_room	*room;
	t_room	*room_one;
	t_room	*room_two;
	t_room	**graph;
	t_rlist	*tmp;
	t_sinfo	*info;

	line = NULL;
	root = NULL;
	f = 0;
	id = 0;
	ret = 1;
	start = 0;
	end = 0;
	if (get_next_line(0, &line) <= 0)
		return (NULL);
	lems = atoi_lem_in(&line, &f);
	if (*line != '\0' || lems <= 0 || f)
	{
		free(line);
		return (NULL);
	}
	info = (t_sinfo *)ft_memalloc(sizeof(t_sinfo));
	while (get_next_line(0, &line) > 0 && line && (ft_strchr(line, ' ') || ft_strchr(line, '#')))
	{
		if (ft_strchr(line, '#'))
		{
			if (!ft_strcmp(line, "##start"))
			{
				if (start || end)
					return (NULL);
				else
					start = 1;
			}
			else if (!ft_strcmp(line, "##end"))
			{
				if (start || end)
					return (NULL);
				else
					end = 1;
			}
			continue;
		}
		name = ft_memalloc(ft_strchr(line, ' ') ? ft_strchr(line, ' ') - line + 1: ft_strchr(line, '#') - line + 1);
		room = init_room(id, ft_memcpy(name, line, ft_strchr(line, ' ') - line), 0, 0);
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

	printf("\n\n->Current tree content: \n");
	post_order(root, appt); // just for test

	graph = (t_room**)malloc(sizeof(t_room*) * id);

	while (ret && line && *line)
	{
		if (*line != '#')
		{
			link = ft_strsplit(line, '-');
			if (!(link[1]) || link[2] || !(get_room(root, link[0]) && get_room(root, link[1])))
				return (NULL);
			room_one = get_room(root, link[0]);
			graph[room_one->id] = room_one;
			room_two = get_room(root, link[1]);
			graph[room_two->id] = room_two;
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

	printf("->Current tree content with adjacency: \n");
	post_order(root, appt_adj); // just for test

	info->graph = graph;
	info->size = id;
	info->lems = lems;
	printf("all\n");
	if (info->start == 0 || info->end == 0)
	{
		free(info);
		return (NULL);
	}
	return (info);
}