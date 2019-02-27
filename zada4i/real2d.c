#include <stdio.h>
#include <stdlib.h>

int real2d(int i, int pow)
{
	if (pow == i)
	{
		printf("YES\n");
		return (1);
	}
	else if (pow > i)
	{
		printf("NO\n");
		return (1);
	}
	else
		return (real2d(i, pow * 2));
}


int main(int argc, char const *argv[])
{
	int i;

	i = atoi(argv[1]);
	real2d(i, 1);
	return (0);
}
