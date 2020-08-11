/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 04:23:30 by eesaki            #+#    #+#             */
/*   Updated: 2020/08/11 13:58:54 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>  // debug purpose

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
		array[i] = array[k];
		array[k] = tmp;
		i++;
		k--;
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
		array[i] = array[k];
		array[k] = tmp;
		i++;
		k--;
	}
	rev_quicksort(array, i);
	rev_quicksort(array + i, size - i);
}

// int		main(void)
// {
// 	int		size = 15;
// 	int		array[] = {8, 1, 15, 4, 10, 13, 12, 11, 7, 9, 3, 6, 2, 5, 14};
// 	int		i = 0;

// 	rev_quicksort(array, 15);
// 	while (i < size)
// 		printf("%d\n", array[i++]);

// 	return (0);
// }

// void		partition(int *array, int start, int end)
// {
// 	int		pivot;
// 	int		i;
// 	int		j;

// 	pivot = array[0];
// 	i = start;
// 	j = end;
// }
