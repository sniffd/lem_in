#include "lem_in.h"
#include "ft_printf.h"

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

void		error(void)
{
	ft_printf("ERROR\n");
	exit(0);
}
