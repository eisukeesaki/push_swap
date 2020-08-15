/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 15:20:58 by eesaki            #+#    #+#             */
/*   Updated: 2020/08/14 18:55:46 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_5(t_ps *ps)
{
	t_elm	*a_h;
	int		*a_arr;
	int		i;

	if (!(a_arr = ft_memalloc(sizeof(int) * 5)))
		error("failed to allocate a_arr in sort_5()");
	i = 0;
	a_h = ps->a->head;
	while (i < 5)
	{
		a_arr[i++] = a_h->n;
		a_h = a_h->next;
	}
	quicksort(a_arr, 5);
	a_h = ps->a->head;
	i = 4;
	while (ps->a->size > 3)
	{
		while (a_h->n != a_arr[i])
			a_h = a_h->next;
		rotate_til_at_top(ps, ps->a, a_h);
		perform_op_ntimes(ps, PB, 1);
		a_h = ps->a->head;
		i = 3;
	}
	sort_3(ps, ps->a);
	while (ps->b->size > 0)
	{
		if (ps->b->size > 1 && ps->b->head->n > ps->b->head->next->n)
			perform_op_ntimes(ps, SB, 1);
		perform_op_ntimes(ps, PA, 1);
		rotate_til_at_top(ps, ps->a, find_min(ps->a));
	}
	free(a_arr);
}
