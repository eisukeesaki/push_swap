/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_median_in_array.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <eesaki@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 04:25:22 by eesaki            #+#    #+#             */
/*   Updated: 2020/08/18 21:18:35 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			*dup_int_array(int *array, size_t size)
{
	int		*new;
	size_t	i;

	if (!(new = ft_memalloc(sizeof(int) * size)))
		error("failed to allocate \"new\" in dup_int_array()\n");
	i = 0;
	while (i < size)
	{
		new[i] = array[i];
		i++;
	}
	return (new);
}

int			get_median_in_array(int *array, size_t size)
{
	int		median;
	int		*arr;

	arr = dup_int_array(array, size);
	quicksort(arr, size);
	median = arr[size / 2];
	free(arr);
	return (median);
}
