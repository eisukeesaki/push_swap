#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <time.h>

long	random_at_most(long max)
{
	unsigned long	num_bins = (unsigned long) max + 1;
	unsigned long	num_rand = (unsigned long) RAND_MAX + 1;
	unsigned long	bin_size = num_rand / num_bins;
	unsigned long	defect = num_rand % num_bins;
	long			x;

	do
	{
		x = random();
	}
	while (num_rand - defect <= (unsigned long)x);

	return (x / bin_size);
}

int		is_duplicate(int e0, int e1, int e2, int e3, int e4)
{
	int		arr[5] = {e0, e1, e2, e3, e4};
	int		i = 0;
	int		k;

	while (i < 5)
	{
		k = i + 1;
		while (k < 5)
		{
			if (arr[i] == arr[k])
				return (1);
			k++;
		}
		i++;
	}
	return (0);
}

int		is_ascending(int e0, int e1, int e2, int e3, int e4)
{
	if (e0 < e1 && e1 < e2 && e2 < e3 && e3 < e4)
		return (1);
	return (0);
}

int		main(void)
{
	srandom(time(0));

	int		test_count = 5;

	int		e0 = 0;
	int		e1 = 0;
	int		e2 = 0;
	int		e3 = 0;
	int		e4 = 0;

	size_t	size = snprintf(NULL, 0, "ARG=\"%d %d %d %d %d\" ; ../push_swap $ARG | ../checker $ARG", e0, e1, e2, e3, e4) + 1;
	char	*command = malloc(size);

	while (0 < test_count)
	{
		e0 = random_at_most(4);
		e1 = random_at_most(4);
		e2 = random_at_most(4);
		e3 = random_at_most(4);
		e4 = random_at_most(4);

		if (is_duplicate(e0, e1, e2, e3, e4) || is_ascending(e0, e1, e2, e3, e4))
			continue;

		// run only push_swap
		sprintf(command, "ARG=\"%d %d %d %d %d\" ; ../push_swap $ARG", e0, e1, e2, e3, e4);

		// run both push_swap and checker
		// sprintf(command, "ARG=\"%d %d %d %d %d\" ; ../push_swap $ARG | ../checker $ARG", e0, e1, e2, e3, e4);

		printf("-------------------------------------------------------%d,%d,%d,%d,%d\n", e0, e1, e2, e3, e4); setbuf(stdout, NULL);
		// printf("%s\n", command);
		system(command);
		printf("-------------------------------------------------------%d,%d,%d,%d,%d\n\n", e0, e1, e2, e3, e4); setbuf(stdout, NULL);

		test_count--;
	}
	return (0);
}
