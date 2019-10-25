/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avlt.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 19:37:16 by gbrandon          #+#    #+#             */
/*   Updated: 2019/10/23 19:34:00 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVLT_H
# define AVLT_H
# include <unistd.h>

typedef struct	s_avlt
{
	int					height;
	struct s_avlt		*left;
	struct s_avlt		*right;
	void				*item;
}				t_avlt;

t_avlt			*create_node(void *tr, void *(*ins)(void *));
void			add_node(t_avlt **tr, void *node, int (*cmp)(void *, void *),\
void *(*ins)(void *));
int				height(t_avlt *tr);
void			set_height(t_avlt *tr);
void			pre_order(t_avlt *tr, void (*appt)(void *));
void			in_order(t_avlt *tr, void (*appt)(void *));
void			post_order(t_avlt *tr, void (*appt)(void *));
void			pre_order_gfz(t_avlt *tr, void (*appt)(void *), int a);
void			gfz_write_init(int a);
void			gfz_write_end(int a);
int				balancef(t_avlt *tr);
void			balance(t_avlt **tr);
t_avlt			*rotater(t_avlt *tr);
t_avlt			*rotatel(t_avlt *tr);
void			remove_n(t_avlt **tr, void *node, int (*cmp)(void *, void *),
void (*del)(void *));

#endif
