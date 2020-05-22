/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 14:24:56 by eesaki            #+#    #+#             */
/*   Updated: 2020/05/23 04:57:50 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"
#include <fcntl.h> // debug purpose
#include <sys/errno.h> // debug purpose

void	vali_result(t_ps *ps)
{
	if (ps->b->head != NULL)
		ERROR("stack_b is not empty. exiting.");
	if (ps->a->head)
	{
		while (ps->a->head->next != ps->a->tail)
		{
			if (ps->a->head->n > ps->a->head->next->n)
				ERROR("stack_a is not sorted in ascending order. exiting.");
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
	{
		if (DBG) printf("calling pa...\n"); setbuf(stdout, NULL);
		push(ps->b, ps->a);
	}
	if (!strcmp(op, "pb"))
	{
		if (DBG) printf("calling pb...\n"); setbuf(stdout, NULL);
		push(ps->a, ps->b);
	}
	if (!strcmp(op, "sa") || !strcmp(op, "ss"))
		swap(ps->a);
	if (!strcmp(op, "sb") || !strcmp(op, "ss"))
		swap(ps->b);
}

int		main(int ac, char **av)
{
	t_ps		*ps;
	char		*line;
	int			fd; // debug purpose
	
	if (ac < 2)
		return (0);
	ps = get_ps(av + 1);
	if (DBG) print_stacks(ps, "init");
	if ((fd = open("op_list.txt", O_RDONLY)) == -1) // debug purpose
		printf("file open error:%s\n", strerror(errno));
	else
		if (DBG) printf("\nfd of op_list.txt is:%d\n", fd);
	// while (get_next_line(0, &line))
	while (get_next_line(fd, &line)) // debug purpose
		dispatch_op_checker(line, ps);
	if (DBG) {write(1, "\n", 1); print_stacks(ps, "after op"); write(1, "\n", 1);}
	vali_result(ps);
	return (0);
}