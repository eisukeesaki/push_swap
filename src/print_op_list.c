/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_op_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <eesaki@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 18:54:26 by eesaki            #+#    #+#             */
/*   Updated: 2020/02/21 20:35:42 by eesaki           ###   ########.fr       */
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
	char	*tmp;
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
	tmp = output;
	while (--i > 0)
	{
		tmp = strcpy_for_cat(tmp, ops[op_list->head->n]);
		*tmp++ = '\n';
		op_list->head = op_list->head->next;
	}
	*tmp = '\0';
			printf("op_list:\n"); setbuf(stdout, NULL);  // debug purpose
	write(1, output, len);
	free(output);
}
