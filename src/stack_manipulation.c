/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manipulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 04:00:58 by eesaki            #+#    #+#             */
/*   Updated: 2020/08/03 06:34:46 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		assign_seg_id(t_stack *b, int seg_id, int push_ct)
{
	int		i;
	t_elm	*b_elm;

	i = 0;
	b_elm = b->head;
	while (i++ < push_ct)
	{
		b_elm->seg = seg_id;
		b_elm = b_elm->next;
	}
}

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

void	pa_all_in_list(t_ps *ps, int *pa_list, int b_arr_size)
{
	int		mid;
	int		idx;
	int		i;
	int		k;
	t_stack	*b;

	mid = ps->b->size / 2;
	idx = 0;
	i = 0;
	b = ps->b;
	while (i < b_arr_size)
	{
		k = 0;
		while (k++ < ps->b->size && b->head->n != pa_list[i++])
		{
			idx++;
			b->head = b->head->next;
		}
		if (idx <= mid)
			perform_op_ntimes(ps, RB, idx);
		else
			perform_op_ntimes(ps, RRB, ps->b->size - idx);
		perform_op_ntimes(ps, PA, 1);
		b = ps->b;
	}
}

void	get_pa_list_and_pa(t_ps *ps, int top_seg)
{
	int		median;
	int		*b_arr;
	size_t	b_arr_size;
	size_t	i;
	int		k;

	b_arr_size = 0;
	b_arr = create_array_of_seg(ps->b, top_seg, &b_arr_size);
	while (b_arr_size > 3)
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

void	process_b(t_ps *ps)
{
	int		top_seg;

	top_seg = get_top_seg(ps->b);
	get_pa_list_and_pa(ps, top_seg);
}

void	pb_smaller(t_ps *ps, t_stack *pb_list)
{
	int		mid;
	int		idx;
	int		i;
	t_elm	*elm;
	int		curr_seg;

	mid = ps->a->size / 2;
	idx = 0;
	i = 0;
	elm = ps->a->head;
	curr_seg = ps->b->head != NULL ? ps->b->head->seg : 0;
	while (i++ < pb_list->size)
	{
		while (elm->n != pb_list->head->n)
		{
			idx++;
			elm = elm->next;
		}
		if (idx <= mid)
			perform_op_ntimes(ps, RA, idx);
		else
			perform_op_ntimes(ps, RRA, ps->a->size - idx);
		perform_op_ntimes(ps, PB, 1);
		pb_list->head = pb_list->head->next;
		elm = ps->a->head;
		idx = 0;
	}
	assign_seg_id(ps->b, curr_seg + 1, pb_list->size);
	free_elms(pb_list);
}
