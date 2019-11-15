/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_instructions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 20:34:15 by eesaki            #+#    #+#             */
/*   Updated: 2019/11/15 00:00:53 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stddef.h>

void	compare(char *ins, char *valid[])
{
	size_t	i;

	i = 0;
	while (valid[i])
	{
		if (!(ft_strequ(ins, valid[i])))
		{
			write(1, "invalid ins", 12);
			exit(1);
		}
		i++;
	}
}

void	vali_ins(char *ins)
{
	char	*valid[] =
	{
		"sa\n",
		"sb\n",
		"ss\n",
		"pa\n",
		"pb\n",
		"ra\n",
		"rb\n",
		"rr\n",
		"rra\n",
		"rrb\n",
		"rrr\n",
		"\0",
	};
	compare(ins, valid);
}
