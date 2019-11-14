/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newdnode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 18:07:09 by eesaki            #+#    #+#             */
/*   Updated: 2019/11/08 16:50:56 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

t_stack	*newdnode(int data)
{
	t_stack	*node;

	node = (t_stack *)ft_memalloc(sizeof(t_stack));
	node->n = data;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}
