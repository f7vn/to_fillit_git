#include <stdio.h>
#include <stdlib.h>

int sum4isl(int i)
{
	printf("%d\n", i);
	return (i % 10 + (i > 0 ? sum4isl(i / 10) : 0));
}

int main(int argc, char const *argv[])
{
	int i;

	i = atoi(argv[1]);
	printf("%d", sum4isl(i));
	return (0);
}
