/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_elms_gtet_median_part2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <eesaki@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 04:33:19 by eesaki            #+#    #+#             */
/*   Updated: 2020/08/18 21:22:06 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		assign_seg_id(t_stack *b, int seg_id, int push_ct)
{
	int		i;
	t_elm	*b_elm;

	i = 0;
	b_elm = b->head;
	while (i < push_ct)
	{
		b_elm->seg = seg_id;
		b_elm = b_elm->next;
		i++;
	}
}

void		delete_seg_id(t_stack *a, int pushed_size)
{
	t_elm	*a_elm;
	int		i;

	a_elm = a->head;
	i = 0;
	while (i < pushed_size)
	{
		a_elm->seg = 0;
		a_elm = a_elm->next;
		i++;
	}
}

int			get_array_size_of_seg(t_stack *stack, int seg)
{
	int		size;
	int		i;
	t_elm	*elm;

	i = 0;
	size = 0;
	elm = stack->head;
	while (i < stack->size)
	{
		if (elm->seg == seg)
			size++;
		elm = elm->next;
		i++;
	}
	return (size);
}

int			*create_array_of_seg(t_stack *stack, int seg, size_t *arr_size)
{
	int		*array;
	int		i;
	int		k;
	t_elm	*elm;

	elm = stack->head;
	*arr_size = get_array_size_of_seg(stack, seg);
	if (!(array = ft_memalloc(sizeof(int) * *arr_size)))
		error("failed to allocate \"array\" in create_array_of_seg()\n");
	i = 0;
	k = 0;
	while (i < stack->size)
	{
		if (elm->seg == seg)
		{
			array[k] = elm->n;
			k++;
		}
		elm = elm->next;
		i++;
	}
	return (array);
}
