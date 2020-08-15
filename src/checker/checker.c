/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 14:24:56 by eesaki            #+#    #+#             */
/*   Updated: 2020/08/15 19:58:07 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"
#include <fcntl.h> // debug purpose
#include <sys/errno.h> // debug purpose

void	vali_result(t_ps *ps)
{
	if (ps->b->head != NULL)
		ERROR("stack_b is not empty. exiting.\n");
	if (ps->a->head)
	{
		while (ps->a->head->next != ps->a->tail)
		{
			if (ps->a->head->n > ps->a->head->next->n)
				ERROR("stack_a is not sorted in ascending order. exiting.\n");
			ps->a->head = ps->a->head->next;
		}
	}
	write(1, "OK\n", 3);
}

void	dispatch_op_checker(char *op, t_ps *ps)
{
	if (!strcmp(op, "ra") || !strcmp(op, "rr"))
		rotate_up(ps->a);
	if (!strcmp(op, "rb") || !strcmp(op, "rr"))
		rotate_up(ps->b);
	if (!strcmp(op, "rra") || !strcmp(op, "rrr"))
		rotate_down(ps->a);
	if (!strcmp(op, "rrb") || !strcmp(op, "rrr"))
		rotate_down(ps->b);
	if (!strcmp(op, "pa"))
		push(ps->b, ps->a);
	if (!strcmp(op, "pb"))
		push(ps->a, ps->b);
	if (!strcmp(op, "sa") || !strcmp(op, "ss"))
		swap(ps->a);
	if (!strcmp(op, "sb") || !strcmp(op, "ss"))
		swap(ps->b);
}

int		main(int ac, char **av)
{
	t_ps		*ps;
	char		*line;
	int			fd = 0; // debug purpose
	
	if (ac < 2)
		return (0);
	ps = get_ps(av + 1);
	if (DBG) print_stacks(ps, "init");
	if (RDFILE) // debug purpose
	{
		if ((fd = open("op_list.txt", O_RDONLY)) == -1)
			printf("file open error:%s\n", strerror(errno));
	}
	if (DBG) printf("\nfd of op_list.txt is:%d\n", fd);
	while (get_next_line(fd, &line)) // hard-code fd as 0 in deploy build
	{
		dispatch_op_checker(line, ps);
		free(line);
		line = NULL;
	}
	if (DBG) {write(1, "\n", 1); print_stacks(ps, "after ops"); write(1, "\n", 1);}
	vali_result(ps);
	// system("leaks checker");
	return (0);
}