#include "../push_swap.h"
#include <stdio.h>

void		count_ins(t_ins_set *ins_set)
{
	int		n = 0;
	while (ins_set)
	{
		n++;
		ins_set = ins_set->next;
	}
	printf("%d instructions were executed.\n", n);
}

