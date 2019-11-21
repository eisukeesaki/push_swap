/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_dnode_head.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 17:13:04 by eesaki            #+#    #+#             */
/*   Updated: 2019/11/20 21:25:45 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h>

void	link_dnode_head(t_stack **head, t_stack *new)
{
	new->next = *head;
	new->prev = NULL;
	(*head)->prev = new;
	*head = new;
}
