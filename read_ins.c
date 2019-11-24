/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_ins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 15:17:05 by eesaki            #+#    #+#             */
/*   Updated: 2019/11/23 22:35:53 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "push_swap.h"
#include <stdio.h> // debug purpose

int		get_line(char **str, char **line)
{
	char	*nl;
	char	*tmp;

	while ((nl = ft_strchr(*str, '\n')))
	{
		*line = ft_strndup(*str, (nl - *str));
		tmp = ft_strdup(nl + 1);
		free(*str);
		*str = tmp;
		return (1);
	}
	if (**str)
	{
		*line = ft_strdup(*str);
		ft_bzero(*str, ft_strlen(*str));
		return (1);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	char		buff[BUFF_SIZE + 1];
	static char	*s[FD_MAX];
	char		*tmp;
	int			rc;

	if (fd < 0 || !line || BUFF_SIZE <= 0)
		return (-1);
	while ((rc = read(fd, buff, BUFF_SIZE)) != 0)
	{
		buff[rc] = '\0';
		if (!s[fd])
			s[fd] = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(s[fd], buff);
			free(s[fd]);
			s[fd] = tmp;
		}
	}
	if (rc < 1 && s[fd] == NULL)
		return (rc);
	if (ft_strlen(s[fd]) > 0)
		return (get_line(&s[fd], line));
	return (0);
}

void	link_node_tail(t_ins_set *head, t_ins_set *new)
{
	while (head->next != NULL)
		head = head->next;
	head->next = new;
}

t_ins_set	*newnode(char *s)
{
	t_ins_set	*node;

	node = (t_ins_set *)ft_memalloc(sizeof(t_ins_set));
	node->ins = s;
	node->next = NULL;
	return (node);
}

t_ins_set	*read_ins(void)
{
	char		*line;
	t_ins_set	*head;
	t_ins_set	*tmp;
	// int		fd = 0; // test purpose

	line = NULL;
	head = NULL;
	// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< reading ins from file instead of stdin to allow debugging
	// if ((fd = open("unused/instructions.txt", O_RDONLY)) == 1)
	// {
	// 	printf("file open error\n");
	// 	exit(1);
	// }
	// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> reading ins from file instead of stdin to allow debugging
	while (get_next_line(1, &line))
	// while (get_next_line(fd, &line))
	{
		vali_ins(line);
		tmp = newnode(line);
		if (head == NULL)
			head = tmp;
		else
			link_node_tail(head, tmp);
		// free(line);
	}
	return (head);
}
