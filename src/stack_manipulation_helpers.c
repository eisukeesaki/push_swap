/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manipulation_helpers.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 04:33:19 by eesaki            #+#    #+#             */
/*   Updated: 2020/07/28 05:34:01 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t		get_array_size_of_seg(t_stack *stack, int seg)
{
	int		i;
	int		size;
	t_elm	*head;

	i = 0;
	size = 0;
	head = stack->head;
	while (i++ < stack->size)
	{
		if (stack->head->seg == seg)
			size++;
		head = head->next;
	}
	return (size);
}

int			*create_array_of_seg(t_stack *stack, int seg, int *arr_size)
{
	int		*array;
	t_elm	*elm;

	elm = stack->head;
	if (!(array = ft_memalloc(sizeof(get_array_size_of_seg(stack, seg)))))
		ERROR("failed to allocate array in create_array_of_seg()");
	while (*arr_size < stack->size)
	{
		if (elm->seg == seg)
			array[*arr_size] = elm->n; /* increment i here? */
		elm = elm->next;
		(*arr_size)++;
	}
	return (array);
}
