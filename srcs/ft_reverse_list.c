/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:26:56 by gbrandon          #+#    #+#             */
/*   Updated: 2019/11/06 14:35:14 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_rev_lst(t_list *lst)
{
	t_list	*temp;
	t_list	*a;
	t_list	*ah;

	ah = NULL;
	while (lst)
	{
		temp = lst->next;
		a = lst;
		a->next = ah;
		ah = a;
		lst = temp;
	}
	return (ah);
}
