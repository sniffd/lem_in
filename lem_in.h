#ifndef LEM_IN_LEM_IN_H
# define LEM_IN_LEM_IN_H
# include "libft.h"
# include "avlt.h"

struct	s_rlist
{
	struct	s_rlist	*first;
	struct	s_rlist	*last;
	struct	s_rlist	*current;
	struct	s_rlist	*next;
};

typedef struct	s_room
{
	char			*name;
	struct	s_rlist	*lst;
}				t_room;

#endif
