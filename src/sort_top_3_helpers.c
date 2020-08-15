/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_top_3_helpers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 18:11:07 by eesaki            #+#    #+#             */
/*   Updated: 2020/08/15 19:41:14 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_top_mid_btm(t_stack *a, int *top, int *mid, int *btm)
{
	*top = a->head->n;
	*mid = a->head->next->n;
	*btm = a->head->next->next->n;
}
