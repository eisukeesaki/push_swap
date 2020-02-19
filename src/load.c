/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 18:34:58 by eesaki            #+#    #+#             */
/*   Updated: 2020/02/17 18:21:06 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// char		**split(char *s)
// {

// }

t_ps		*alloc_ps(t_ps *ps)
{
	if (!(ps = ft_memalloc(sizeof(t_ps)))
		|| !(ps->a = (t_stack *)ft_memalloc(sizeof(t_stack)))
		|| !(ps->b = (t_stack *)ft_memalloc(sizeof(t_stack)))
		|| !(ps->ops = (t_stack *)ft_memalloc(sizeof(t_stack))))
		ERROR("failed to allocate ps\n");
		// printf(); setbuf(stdout, NULL); // debug purpose
	return (ps);
}

t_ps		*get_ps(char **av)
{
	t_ps		*ps;
	char		**split_args;
	int			n;
	size_t		i;
	size_t		k;

	ps = NULL;
	ps = alloc_ps(ps);
	// <parse flags>
	i = 0;
	while (av[i])
	{
		k = 0;
		split_args = ft_strsplit(av[i], ' ');
		while (split_args[k])
		{
			n = ps_atoi(split_args[k]);
			vali_dup(ps->a, n);
			append_node(ps->a, create_node(n));
			k++;
		}
		free(split_args);
		i++;
	}
	// print_stacks(ps, ""); // debug purpose
	return (ps);
}
