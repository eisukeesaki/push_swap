/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <eesaki@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 14:24:56 by eesaki            #+#    #+#             */
/*   Updated: 2020/08/18 22:07:00 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_get_next_line.h"

void	validate_result(t_ps *ps)
{
	if (ps->b->head != NULL)
		error("stack_b is not empty. exiting.\n");
	if (ps->a->head)
	{
		while (ps->a->head->next != ps->a->tail)
		{
			if (ps->a->head->n > ps->a->head->next->n)
				error("stack_a is not sorted in ascending order. exiting.\n");
			ps->a->head = ps->a->head->next;
		}
	}
	write(1, "OK\n", 3);
}

void	dispatch_op_checker(char *op, t_ps *ps)
{
	if (strcmp(op, "ra") == FALSE || strcmp(op, "rr") == FALSE)
		rotate_up(ps->a);
	if (strcmp(op, "rb") == FALSE || strcmp(op, "rr") == FALSE)
		rotate_up(ps->b);
	if (strcmp(op, "rra") == FALSE || strcmp(op, "rrr") == FALSE)
		rotate_down(ps->a);
	if (strcmp(op, "rrb") == FALSE || strcmp(op, "rrr") == FALSE)
		rotate_down(ps->b);
	if (strcmp(op, "pa") == FALSE)
		push(ps->b, ps->a);
	if (strcmp(op, "pb") == FALSE)
		push(ps->a, ps->b);
	if (strcmp(op, "sa") == FALSE || strcmp(op, "ss") == FALSE)
		swap(ps->a);
	if (strcmp(op, "sb") == FALSE || strcmp(op, "ss") == FALSE)
		swap(ps->b);
}

int		main(int ac, char **av)
{
	t_ps		*ps;
	char		*line;
	int			fd;

	if (ac < 2)
		return (0);
	ps = get_ps(av + 1);
	fd = 0;
	while (ft_get_next_line(fd, &line))
	{
		dispatch_op_checker(line, ps);
		free(line);
		line = NULL;
	}
	validate_result(ps);
	return (0);
}
