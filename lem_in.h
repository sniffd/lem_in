#ifndef LEM_IN_LEM_IN_H
# define LEM_IN_LEM_IN_H
# include "libft.h"
# include "avlt.h"

typedef struct	s_rlist
{
	int				id;
	int				flow;
	int				cap;
	struct	s_rlist	*first;
	struct	s_rlist	*last;
	struct	s_rlist	*current;
	struct	s_rlist	*next;
}				t_rlist;

typedef struct	s_room
{
	int				id;
	char			*name;
	char 			mark;
	int				parent;
	int				x;
	int				y;
	struct	s_rlist	*lst;
}				t_room;

t_room			*get_v(t_avlt *tr, char *name);
int				ft_bfs(t_avlt *graph, char *start, char *end);
void			*q_input(void *it);
int				ft_bfs_int(t_room **graph, int start, int end);
int				edm_karp_alg(t_room **graph, int start, int end);

#endif
