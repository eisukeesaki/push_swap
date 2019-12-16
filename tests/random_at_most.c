#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Assumes 0 <= max <= RAND_MAX
// Returns in the closed interval [0, max]
long	random_at_most(long max)
{
	// max <= RAND_MAX < ULONG_MAX, so this is okay.
	unsigned long	num_bins = (unsigned long) max + 1;
	unsigned long	num_rand = (unsigned long) RAND_MAX + 1;
	unsigned long	bin_size = num_rand / num_bins;
	unsigned long	defect = num_rand % num_bins;
	long			x;

	do
	{
		x = random();
	}
	// This is carefully written not to overflow
	while (num_rand - defect <= (unsigned long)x);

	// Truncated division is intentional
	return (x / bin_size);
}

// int		main(void)
// {
// 	int	i = 0;
// 	int	n;

// 	srandom(time(0));
// 	while (i++ < 5)
// 	{
// 		n = random_at_most(5);
// 		printf("%d\n", n);
// 	}

// 	return (0);
// }

/*
The loop is necessary to get a perfectly uniform distribution.
For example, if you are given random numbers from 0 to 2 and you want only ones from 0 to 1,
you just keep pulling until you don't get a 2; it's not hard to check that this gives 0 or 1 with equal probability.
This method is also described in the link that nos gave in their answer, though coded differently.
I'm using random() rather than rand() as it has a better distribution (as noted by the man page for rand()).

If you want to get random values outside the default range [0, RAND_MAX], then you have to do something tricky.
Perhaps the most expedient is to define a function random_extended()
that pulls n bits (using random_at_most()) and returns in [0, 2**n),
and then apply random_at_most() with random_extended() in place of random() (and 2**n - 1 in place of RAND_MAX)
to pull a random value less than 2**n, assuming you have a numerical type that can hold such a value.
Finally, of course, you can get values in [min, max] using min + random_at_most(max - min), including negative values.
*/
