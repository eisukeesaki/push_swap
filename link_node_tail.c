/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_node_tail.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 17:13:04 by eesaki            #+#    #+#             */
/*   Updated: 2019/10/13 20:12:26 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h>

void	link_node_tail(t_stack *head, t_stack *new)
{
	while (head->next != NULL)
		head = head->next;
	new->prev = head;
	head->next = new;
}
