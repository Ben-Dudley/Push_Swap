/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdudley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 21:06:39 by bdudley           #+#    #+#             */
/*   Updated: 2019/03/02 18:41:05 by bdudley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

static void	ft_delete(t_list **my_list, t_list **copy)
{
	t_list *tmp;

	tmp = *my_list;
	if (*my_list == *copy)
	{
		*my_list = (*my_list)->next;
		free(tmp);
		tmp = NULL;
		return ;
	}
	while (tmp->next != *copy)
		tmp = tmp->next;
	tmp->next = (*copy)->next;
	free(*copy);
	*copy = NULL;
}

static int	get_line(char ***line, void **str, char c)
{
	char *str_copy;

	str_copy = NULL;
	**line = (ft_strcmp((char *)(*str), "")) ?
		ft_strsub((char const *)(*str), 0,
		ft_strchr((const char*)(*str), c) - (char *)(*str)) : NULL;
	if (c == '\n')
		if (!(str_copy = ft_strdup(ft_strchr((const char *)(*str), c) + 1)))
			return (-1);
	ft_memdel(&(*str));
	*str = (void*)str_copy;
	if (**line != NULL)
		return (1);
	return (0);
}

static int	read_line(int fd, void **str, char ***line)
{
	char	*str_copy;
	char	buf[BUFF_SIZE + 1];
	int		result;

	if (ft_strchr((const char*)(*str), '\n') != NULL)
		return (get_line(&(*line), &(*str), '\n'));
	while ((result = read(fd, buf, BUFF_SIZE)))
	{
		if (result == -1)
			return (-1);
		buf[result] = '\0';
		if (!(str_copy = ft_strjoin((char const *)(*str), (char const *)buf)))
			return (-1);
		free((*str));
		(*str) = (void *)str_copy;
		if (ft_strchr((const char*)(*str), '\n') != NULL)
			return (get_line(&(*line), &(*str), '\n'));
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static t_list	*my_list = NULL;
	t_list			*copy;
	int				result;
	char			buf[1];

	if (fd < 0 || line == NULL || BUFF_SIZE < 1 || read(fd, &buf, 0) < 0)
		return (-1);
	*line = NULL;
	copy = my_list;
	while (copy != NULL && copy->content_size != (size_t)fd)
		copy = copy->next;
	if (copy == NULL)
	{
		ft_lstadd(&my_list, ft_lstnew("", fd));
		copy = my_list;
	}
	if ((result = read_line(fd, &copy->content, &line)))
		return (result);
	if (ft_strchr((const char*)copy->content, '\0') != NULL)
	{
		result = get_line(&line, &(copy->content), '\0');
		ft_delete(&my_list, &copy);
		return (result);
	}
	return (-1);
}
