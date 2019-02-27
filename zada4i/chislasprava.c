#include <stdio.h>
#include <stdlib.h>

int chislasprava(int i)
{
	printf("%d", i % 10);
	return (i > 0 ? chislasprava(i / 10) : 0);
}


int main(int argc, char const *argv[])
{
	int i;

	i = atoi(argv[1]);
	chislasprava(i);
	printf("%d", chislasprava(i));
	return (0);
}
