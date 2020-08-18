/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <eesaki@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 15:54:44 by eesaki            #+#    #+#             */
/*   Updated: 2020/08/18 21:59:14 by eesaki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

/*
**-----------------------------------------------------------------------------
**                                  macros
**-----------------------------------------------------------------------------
*/
# define DEBUG 0

/*
**-----------------------------------------------------------------------------
**                                  structs
**-----------------------------------------------------------------------------
*/
typedef struct		s_elm
{
	int				n;
	int				seg;
	t_bool			sorted;
	struct s_elm	*prev;
	struct s_elm	*next;
}					t_elm;

typedef struct		s_stack
{
	t_elm			*head;
	t_elm			*tail;
	int				size;
}					t_stack;

typedef struct		s_ps
{
	t_stack			*a;
	t_stack			*b;
	t_stack			*ops;
	/*t_bool			verbose;*/
}					t_ps;

/*
**-----------------------------------------------------------------------------
**                                  enums
**-----------------------------------------------------------------------------
*/
typedef enum		e_ops
{
	RA,  /* 0 */
	RB,  /* 1 */
	RRA, /* 2 */
	RRB, /* 3 */
	PA,  /* 4 */
	PB,  /* 5 */
	SA,  /* 6 */
	SB,  /* 7 */
	RR,  /* 8 */
	RRR, /* 9 */
	SS,  /* 10 */
	NOPS /* 11 (total amount of ops) */
}					t_ops;

/*
**-----------------------------------------------------------------------------
**                                  protptypes
**-----------------------------------------------------------------------------
*/
/* error.c */
void				error(char *message);

/* free.c */
void				free_output_and_ops(char *output, char **ops);
void				free_elms(t_stack *stack);
void				free_ps(t_ps *ps);
void				free_stack(t_ps *ps, t_stack *stack);

/* get_median_in_a.c */
int					get_median_in_a(t_stack *stack);

/* get_median_in_array.c */
int					get_median_in_array(int *array, size_t size);

/* list_manipulation.c */
void				unlink_node(t_stack *stack, t_elm *node);
void				append_node(t_stack *stack, t_elm *node);
t_elm				*create_node(int n);

/* load.c */
t_ps				*get_ps(char **av);

/* operations.c */
void				rotate_up(t_stack *stack);
void				rotate_down(t_stack *stack);
void				push(t_stack *from, t_stack *to);
void				swap(t_stack *stack);

/* pa_elms_gtet_median.c */
void				rotate_til_at_top(t_ps *ps, t_stack *stack, t_elm *dest);
void				pa_all_in_list(t_ps *ps, int *pa_list, int b_arr_size);
void				pa_elms_gtet_median(t_ps *ps);

/* pa_elms_gtet_median_part2.c */
void				assign_seg_id(t_stack *b, int seg_id, int push_ct);
void				delete_seg_id(t_stack *a, int pushed_size);
int					*create_array_of_seg(t_stack *stack, int seg, size_t *arr_size);

/* perform_op_ntimes.c */
void				perform_op_ntimes(t_ps *ps, int op, int n);

/* print_op_list.c */
void				print_op_list(t_stack *op_list);

/* ps_atoi.c */
intmax_t			ps_atoi(const char *str);

/* quicksort.c */
void				quicksort(int *array, int size);
void				rev_quicksort(int *array, int size);

/* sort.c */
void				sort(t_ps *ps);

/* sort_3.c */
void				sort_3(t_ps *ps, t_stack *stack);

/* sort_5.c */
void				sort_5(t_ps *ps);

/* sort_helpers.c */
int					get_top_seg(t_stack *b);
int					count_unsorted(t_stack *stack); // returns num of unsorted elms in stack_a
t_bool				is_sorted(t_stack *a);
int					get_rotation_count(t_stack *stack, t_elm *dest, t_bool reverse);
t_elm				*find_min(t_stack *stack);

/* sort_remaining_unsorteds_in_a.c */
void				mark_as_sorted(t_stack *stack);
void				sort_remaining_unsorteds_in_a(t_stack *a, t_ps *ps);

/* sort_top_3.c */
void				sort_top_3(t_ps *ps);

/* validation.c */
t_bool				is_sorted_circularly(t_stack *stack, t_elm *min_elm);
void				vali_dup(t_stack *stack, int n);

#endif
