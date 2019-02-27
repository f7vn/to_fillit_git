#include <stdio.h>
#include <stdlib.h>


int fromA2B(int a, int b)
{
	if (a == b)
	{
		printf("%d\n", a);
		return (a);
	}

	else if (a < b)
	{
		printf("%d\n", a);
		return (fromA2B(++a, b));
	}

	else if (a > b)
	{
		printf("%d\n", a);
		return (fromA2B(--a, b));
	}
	return (0);
}

int main(int argc, char const *argv[])
{
	int a;
	int b;
	int n;
	a = atoi(argv[1]);
	b = atoi(argv[2]);
	//printf("%d\n", atoi(argv[1]));
	n = fromA2B(a, b);
	return 0;
}
