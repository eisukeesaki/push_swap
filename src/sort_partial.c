/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_partial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 20:02:12 by eesaki            #+#    #+#             */
/*   Updated: 2020/08/15 10:34:00 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bring_unsorted_to_top(t_ps *ps, int unsorted_ct)
{
	int		i;
	int		rra_ct;
	t_elm	*a_t;

	i = 0;
	rra_ct = 0;
	a_t = ps->a->tail;
	if (!a_t->sorted)
	{
		while (i++ < unsorted_ct)
		{
			if (!a_t->sorted)
				rra_ct++;
			a_t = a_t->prev;
		}
		perform_op_ntimes(ps, RRA, rra_ct);
	}
	// while (!ps->a->tail->sorted || !ps->a->tail->prev->sorted ||
	// 	!ps->a->tail->prev->prev->sorted)
}

void	mark_as_sorted(t_stack *stack)
{
	int		i;
	t_elm	*head;

	i = 0;
	head = stack->head;
	while (i++ < stack->size)
	{
		if (head->sorted == FALSE)
			head->sorted = TRUE;
		head = head->next;
	}
}

void	sort_2_or_3(t_ps *ps)
{
	if (ps->a->head->next->next->sorted == TRUE)
	{
		perform_op_ntimes(ps, SA, 1);
		return ;
	}
	sort_3(ps, ps->a);
}

void	sort_partial(t_stack *a, t_ps *ps) // todo: must sort unsorted elms regardless of the position
{
	t_elm	*min;
	int		i;
	t_elm	*elm;
	int		unsorted_ct;

	min = find_min(a);
	unsorted_ct = count_unsorted(a);
	// printf("unsorted_ct: %d\n", unsorted_ct);  // debug purpose
	if (is_sorted_circularly(a, min) == FALSE)
	{
		bring_unsorted_to_top(ps, unsorted_ct);
		if (unsorted_ct == 2)
			perform_op_ntimes(ps, SA, 1);
		else if (unsorted_ct == 3)
			sort_top_3(ps);
		else
			error("something went wrong in sort_partial()\n");
	}
	else
	{
		if (a->size == 2 && a->head->n > a->head->next->n)
			perform_op_ntimes(ps, SA, 1);
		else
		{
			rotate_til_at_top(ps, a, min);
			i = 0;
			elm = a->head;
		}
	}
	mark_as_sorted(a);
	if (confirm_sort_partial(a) == FALSE)  // debug purpose
		error("sort_partial() has failed\n");
}

// void	handle_msl(t_ps *ps)
// {
// 	perform_op_ntimes(ps, SA, 1);
// }

// void	handle_mls(t_ps *ps)
// {
// 	perform_op_ntimes(ps, RRA, 1);
// }

// void	handle_lsm(t_ps *ps)
// {
// 	perform_op_ntimes(ps, RA, 1);
// }

// void	handle_lms(t_ps *ps)
// {
// 	perform_op_ntimes(ps, SA, 1);
// 	perform_op_ntimes(ps, RRA, 1);
// }

// void	handle_slm(t_ps *ps)
// {
// 	perform_op_ntimes(ps, SA, 1);
// 	perform_op_ntimes(ps, RA, 1);
// }

// void	func_to_sort_stack_of_3(t_ps *ps)
// {
// 	// int		top;
// 	// int		med;
// 	// int		btm;

// 	// top = ps->a->head->n;
// 	// med = ps->a->head->next->n;
// 	// btm = ps->a->head->next->next->n;
// 	// if (top < med && med > btm && top < btm)
// 	// 	// handle_slm(ps);
// 	// {
// 	// 	perform_op_ntimes(ps, SA, 1);
// 	// 	perform_op_ntimes(ps, RA, 1);
// 	// }
// 	// else if (top > med && med < btm && top < btm)
// 	// 	perform_op_ntimes(ps, SA, 1);
// 	// 	// handle_msl(ps);
// 	// else if (top < med && med > btm && top > btm)
// 	// 	perform_op_ntimes(ps, RRA, 1);
// 	// 	// handle_mls(ps);
// 	// else if (top > med && med < btm && top > btm)
// 	// 	perform_op_ntimes(ps, RA, 1);
// 	// 	// handle_lsm(ps);
// 	// else if (top > med && med > btm && top > btm)
// 	// {
// 	// 	perform_op_ntimes(ps, SA, 1);
// 	// 	perform_op_ntimes(ps, RRA, 1);
// 	// }
// 	// 	// handle_lms(ps);
// 	// else
// 	// 	printf("something went wrong in sort_2_or_3()\n");  // debug purpose
// }