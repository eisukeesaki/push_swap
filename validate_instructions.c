/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_instructions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 20:34:15 by eesaki            #+#    #+#             */
/*   Updated: 2019/11/15 17:58:11 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stddef.h>
#define NVALID 11

void	compare(char *ins, char *valid[])
{
	size_t	i;

	i = 0;
	while (i < NVALID)
	{
		if (ft_strequ(ins, valid[i]))
			return ;
		i++;
	}
	// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< replace with error()
	write(1, "invalid ins", 12);
	exit(1);
	// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> replace with error()
}

void	vali_ins(char *ins)
{
	char	*valid[NVALID] =
	{
		"sa",
		"sb",
		"ss",
		"pa",
		"pb",
		"ra",
		"rb",
		"rr",
		"rra",
		"rrb",
		"rrr",
	};
	compare(ins, valid);
}
