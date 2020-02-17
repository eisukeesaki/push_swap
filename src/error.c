/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:28:13 by eesaki            #+#    #+#             */
/*   Updated: 2020/02/16 20:21:56 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

void	error(char *message)
{
	t_bool		debug;

	write(1, "Error\n", 7);
	if ((debug = 1))/* disable it when dev is complete! */
		ft_putstr(message);
	exit(1);
}
