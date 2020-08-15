/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manipulation_helpers.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 04:33:19 by eesaki            #+#    #+#             */
/*   Updated: 2020/08/15 19:57:37 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		select_3_largest(int *b_arr, size_t *b_arr_size)
{
	rev_quicksort(b_arr, *b_arr_size);
	(*b_arr_size)--;
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
	int		i;
	int		size;
	t_elm	*head;

	i = 0;
	size = 0;
	head = stack->head;
	while (i++ < stack->size)
	{
		if (head->seg == seg)
			size++;
		head = head->next;
	}
	return (size);
}

int			*create_array_of_seg(t_stack *stack, int seg, size_t *arr_size)
{
	int		*array;
	t_elm	*elm;
	int		i;
	int		k;

	elm = stack->head;
	*arr_size = get_array_size_of_seg(stack, seg);
	if (!(array = ft_memalloc(sizeof(int) * *arr_size)))
		ERROR("failed to allocate \"array\" in create_array_of_seg()\n");
	i = 0;
	k = 0;
	while (i < stack->size)
	{
		if (elm->seg == seg)
			array[k++] = elm->n;
		elm = elm->next;
		i++;
	}
	return (array);
}
