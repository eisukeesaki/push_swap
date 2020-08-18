/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <eesaki@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 17:28:19 by eesaki            #+#    #+#             */
/*   Updated: 2020/08/18 21:28:15 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		pb_elms_ltet_median(t_ps *ps, t_stack *pb_list)
{
	int		idx;
	int		i;
	t_elm	*a_elm;

	idx = 0;
	i = 0;
	a_elm = ps->a->head;
	while (i++ < pb_list->size)
	{
		while (a_elm->n != pb_list->head->n)
		{
			idx++;
			a_elm = a_elm->next;
		}
		if (idx <= ps->a->size / 2)
			perform_op_ntimes(ps, RA, idx);
		else
			perform_op_ntimes(ps, RRA, ps->a->size - idx);
		perform_op_ntimes(ps, PB, 1);
		pb_list->head = pb_list->head->next;
		a_elm = ps->a->head;
		idx = 0;
	}
	assign_seg_id(ps->b, get_top_seg(ps->b) + 1, pb_list->size);
	free_elms(pb_list);
}

void		create_pb_list(t_stack *a, t_stack *pb_list)
{
	int		median;
	int		i;
	t_elm	*a_elm;

	i = 0;
	a_elm = a->head;
	median = get_median_in_a(a);
	while (i < a->size)
	{
		if (a_elm->n <= median && a_elm->sorted == FALSE)
			append_node(pb_list, create_node(a_elm->n));
		a_elm = a_elm->next;
		i++;
	}
}

void		sort(t_ps *ps)
{
	t_stack	*pb_list;

	if (!(pb_list = (t_stack *)ft_memalloc(sizeof(t_stack))))
		error("failed to allocate \"pb_list\" in sort()\n");
	while (1)
	{
		while (count_unsorted(ps->a) > 3)
		{
			create_pb_list(ps->a, pb_list);
			pb_elms_ltet_median(ps, pb_list);
		}
		sort_remaining_unsorteds_in_a(ps->a, ps);
		if (ps->b->size > 0)
			pa_elms_gtet_median(ps);
		else
			break ;
	}
	free(pb_list);
}
