/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_elms_gtet_median.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <eesaki@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 04:00:58 by eesaki            #+#    #+#             */
/*   Updated: 2020/08/18 21:23:40 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		rotate_til_at_top(t_ps *ps, t_stack *stack, t_elm *dest)
{
	int		r_count;
	int		rr_count;

	r_count = get_rotation_count(stack, dest, FALSE);
	rr_count = get_rotation_count(stack, dest, TRUE);
	if (r_count < rr_count)
		perform_op_ntimes(ps, (stack == ps->a) ? RA : RB, r_count);
	else
		perform_op_ntimes(ps, (stack == ps->a) ? RRA : RRB, rr_count);
}

void		pa_all_in_list(t_ps *ps, int *pa_list, int b_arr_size)
{
	int		idx;
	int		i;
	int		k;
	int		m;
	t_elm	*b_elm;

	i = 0;
	m = 0;
	while (i++ < b_arr_size)
	{
		k = 0;
		idx = 0;
		b_elm = ps->b->head;
		while (k++ < ps->b->size && b_elm->n != pa_list[m])
		{
			idx++;
			b_elm = b_elm->next;
		}
		if (idx <= ps->b->size / 2)
			perform_op_ntimes(ps, RB, idx);
		else
			perform_op_ntimes(ps, RRB, ps->b->size - idx);
		perform_op_ntimes(ps, PA, 1);
		m++;
	}
}

void		get_pa_list_and_pa(t_ps *ps, int top_seg)
{
	int		*b_arr;
	size_t	b_arr_size;
	int		median;
	size_t	i;
	int		k;

	b_arr_size = 0;
	b_arr = create_array_of_seg(ps->b, top_seg, &b_arr_size);
	if (b_arr_size > 3)
	{
		median = get_median_in_array(b_arr, b_arr_size);
		i = 0;
		k = 0;
		while (i < b_arr_size)
		{
			if (b_arr[i] >= median)
				b_arr[k++] = b_arr[i];
			i++;
		}
		b_arr_size = k;
	}
	pa_all_in_list(ps, b_arr, b_arr_size);
	delete_seg_id(ps->a, b_arr_size);
	free(b_arr);
}

void		pa_elms_gtet_median(t_ps *ps)
{
	int		top_seg;

	top_seg = get_top_seg(ps->b);
	get_pa_list_and_pa(ps, top_seg);
}
