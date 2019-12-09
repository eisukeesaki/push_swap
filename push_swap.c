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

t_stack	*build_a(int ac, char **av) // exceeding 25 lines!
{
	size_t	i;
	size_t	k;
	char	**split;
	t_stack	*head; // head == top of stack
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
		}
		k = 0;
		i++;
		free_split_str(split);
	}
	return (head);
}

int		find_min(t_stack **stack_a)
{
	t_stack	*a;
	int		min;

	a = (*stack_a)->next;
	min =  (*stack_a)->n;
	while (a != NULL)
	{
		if (a->n < min)
			min = a->n;
		a = a->next;
	}
	return (min);
}

int		main(int ac, char **av)
{
	t_stack		*stack_a;
	t_stack		*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac > 1)
		stack_a = build_a(ac, av);
	else
		exit(0);
	vali_dup(stack_a); // do it when building stack_a?
	print_stacks(stack_a, stack_b); // debug purpose
	// if (elm_ttl is 3 or 5)
		// 3_or_5_sort(stack_a)
	/*else*/ if (ac >= 8 && 801 >= ac)
		chunk_sort(&stack_a, &stack_b);

	if (vali_sort(stack_a, stack_b) == 1)
		insert_sort(&stack_a, &stack_b);
	print_stacks(stack_a, stack_b); // debug purpose | TODO: [] print stack_b in sorting func
	// print_stacks_bw(stack_a, stack_b); // debug purpose
	free_stacks(stack_a);
	free_stacks(stack_b); // TODO:	[] free stack_b in sorting func
	write(1, "OK", 3);
	// system("leaks checker");
	return (0);
}


/** sorting algo
 * ra until min is at top of A
 * pb
 * repeat until A is empty
 * pa until B is empty
 * 
 * TODO: record called ins
 * TODO: print recorded ins
**/ 

/** sorting algo (requires tmp var)
 * if stack_b is empty, move top@stack_a to top@stack_b
 * while stack_a is not empty
 	* move top of stack_a to tmp
 	* while there're elements in stack_b && tmp > top@stack_b
 		* move top@stack_b to top@stack_a
	* move tmp to top@stack_b
 * 
**/

/**
 * input: stack_a
 * output: instruction set that sorts stack_a
 * 
 * validate stack_a
 * make linked list of stack_a
 * sort list with quicksort program?
 * validate sort
 * write instruction set to stdout
 * write status to stdout
**/

// tests:
//	- already sorted lists
//		- "$>./push_swap 42". The program should display nothing (0 instruction)
//		-  "$>./push_swap 0 1 2 3". The program should display nothing (0 instruction)
//		- "$>./push_swap 0 1 2 3 4 5 6 7 8 9". The program should display nothing (0 instruction)

// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< old
// sort_1(&stack_a, &stack_b); // callere

void	sort_1(t_stack **stack_a, t_stack **stack_b) // optimize by implementing ra/rra selector
{
	printf("<<< sorting started.\n"); // debug purpose
	t_stack	*a;
	t_stack	*b;
	int		min;

	a = *stack_a;
	b = *stack_b;
	min = find_min(stack_a);
	while (a != NULL)
	{
		while (min < (*stack_a)->n)
			ra(stack_a, NULL); // TODO:	[] modify ins func prototype. no need to pass stack_b
		pb(stack_a, stack_b);
		a = a->next;
	}
	while (*stack_b != NULL)
	{
		pa(stack_a, stack_b);
		*stack_b = (*stack_b)->next;
	}
	printf(">>> sorting complete.\n"); // debug purpose
}
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> old