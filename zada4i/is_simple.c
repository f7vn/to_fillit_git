#include <stdio.h>
#include <stdlib.h>

void 	is_simple(int i, int del)
{
	if (i > del)
	{
		//printf("del = %d\ni = %d", del, i);
		if (i % del == 0)
		{
			printf("NOSIMPLE\n");
			exit(0);
		}
		else
			is_simple(i, ++del);
	}
	printf("SIMPLE\n");
	exit(0);
}

int main(int argc, char const *argv[])
{
	int i = atoi(argv[1]);
	printf("main 4islo %d\n", i);
	is_simple(i, 2);
	//printf("%d", chislasprava(i));
	return (0);
}
