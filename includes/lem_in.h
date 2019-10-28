#ifndef LEM_IN_LEM_IN_H
# define LEM_IN_LEM_IN_H
# include "libft.h"
# include "avlt.h"

typedef struct	s_rlist
{
	int				id;			// id = id		at start
	int				flow;		// flow = 0		at start
	int				cap;		// cap = 1 		at start
	void			*twin;		// twin = NULL	at start
	//struct	s_rlist	*first;
	//struct	s_rlist	*last;
	//struct	s_rlist	*current;
	struct	s_rlist	*next;
}				t_rlist;

typedef struct	s_room
{
	int				id;			// id = id		at start
	char			*name;		// name = name	at start
	char 			mark;		// mark = -1	at start
	int				parent;		// parent = -1	at start
	int				x;			// x = x		at start
	int				y;			// y = y		at start
	struct	s_rlist	*lst;
}				t_room;

// t_room			*get_v(t_avlt *tr, char *name);
// int				ft_bfs(t_avlt *graph, char *start, char *end);
t_room			*init_room(int id, char *name, int x, int y);
t_rlist			*init_rlist(int id);
void			*q_input(void *it);
int				ft_bfs_int(t_room **graph, int start, int end);
int				edm_karp_alg(t_room **graph, int start, int end);
void			ek_alg_mk_twin(t_room *room, int start);

#endif
