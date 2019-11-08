#include "lem_in.h"
#include "ft_printf.h"

extern	int	g_lf;

void			free_arr(char **ar)
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

static void		print_map(t_vars *vars)
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
	print_tree(vars->root);
	lem_del_tree(&(vars->root));
}

void			nul(t_vars *vars)
{
	vars->start = 0;
	vars->end = 0;
	vars->f = 1;
}

t_sinfo			*parse_lem(void)
{
	t_vars	*vars;
	t_sinfo	*res;

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
	nul(vars);
	parse_links(vars);
	vars->info->size = vars->id;
	ft_printf("\n\n");
	if (vars->info->start == -1 || vars->info->end == -1 ||
	!(vars->start && vars->end))
		error();
	print_map(vars);
	res = vars->info;
	free(vars);
	return (res);
}
