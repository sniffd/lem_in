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

int			*parse()
{
	char	*line;
	char	*name;
	char	**link;
	int		f;
	int		lems;
	int		id;
	int		ret;
	t_avlt	*root;
	t_room	*room_one;
	t_room	*room_two;
	t_rlist	*tmp;

	line = NULL;
	root = NULL;
	f = 0;
	id = 1;
	ret = 1;
	printf("SUKA\n");
	if (get_next_line(0, &line) <= 0)
		return (NULL);
	lems = atoi_lem_in(&line, &f);
	if (*line != '\0' || lems <= 0 || f)
	{
		free(line);
		return (NULL);
	}
	while (get_next_line(0, &line) > 0 && line && (ft_strchr(line, ' ') || ft_strchr(line, '#')))
	{
		if (ft_strchr(line, '#'))
			continue;
		name = ft_memalloc(ft_strchr(line, ' ') ? ft_strchr(line, ' ') - line : ft_strchr(line, '#') - line);
		add_node(&root, init_room(id, ft_memcpy(name, line, ft_strchr(line, ' ') - line), 0, 0), cmp, ins);
		free(name);
		free(line);
		id++;
	}
	while (ret && line && *line)
	{
		if (*line != '#')
		{
			link = ft_strsplit(line, '-');
			room_one = get_room(root, link[0]);
			room_two = get_room(root, link[1]);
			if (!(room_one->lst))
			{
				room_one->lst = ft_memalloc(sizeof(t_rlist));
				room_one->lst->id = room_two->id;
			}
			else
			{
				tmp = room_one->lst;
				while (tmp->next)
					tmp = tmp->next;
				tmp->next = ft_memalloc(sizeof(t_rlist));
				tmp = tmp->next;
				tmp->id = room_two->id;
			}
			if (!(room_two->lst))
			{
				room_two->lst = ft_memalloc(sizeof(t_rlist));
				room_two->lst->id = room_one->id;
			}
			else
			{
				tmp = room_two->lst;
				while (tmp->next)
					tmp = tmp->next;
				tmp->next = ft_memalloc(sizeof(t_rlist));
				tmp = tmp->next;
				tmp->id = room_one->id;
			}
			free(link);
		}
		ret = get_next_line(0, &line);
	}
	printf("all\n");

	return (0);   // value up to u
}