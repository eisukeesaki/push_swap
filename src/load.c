/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 18:34:58 by eesaki            #+#    #+#             */
/*   Updated: 2020/08/09 17:14:06 by eesaki           ###   ########.fr       */
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
	// stack->top_seg = 0;
}

t_ps		*alloc_ps(t_ps *ps)
{
	if (!(ps = ft_memalloc(sizeof(t_ps)))
		|| !(ps->a = ft_memalloc(sizeof(t_stack)))
		|| !(ps->b = ft_memalloc(sizeof(t_stack)))
		|| !(ps->ops = ft_memalloc(sizeof(t_stack))))
		ERROR("failed to allocate ps\n");
	init_stack(ps->a);
	init_stack(ps->b);
	init_stack(ps->ops);
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
		i++;
		free_split_args(split_args);
	}
	return (ps);
}

// t_ps		*get_ps(char **av) // fix: make it compatible with 100,500 test and checker
// {
// 	t_ps		*ps;
// 	char		**split_args;
// 	int			n;
// 	// size_t		i;
// 	size_t		k;

// 	ps = NULL;
// 	ps = alloc_ps(ps);
// 	// <parse flags>
// 	// i = 0;
// 	split_args = ft_strsplit(av[0], ' ');
// 	// while (av[0][i])
// 	// {
// 	k = 0;
// 	while (split_args[k])
// 	{
// 		n = ps_atoi(split_args[k]);
// 		vali_dup(ps->a, n);
// 		append_node(ps->a, create_node(n));
// 		k++;
// 	}
// 		// i++;
// 	// }
// 	free_split_args(split_args, k);
// 	return (ps);
// }
