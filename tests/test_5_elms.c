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

int		main(void)
{
	srandom(time(0));

	int		test_count = 2;

	int		e0 = 0;
	int		e1 = 0;
	int		e2 = 0;
	int		e3 = 0;
	int		e4 = 0;

	size_t	size = snprintf(NULL, 0, "ARG=\"%d %d %d %d %d\" ; ../push_swap $ARG | ../checker $ARG", e0, e1, e2, e3, e4) + 1;
	char	*command = malloc(size);

	while (0 < test_count--)
	{
		e0 = random_at_most(100);
		e1 = random_at_most(100);
		e2 = random_at_most(100);
		e3 = random_at_most(100);
		e4 = random_at_most(100);

		// run only push_swap
		sprintf(command, "ARG=\"%d %d %d %d %d\" ; ../push_swap $ARG", e0, e1, e2, e3, e4);

		// run both push_swap and checker
		// sprintf(command, "ARG=\"%d %d %d %d %d\" ; ../push_swap $ARG | ../checker $ARG", e0, e1, e2, e3, e4);

		printf("-------------------------------------------------------%d,%d,%d,%d,%d\n", e0, e1, e2, e3, e4); setbuf(stdout, NULL);
		// printf("%s\n", command);
		system(command);
		printf("-------------------------------------------------------%d,%d,%d,%d,%d\n\n", e0, e1, e2, e3, e4); setbuf(stdout, NULL);
	}
	return (0);
}
