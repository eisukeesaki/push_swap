/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newnode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 18:07:09 by eesaki            #+#    #+#             */
/*   Updated: 2019/10/10 17:37:43 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

t_stack	*newnode(int data)
{
	t_stack	*node;

	node = (t_stack *)ft_memalloc(sizeof(t_stack));
	node->n = data;
	node->next = NULL;
	return (node);
}
