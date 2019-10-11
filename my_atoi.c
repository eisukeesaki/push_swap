/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 02:56:20 by eesaki            #+#    #+#             */
/*   Updated: 2019/10/10 21:57:31 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdint.h>
// #include <stdio.h>

intmax_t	my_atoi(const char *str)
{
	intmax_t	n;
	int			i;
	int			neg;

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

// int		main(void)
// {
// 	char		s[] = "2147483648";
// 	intmax_t	ret = my_atoi(s);
// 	printf("%jd\n", ret);

// 	return (0);
// }