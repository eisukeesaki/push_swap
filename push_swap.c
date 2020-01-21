#include "push_swap.h"
#include <stddef.h>
#include <stdlib.h>
#include "libft/libft.h"
#include <stdio.h> // debug purpose

void	free_split_str(char **split)
{
	size_t	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	free_stacks(t_stack *stack)
{
	while (stack != NULL)
	{
		free(stack);
		stack = stack->next;
	}
}

t_stack	*build_a(int ac, char **av, int *n_elms) // exceeding 25 lines!
{
	size_t	i;
	size_t	k;
	char	**split;
	t_stack	*head;
	t_stack	*tmp;

	i = 1;
	k = 0;
	head = NULL;
	while (i < (size_t)ac)
	{
		split = ft_strsplit(av[i], ' ');
		while (split[k])
		{
			tmp = newdnode(vali_int(my_atoi(vali_num(split[k]))));
			if (head == NULL)
				head = tmp;
			else
				link_dnode_tail(head, tmp);
			k++;
			(*n_elms)++;
		}
		k = 0;
		i++;
		free_split_str(split);
	}
	return (head);
}

int		main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		n_elms;

	n_elms = 0;
	stack_a = build_a(ac, av, &n_elms);
	stack_b = NULL;
// /* debug */	print_stacks(stack_a, stack_b, " (initial)");
	if (is_sorted(stack_a, stack_b))
	{
		// printf("initially sorted\n\n"); // debug purpose
		return (0);
	}
	if (n_elms <= 5)
		sort_small(&stack_a, &stack_b, n_elms);
	else if (n_elms >= 6)
		sort_medium(&stack_a, &stack_b, n_elms);
	// else if (n_elms == 2 || n_elms == 4 || n_elms >= 6)
	// 	insert_sort(&stack_a, &stack_b);
// /* debug */	print_stacks(stack_a, stack_b, " (sorted)");
	free_stacks(stack_a);
	free_stacks(stack_b); // TODO:	[] free stack_b in sorting func
	// system("leaks push_swap");
	return (0);
}

// TODO:	[] why is leaks reporting 0 leaks when stacks aren't free-ed?