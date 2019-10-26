#ifndef LEM_IN_LEM_IN_H
# define LEM_IN_LEM_IN_H
# include "libft.h"
# include "avlt.h"

struct	s_rlist
{
	char			*name;
	struct	s_rlist	*first;
	struct	s_rlist	*last;
	struct	s_rlist	*current;
	struct	s_rlist	*next;
};

typedef struct	s_room
{
	char			*name;
	int 			mark;
	int				x;
	int				y;
	struct	s_rlist	*lst;
}				t_room;

t_room			*get_v(t_avlt *tr, char *name);
int				ft_bfs(t_avlt *graph, char *start, char *end);
void			*q_input(void *it);

#endif
