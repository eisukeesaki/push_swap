/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 04:23:30 by eesaki            #+#    #+#             */
/*   Updated: 2020/07/28 04:23:52 by eesaki           ###   ########.fr       */
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
		array[i] = array[k];
		array[k] = tmp;
		i++;
		k--;
	}
	quicksort(array, i);
	quicksort(array + i, size - i);
}

// void		partition(int *array, int start, int end)
// {
// 	int		pivot;
// 	int		i;
// 	int		j;

// 	pivot = array[0];
// 	i = start;
// 	j = end;
// }
