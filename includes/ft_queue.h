/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 14:52:28 by gbrandon          #+#    #+#             */
/*   Updated: 2019/11/08 07:24:11 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_QUEUE_H
# define FT_QUEUE_H

typedef struct	s_fque
{
	void			*item;
	struct s_fque	*next;
}				t_fque;

void			add_qnode(t_fque **head, t_fque **tail, void *it,
void *(*inp)(void *));
void			del_qnode(t_fque **head);
void			free_qnode(t_fque **head);
void			print_qnode(t_fque *head, void (*f)(void *));

#endif
