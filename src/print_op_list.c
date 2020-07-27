/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_op_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 18:54:26 by eesaki            #+#    #+#             */
/*   Updated: 2020/07/23 21:00:20 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*strcpy_for_cat(char *dst, const char *src)
{
	int	i;

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
	char	*ops[NOPS] = {OPS};
	char	*output;
	char	*p;
	size_t	len;
	int		i;
	
	i = 0;
	len = 0;
	while (i++ < op_list->size)
	{
		len += ft_strlen(ops[op_list->head->n]) + 1;
		op_list->head = op_list->head->next;
	}
	if (!(output = ft_memalloc(len + 1)))
		ERROR("failed to allocate char *output");
	p = output;
	while (--i > 0)
	{
		p = strcpy_for_cat(p, ops[op_list->head->n]);
		*p++ = '\n';
		op_list->head = op_list->head->next;
	}
	*p = '\0';
	if (DBG) printf("op_list:\n"); setbuf(stdout, NULL);  // debug purpose
	write(1, output, len);
	free(output);
}