/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <eesaki@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 02:56:20 by eesaki            #+#    #+#             */
/*   Updated: 2020/08/18 21:25:14 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

intmax_t		ps_atoi(const char *str)
{
	intmax_t	n;
	int			neg;
	int			i;

	n = 0;
	i = 0;
	while (ft_iswhitespace(str[i]))
		i++;
	neg = str[i] == '-';
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		n = (n * 10) + (str[i] - '0');
		i++;
	}
	return (neg ? -n : n);
}
