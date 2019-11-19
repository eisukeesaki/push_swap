/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 12:21:01 by eesaki            #+#    #+#             */
/*   Updated: 2019/11/18 19:42:54 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdint.h>
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< testing
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> testing
// # include "libft/libft.h"

/*
**-----------------------------------------------------------------------------
**									structs
**-----------------------------------------------------------------------------
*/
typedef struct			s_stack
{
	int					n;
	struct s_stack		*prev;
	struct s_stack		*next;
}						t_stack;

typedef struct			s_ins_set
{
	char				*ins;
	struct s_ins_set	*next;
}						t_ins_set;

typedef struct			s_ins
{
	char				*name;
	void				(*ins)(t_stack *);
}						t_ins;

typedef void 			ins(t_stack head);
typedef struct			s_functab
{
	char				*ins_str;
	void				(*ins_func)(t_stack **stack_a, t_stack **stack_b);
	// void				(*ins_func)(t_stack *stack_a __attribute((unused)), t_stack *stack_b __attribute((unused)));
}						t_functab;

/*
**-----------------------------------------------------------------------------
**									prototypes
**-----------------------------------------------------------------------------
*/
void				error(void);
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< debug purpose
void				dup_err(void);
void				notint_err(void);
void				sort_err(void);
void				print_stacks(t_stack *stack_a, t_stack *stack_b);
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> debug purpose
intmax_t			my_atoi(const char *str);
intmax_t			vali_int(intmax_t n);
void				vali_dup(t_stack *head);
t_ins_set			*read_ins(void);
void				vali_ins(char *ins);
void				vali_sort(t_stack *head);
void				exe_ins(t_ins_set *ins_set, t_stack **stack_a, t_stack **stack_b);

t_stack				*newdnode(int data);
void				link_dnode_head(t_stack *head, t_stack *new);
void				link_dnode_tail(t_stack *head, t_stack *new);

// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< instruction functions
// void				sa(t_stack *head __attribute((unused)));
// void				sb(t_stack *head __attribute((unused)));
// void				ss(t_stack *head __attribute((unused)));
// void				pa(t_stack *head __attribute((unused)));
// void				pb(t_stack *head __attribute((unused)));
// void				ra(t_stack *head __attribute((unused)));
// void				rb(t_stack *head __attribute((unused)));
// void				rr(t_stack *head __attribute((unused)));
// void				rra(t_stack *head __attribute((unused)));
// void				rrb(t_stack *head __attribute((unused)));
// void				rrr(t_stack *head __attribute((unused)));

void				sa(t_stack **stack_a, t_stack **stack_b __attribute__((unused)));
void				sb(t_stack **stack_a __attribute__((unused)), t_stack **stack_b);
void				ss(t_stack **stack_a, t_stack **stack_b);
void				pa(t_stack **stack_a, t_stack **stack_b);
void				pb(t_stack **stack_a, t_stack **stack_b);
void				ra(t_stack **stack_a, t_stack **stack_b __attribute__((unused)));
void				rb(t_stack **stack_a __attribute__((unused)), t_stack **stack_b);
// void				rr(t_stack **stack_a, t_stack **stack_b);
// void				rra(t_stack **stack_a, t_stack **stack_b);
// void				rrb(t_stack **stack_a, t_stack **stack_b);
// void				rrr(t_stack **stack_a, t_stack **stack_b);
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> instruction functions

// t_ins				ins_table[2] =
// {
// 	{"sa", sa},
// 	{"sb", sb},
// };

// typedef struct		s_list
// {
// 	int				*n;
// 	struct s_list	*next;
// }					t_list;


#endif