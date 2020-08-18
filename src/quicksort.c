/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <eesaki@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 04:23:30 by eesaki            #+#    #+#             */
/*   Updated: 2020/08/16 14:52:08 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		quicksort(int *array, int size)
{
	int		pivot;
	int		i;
	int		k;
	int		tmp;

	if (size < 2)
		return ;
	i = 0;
	k = size - 1;
	pivot = array[size / 2];
	while (i <= k)
	{
		while (array[i] < pivot)
			i++;
		while (array[k] > pivot)
			k--;
		if (i >= k)
			break ;
		tmp = array[i];
		array[i++] = array[k];
		array[k--] = tmp;
	}
	quicksort(array, i);
	quicksort(array + i, size - i);
}

void		rev_quicksort(int *array, int size)
{
	int		pivot;
	int		i;
	int		k;
	int		tmp;

	if (size < 2)
		return ;
	i = 0;
	k = size - 1;
	pivot = array[size / 2];
	while (i <= k)
	{
		while (array[i] > pivot)
			i++;
		while (array[k] < pivot)
			k--;
		if (i >= k)
			break ;
		tmp = array[i];
		array[i++] = array[k];
		array[k--] = tmp;
	}
	rev_quicksort(array, i);
	rev_quicksort(array + i, size - i);
}
