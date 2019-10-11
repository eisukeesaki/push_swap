/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 12:21:01 by eesaki            #+#    #+#             */
/*   Updated: 2019/10/10 21:59:04 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdint.h>
// # include "libft/libft.h"

typedef struct		s_stack
{
	int				n;
	struct s_stack	*next;
}					t_stack;

// typedef struct		s_list
// {
// 	int				*n;
// 	struct s_list	*next;
// }					t_list;

/*
**-----------------------------------------------------------------------------
**									prototypes
**-----------------------------------------------------------------------------
*/
void				error(void);
intmax_t			my_atoi(const char *str);

#endif