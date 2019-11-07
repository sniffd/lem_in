#ifndef LEM_IN_LEM_IN_H
# define LEM_IN_LEM_IN_H
# include "libft.h"
# include "get_next_line.h"
# include "avlt.h"

typedef struct	s_rlist
{
	int				id;
	int				flow;
	int				cap;
	void			*twin;
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
	int				is_in_path;
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
	char			is_ed_del;
	t_room			*par;
	int				cur;
	size_t			i;
	t_list			*path;
}				t_ek_info;

typedef struct	s_sinfo
{
	int		start;
	int		end;
	t_room	**graph;
	int		lems;
	size_t	size;
}				t_sinfo;

t_room			*init_room(int id, char *name, int x, int y);
t_rlist			*init_rlist(int id);
t_path_agr		*init_path_agr(int l, int n, int k);
t_ek_info		*init_ek_info(t_room **graph, int end, int cntr);
void			*ins(void *ins);
t_sinfo			*parse_lem(void);
int				cmp(void *p1, void *p2);
void			*q_input(void *it);
int				ft_bfs(t_sinfo *rooms);
t_path_agr		*edm_karp_alg(t_sinfo *rooms, int *e);
void			ek_alg_mk_twin(t_room *room, int start);
t_list			*ek_alg_mk_path(t_room *parent,  t_list *lst, t_sinfo *rooms);
t_path_l		*ek_alg_mk_path_l(t_path_l *path_l, t_list *path, size_t length);
t_path_agr		*ek_alg_mk_pagr(t_path_agr *pagr, t_ek_info *box);
void			del_lst(void *it, size_t s);
int				release_antsi(t_path_agr *paths, int end, int *stra_num);
t_room			*get_room(t_avlt *tr, char *name);
t_room			*get_room_id(t_avlt *tr, int id);
t_list			*init_ant(size_t id, t_list *path);
void			release_antsi_do(size_t *ants_num, t_path_l *path_l,
t_list **ants);
void			print_ants(t_list *ants, int *str_num);
void			move_ants(t_list **ans, int end);
void			release_antsi_pr_end(t_list *ants, int end, int *stra_num);
void			lem_del_paths(t_path_agr **paths);
void			lem_del_rlist(t_rlist *adj);
void			lem_del_rooms(t_room ***graph, size_t s);
void			lem_del_tree(t_avlt **tr);
t_room			**ft_lem_trrtoarr(t_avlt *tr, size_t s);
void			ek_alg_neg_e(t_room *cur, t_room *par, int start);
t_rlist  		*find_adj(t_room *cur, int id);
int				ek_alg_del_edg(t_room **graph, t_ek_info *box);
void			ft_bfs_clear_all(t_sinfo *room);
void			find_del_adj(t_room *cur, int id);
int				edm_karp_edgew(t_sinfo *rooms, t_ek_info *box);
void			ft_lem_log(char *mes, int lvl, int clr, char imp);
void			ft_lemi_log(int lvl, int clr, t_path_l *path_l);
void			print_paths(t_path_agr *paths);
void			print_lems(int str_num);


#endif
