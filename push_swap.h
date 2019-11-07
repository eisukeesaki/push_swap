/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesaki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 12:21:01 by eesaki            #+#    #+#             */
/*   Updated: 2019/10/17 22:58:54 by eesaki           ###   ########.fr       */
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
typedef struct		s_stack
{
	int				n;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_ins
{
	char			*name;
	void			(*ins)(t_stack *);
}					t_ins;

/*
**-----------------------------------------------------------------------------
**									prototypes
**-----------------------------------------------------------------------------
*/
void				error(void);
intmax_t			my_atoi(const char *str);
int					get_next_line(const int fd, char **line);

t_stack				*newnode(int data);
void				ins_node_aft(t_stack *head, t_stack *new);

void				sa(t_stack *head);
void				sb(t_stack *head);

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