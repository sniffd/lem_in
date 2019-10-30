#ifndef LEM_IN_LEM_IN_H
# define LEM_IN_LEM_IN_H
# include "libft.h"
# include "get_next_line.h"
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

typedef struct	s_path_l
{
	t_list			*path;
	size_t			len;
	int				flow;
	int				cap;
	struct s_path_l	*next;
}				t_path_l;

typedef struct	s_path_agr
{
	size_t			L;
	size_t			ants;
	size_t			pths;
	int				dx;
	t_path_l		*path_l;
}				t_path_agr;

typedef struct	s_ek_info
{
	t_room			*par;
	int				cur;
	size_t			i;
	t_list			*path;
}				t_ek_info;

// t_room			*get_v(t_avlt *tr, char *name);
// int				ft_bfs(t_avlt *graph, char *start, char *end);
t_room			*init_room(int id, char *name, int x, int y);
t_rlist			*init_rlist(int id);
t_path_agr		*init_path_agr(int l, int n, int k);
t_ek_info		*init_ek_info(t_room **graph, int end, int cntr);
void			*ins(void *ins);
int				*parse();
int				cmp(void *p1, void *p2);
void			*q_input(void *it);
int				ft_bfs_int(t_room **graph, int start, int end, size_t s);
t_path_agr		*edm_karp_alg(t_room **graph, int start, int end, size_t s, size_t ants);
void			ek_alg_mk_twin(t_room *room, int start);
t_list			*ek_alg_mk_path(t_room *parent,  t_list *lst);
t_path_l		*ek_alg_mk_path_l(t_path_l *path_l, t_list *path, size_t length);
t_path_agr		*ek_alg_mk_pagr(t_path_agr *pagr, t_ek_info *box);
void			del_lst(void *it, size_t s);
int				release_antsi(t_path_agr *paths, int end);
t_room			*get_room(t_avlt *tr, char *name);
t_list			*init_ant(size_t id, t_list *path);
void			release_antsi_do(size_t *ants_num, t_path_l *path_l,
t_list **ants);
void			print_ants(t_list *ants);
void			move_ants(t_list **ans, int end);
void			release_antsi_pr_end(t_list *ants, int end);
void			lem_del_paths(t_path_agr **paths);
void			lem_del_rlist(t_rlist *adj);
void			lem_del_rooms(t_room ***graph, size_t s);

#endif
