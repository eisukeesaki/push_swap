#include "push_swap.h"

t_bool		confirm_sort_partial(t_stack *a)
{
	int		i;
	t_elm	*a_elm;

	i = 0;
	a_elm = a->head;
	while (i++ < a->size)
	{
		if (a_elm->n > a_elm->next->n != a_elm->sorted == FALSE)
			return (FALSE);
		a_elm = a_elm->next;
		i++;
	}
	return (TRUE);
}