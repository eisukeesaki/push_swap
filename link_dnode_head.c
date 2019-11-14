/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_dnode_head.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 17:13:04 by eesaki            #+#    #+#             */
/*   Updated: 2019/11/08 17:04:06 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h>

void	link_dnode_head(t_stack *head, t_stack *new)
{
	new->next = head;
	head->prev = new;
}
