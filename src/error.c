/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <eesaki@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:28:13 by eesaki            #+#    #+#             */
/*   Updated: 2020/02/20 20:23:15 by eesaki           ###   ########.fr       */
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
