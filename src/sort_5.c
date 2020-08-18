/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <eesaki@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 15:20:58 by eesaki            #+#    #+#             */
/*   Updated: 2020/08/18 21:29:21 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			*create_sorted_array_of_stack_a(t_ps *ps)
{
	int		*a_array;
	int		i;
	t_elm	*a_elm;

	if (!(a_array = ft_memalloc(sizeof(int) * 5)))
		error("failed to allocate \"a_array\" in sort_5()\n");
	i = 0;
	a_elm = ps->a->head;
	while (i < 5)
	{
		a_array[i] = a_elm->n;
		a_elm = a_elm->next;
		i++;
	}
	quicksort(a_array, 5);
	return (a_array);
}

void		pb_largest_two_elms(t_ps *ps)
{
	int		*a_array;
	int		i;
	t_elm	*a_elm;

	a_array = create_sorted_array_of_stack_a(ps);
	i = 4;
	a_elm = ps->a->head;
	while (ps->a->size > 3)
	{
		while (a_elm->n != a_array[i])
			a_elm = a_elm->next;
		rotate_til_at_top(ps, ps->a, a_elm);
		perform_op_ntimes(ps, PB, 1);
		a_elm = ps->a->head;
		i = 3;
	}
	free(a_array);
}

void		sort_5(t_ps *ps)
{
	pb_largest_two_elms(ps);
	sort_3(ps, ps->a);
	while (ps->b->size > 0)
	{
		if (ps->b->size == 2 && ps->b->head->n > ps->b->head->next->n)
			perform_op_ntimes(ps, SB, 1);
		perform_op_ntimes(ps, PA, 1);
		rotate_til_at_top(ps, ps->a, find_min(ps->a));
	}
}
