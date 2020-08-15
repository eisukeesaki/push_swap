/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_median_in_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 18:06:33 by eesaki            #+#    #+#             */
/*   Updated: 2020/08/15 19:58:49 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t		get_array_size_of_unsorted(t_stack *stack)
{
	int		i;
	size_t	size;
	t_elm	*head;

	i = 0;
	size = 0;
	head = stack->head;
	while (i < stack->size)
	{
		if (head->sorted == FALSE)
			size++;
		head = head->next;
		i++;
	}
	return (size);
}

int			*create_array_of_unsorted(t_stack *stack, size_t *size)
{
	int		*array;
	t_elm	*elm;
	int		i;
	int		k;

	elm = stack->head;
	i = 0;
	k = 0;
	*size = get_array_size_of_unsorted(stack);
	if (!(array = ft_memalloc(*size * sizeof(int))))
		ERROR("failed to allocate \"array\" in create_array_unsorted()\n");
	while (i < stack->size)
	{
		if (elm->sorted == FALSE)
			array[k++] = elm->n;
		elm = elm->next;
		i++;
	}
	return (array);
}

int			get_median_in_a(t_stack *stack)
{
	int		*arr;
	size_t	size;
	int		median;

	size = 0;
	arr = create_array_of_unsorted(stack, &size);
	quicksort(arr, (int)size);
	median = size % 2 == 0 ? arr[(size / 2) - 1] : arr[size / 2];
	free(arr);
	return (median);
}
