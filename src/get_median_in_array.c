/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_median_in_array.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 04:25:22 by eesaki            #+#    #+#             */
/*   Updated: 2020/07/28 04:25:53 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			*dup_int_array(int *array, int size)
{
	int		*new;
	int		i;

	if (!(new = ft_memalloc(sizeof(int) * size)))
		error("failed to allocate new at dup_int_array()");
	i = 0;
	while (i < size)
	{
		new[i] = array[i];
		i++;
	}
	return (new);
}

int		get_median_in_array(int *array, int size)
{
	int		*arr;
	int		median;

	arr = dup_int_array(array, size);
	quicksort(arr, size);
	median = arr[size / 2];
	free(arr);
	return (median);
}
