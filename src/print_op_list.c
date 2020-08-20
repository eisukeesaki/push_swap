/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_op_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <eesaki@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 18:54:26 by eesaki            #+#    #+#             */
/*   Updated: 2020/08/21 01:23:26 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**init_ops(void)
{
	char	**ops;

	if (!(ops = ft_memalloc(sizeof(char *) * NOPS + 1)))
		error("failed to allocate ops in init_ops()");
	ops[0] = ft_strdup("ra");
	ops[1] = ft_strdup("rb");
	ops[2] = ft_strdup("rra");
	ops[3] = ft_strdup("rrb");
	ops[4] = ft_strdup("pa");
	ops[5] = ft_strdup("pb");
	ops[6] = ft_strdup("sa");
	ops[7] = ft_strdup("sb");
	ops[8] = ft_strdup("rr");
	ops[9] = ft_strdup("rrr");
	ops[10] = ft_strdup("ss");
	ops[11] = NULL;
	return (ops);
}

static char	*strcpy_for_cat(char *dst, const char *src)
{
	int		i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	return (dst + i);
}

void		print_op_list(t_stack *op_list)
{
	char	**ops;
	char	*output;
	char	*p;
	size_t	len;
	int		i;

	i = 0;
	len = 0;
	ops = init_ops();
	while (i++ < op_list->size)
	{
		len += ft_strlen(ops[op_list->head->n]) + 1;
		op_list->head = op_list->head->next;
	}
	if (!(output = ft_memalloc(len + 1)))
		error("failed to allocate \"output\" in print_op_list()\n");
	p = output;
	while (--i > 0)
	{
		p = strcpy_for_cat(p, ops[op_list->head->n]);
		*p++ = '\n';
		op_list->head = op_list->head->next;
	}
	write(1, output, len);
	free_output_and_ops(output, ops);
}
