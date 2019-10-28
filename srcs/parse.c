#include "lem_in.h"
#include <stdio.h>

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
	int		f;
	int		lems;
	int		id;
	t_avlt	*root;

	line = NULL;
	root = NULL;
	lems = 0;
	f = 0;
	id = 1;
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
		id++;
	}
	printf("all\n");
}