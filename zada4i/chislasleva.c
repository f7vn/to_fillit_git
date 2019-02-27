#include <stdio.h>
#include <stdlib.h>

int chislasleva(int i)
{
	if (i)
		chislasleva(i / 10);
	// if (i)
		printf("%d ", i % 10);
	return (1);
}

int main(int argc, char const *argv[])
{
	int i;

	i = atoi(argv[1]);
	i = chislasleva(i);
	// printf("%d", i);
	return (0);
}
