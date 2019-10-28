/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 14:50:49 by gbrandon          #+#    #+#             */
/*   Updated: 2019/10/28 13:01:42 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ft_queue.h"

void			print_qnode(t_fque *head, void (*f)(void *))
{
	while (head)
	{
		f(head->item);
		head = head->next;
	}
}

void			free_qnode(t_fque **head)
{
	t_fque	*temp;

	while (*head)
	{
		temp = (*head)->next;
		free(head);
		*head = temp;
	}
}

static t_fque	*new_qnode(void *it, void *(*inp)(void *))
{
	t_fque	*new_n;

	if (!(new_n = (t_fque*)malloc(sizeof(t_fque))))
		exit(-1);
	new_n->item = inp(it);
	new_n->next = NULL;
	return (new_n);
}

void			add_qnode(t_fque **head, t_fque **tail, void *it,
void *(*inp)(void *))
{
	t_fque *new_n;

	new_n = new_qnode(it, inp);
	if (*head)
	{
		(*tail)->next = new_n;
		*tail = new_n;
	}
	else
	{
		*head = new_n;
		*tail = new_n;
	}
}

void			del_qnode(t_fque **head)
{
	t_fque		*temp;

	if (*head)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
	}
}
