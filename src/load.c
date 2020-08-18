/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <eesaki@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 18:34:58 by eesaki            #+#    #+#             */
/*   Updated: 2020/08/18 20:43:23 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		free_split_args(char **split_args)
{
	int		i;

	i = 0;
	while (split_args[i])
	{
		free(split_args[i]);
		i++;
	}
	free(split_args);
}

void		init_stack(t_stack *stack)
{
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
}

t_ps		*alloc_ps(void)
{
	t_ps	*ps;

	if (!(ps = ft_memalloc(sizeof(t_ps)))
		|| !(ps->a = ft_memalloc(sizeof(t_stack)))
		|| !(ps->b = ft_memalloc(sizeof(t_stack)))
		|| !(ps->ops = ft_memalloc(sizeof(t_stack))))
		error("failed to allocate \"ps\" in init_stack()\n");
	init_stack(ps->a);
	init_stack(ps->b);
	init_stack(ps->ops);
	return (ps);
}

/*
** TODO parse option flags in get_ps()
*/

t_ps		*get_ps(char **av)
{
	t_ps	*ps;
	char	**split_args;
	int		n;
	size_t	i;
	size_t	k;

	ps = alloc_ps();
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
		i++;
		free_split_args(split_args);
	}
	return (ps);
}
