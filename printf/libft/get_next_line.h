/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 14:26:53 by gbrandon          #+#    #+#             */
/*   Updated: 2019/10/28 15:47:46 by fdaryn-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft.h"

# define BUFF_SIZE 30
# define CHECK_ERR(x) if (!(x)) return (-1)
# define CHECK_CMP_ERR(x) if ((x)) return (-1)
# define IF_RET_ONE(x) if ((x)) return (1)
# define FREE_X(x) if ((x)){free((x)); (x) = NULL;}
# define START_INIT(x,y,z) CHECK_CMP_ERR(x<0);CHECK_ERR(y);*line=NULL;z=0;

typedef struct			s_info
{
	int			fd;
	char		*line;
}						t_info;

int						get_next_line(const int fd, char **line);

#endif
