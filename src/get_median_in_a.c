/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_median_in_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 18:06:33 by eesaki            #+#    #+#             */
/*   Updated: 2020/07/28 04:38:04 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> // debug purpose

size_t		get_array_size_of_unsorted(t_stack *stack)
{
	int		i;
	int		size;
	t_elm	*head;

	i = 0;
	size = 0;
	head = stack->head;
	while (i++ < stack->size)
	{
		if (stack->head->sorted == FALSE)
			size++;
		head = head->next;
	}
	return (size);
}

int			*create_array_of_unsorted(t_stack *stack)
{
	int		*array;
	t_elm	*elm;
	int		i;

	elm = stack->head;
	i = 0;
	if (!(array = ft_memalloc(get_array_size_of_unsorted(stack) * sizeof(int))))
	// if (!(array = ft_memalloc(sizeof(get_array_size_of_unsorted(stack)))))
		ERROR("failed to allocate array in create_array_unsorted()");
	while (i < stack->size)
	{
		if (elm->sorted == FALSE)
			array[i] = elm->n; /* increment i here? */
		elm = elm->next;
		i++;
	}
	return (array);
}

int		get_median_in_a(t_stack *stack)
{
	int		*arr;
	int		median;

	arr = create_array_of_unsorted(stack);
	quicksort(arr, stack->size);
	median = arr[stack->size / 2];
	free(arr);
	return (median);
}

// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< testser
// int		main(void)
// {
// 	int		arr[] = {8, 1, 15, 4, 10, 11, 7, 9, 3, 6, 13, 12, 2, 5, 14};
// 	int		size = sizeof(arr) / sizeof(arr[0]);
// 	// quicksort(arr, size);
// 	quicksort(arr, 0, size - 1);
// 	int	i; for (i = 0; i < size; i++) printf("%d, ", arr[i]);
// 	return (0);
// }
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> testser

// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< backup
// void	quicksort(int *arr, int start, int end)
// {
// 	int		partition;

// 	if (start < end)
// 	{
// 		partition = get_partition(arr, start, end);
// 		quicksort(arr, start, partition - 1);
// 		quicksort(arr, partition + 1, end);
// 	}
// }
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> backup

// int		get_partition(int *arr, int start, int end)
// {
// 	int		pivot;
// 	int		i;
// 	int		partition;
// 	int		tmp;

// 	// pivot = arr[end / 2];
// 	pivot = arr[end];
// 	partition = start;
// 	i = start;
// 	while (i < end)
// 	{
// 		while (arr[i] <= pivot)
// 			i++;
// 		while (arr[partition] > pivot)
// 			partition--;
// 		if (i >= partition)
// 			break ;
// 		tmp = arr[i];
// 		arr[i] = arr[partition];
// 		arr[partition] = tmp;
// 		i++;
// 		partition--;
// 	}
// 	return (partition);
// }

// int		get_median_in_stack(t_stack *stack)
// {
// 	int		*arr;

// 	arr = create_array_of_stack(stack);
// 	quicksort(arr, stack->size);
// 	return (arr[stack->size / 2]);
// }

// int		get_median_b(t_stack *stack, int seg)
// {
// 	int		*arr;
// 	int		size;

// 	size = 0;
// 	arr = create_array_of_seg(stack, seg, &size);
// 	quicksort(arr, size);
// 	return (arr[stack->size / 2]);
// }

// int			*create_array_of_stack(t_stack *stack)
// {
// 	int		*array;
// 	int		i;
// 	t_elm	*head;

// 	i = 0;
// 	if (!(array = ft_memalloc(sizeof(stack->size))))
// 		ERROR("failed to allocate array in create_array_of_stack()");
// 	while (i < stack->size)
// 	{
// 		array[i] = stack->head->n; /* increment i here? */
// 		head = head->next;
// 		i++;
// 	}
// 	return (array);
// }

// int			*create_array(t_stack *stack) // might not use
// {
// 	int		*array;
// 	t_elm	*elm;
// 	int		i;

// 	elm = stack->head;
// 	i = 0;
// 	if (!(array = ft_memalloc(stack->size)))
// 		ERROR("failed to allocate array in create_array()");
// 	while (i < stack->size)
// 	{
// 		array[i] = elm->n; /* increment i here? */
// 		elm = elm->next;
// 		i++;
// 	}
// 	return (array);
// }
