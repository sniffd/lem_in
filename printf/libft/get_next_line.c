/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 13:45:41 by gbrandon          #+#    #+#             */
/*   Updated: 2019/10/28 15:47:46 by fdaryn-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

static void		del_item(t_list **head, int fd)
{
	t_list		*h;
	t_list		*prev;

	prev = *head;
	h = *head;
	while (h)
	{
		if (((t_info*)(h)->content)->fd == fd)
		{
			FREE_X(((t_info*)h->content)->line);
			FREE_X(h->content);
			if (h == prev)
			{
				prev = h->next;
				*head = prev;
			}
			else
				prev->next = h->next;
			free(h);
			return ;
		}
		prev = h;
		h = h->next;
	}
}

static t_info	*get_fd(t_list **head, int fd)
{
	t_info		*new;
	t_list		*new_head;

	new_head = *head;
	while (new_head)
	{
		if (((t_info*)new_head->content)->fd == fd)
			return (new_head->content);
		new_head = new_head->next;
	}
	if (!(new = (t_info*)malloc(sizeof(t_info))))
		return (NULL);
	new->fd = fd;
	new->line = NULL;
	if (!(new_head = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!(new_head->content = new))
	{
		free(new_head);
		return (NULL);
	}
	new_head->next = NULL;
	ft_lstadd(head, new_head);
	return (new_head->content);
}

static int		assembly_line(char **hli, char **buf, char **line, size_t len)
{
	char		*temp;
	char		*fr_temp;
	size_t		rest_len;

	CHECK_ERR(temp = ft_strsub(*hli, 0, *buf - *hli));
	if (*line)
	{
		fr_temp = *line;
		CHECK_ERR(*line = ft_strjoin(*line, temp));
		free(temp);
		free(fr_temp);
	}
	else
		*line = temp;
	if ((rest_len = len - (*buf - *hli)) > 1)
	{
		CHECK_ERR(*buf = ft_strsub(*buf, 1, rest_len));
	}
	else
		*buf = NULL;
	free(*hli);
	*hli = NULL;
	return (1);
}

static int		create_line(char **buf, char **line)
{
	char	*head_line;
	size_t	line_length;
	char	*temp;

	head_line = *buf;
	line_length = ft_strlen(head_line);
	while (**buf)
	{
		if (**buf == '\n')
		{
			CHECK_ERR(assembly_line(&head_line, buf, line, line_length));
			return (1);
		}
		(*buf)++;
	}
	if (*line)
	{
		temp = *line;
		CHECK_ERR(*line = ft_strjoin(*line, head_line));
		free(temp);
	}
	else
		CHECK_ERR(*line = ft_strdup(head_line));
	*buf = head_line;
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*buf = NULL;
	t_info			*cur_buf;
	int				rbytes;
	char			*head_buf;

	START_INIT(fd, line, rbytes);
	CHECK_ERR(cur_buf = get_fd(&buf, fd));
	if (cur_buf->line)
		CHECK_CMP_ERR((rbytes = create_line(&(cur_buf->line), line)) < 0);
	IF_RET_ONE(rbytes == 1);
	FREE_X(cur_buf->line);
	CHECK_ERR(cur_buf->line = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1)));
	head_buf = cur_buf->line;
	while ((rbytes = read(fd, cur_buf->line, BUFF_SIZE)) > 0)
	{
		cur_buf->line[rbytes] = '\0';
		CHECK_CMP_ERR((rbytes = create_line(&(cur_buf->line), line)) < 0);
		IF_RET_ONE(rbytes == 1);
		cur_buf->line = head_buf;
	}
	CHECK_CMP_ERR(rbytes < 0);
	del_item(&buf, fd);
	IF_RET_ONE(*line);
	return (0);
}
