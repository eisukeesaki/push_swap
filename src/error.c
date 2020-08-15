/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:28:13 by eesaki            #+#    #+#             */
/*   Updated: 2020/08/15 19:51:03 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <unistd.h>

void		error(char *message)
{
	t_bool	debug;

	write(1, "Error\n", 7);
	if (DBG)
		ft_putstr(message);
	exit(1);
}
