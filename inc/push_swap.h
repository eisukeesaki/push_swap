/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 15:54:44 by eesaki            #+#    #+#             */
/*   Updated: 2020/02/16 20:24:35 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdint.h>
# include <stdlib.h>
# include "libft.h"
# include <stdio.h> // debug purpose

/*
**-----------------------------------------------------------------------------
**                                  macros
**-----------------------------------------------------------------------------
*/
# define ERROR(message) error(message)
// # define ERROR(message) error(message)

/*
**-----------------------------------------------------------------------------
**                                  structs
**-----------------------------------------------------------------------------
*/
typedef struct		s_elm
{
	int				n;
	struct s_elm	*prv;
	struct s_elm	*nxt;
}					t_elm;

typedef struct		s_stack
{
	t_elm			*head;
	int				size;
}					t_stack;

typedef struct		s_ps
{
	t_stack			*a;
	t_stack			*b;
	t_stack			*ops;
	t_bool			verbose;
}					t_ps;

/*
**-----------------------------------------------------------------------------
**                                  protptypes
**-----------------------------------------------------------------------------
*/
/* -------------------------------- debug -------------------------------- */
void				print_stacks(t_ps *ps, char *comment);

void				error(char *message);

/* -------------------------------- helpers -------------------------------- */
intmax_t			ps_atoi(const char *str);

void				vali_dup(t_stack *stack, int n);
t_ps				*get_ps(char **av);

t_elm				*create_node(int n);
void				append_node(t_stack *stack, t_elm *node);
#endif
