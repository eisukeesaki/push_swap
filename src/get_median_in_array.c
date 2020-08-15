/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_median_in_array.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 04:25:22 by eesaki            #+#    #+#             */
/*   Updated: 2020/08/15 19:58:59 by eesaki           ###   ########.fr       */
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
	int		*arr;
	int		median;

	arr = dup_int_array(array, size);
	quicksort(arr, size);
	median = arr[size / 2];
	free(arr);
	return (median);
}
