#include <stdio.h>
#include <stdlib.h>

void 	vse_mnoshiteli(long int i, int del)
{
	if (i >= del)
	{
		//printf("del = %d\ni = %d", del, i);
		if (i % del == 0)
		{

			printf("%d\n", del);
			vse_mnoshiteli(i, ++del);
		}
		else
			vse_mnoshiteli(i, ++del);
	}
}

int main(int argc, char const *argv[])
{
	int i;

	i = atoi(argv[1]);
	vse_mnoshiteli(i, 1);
	//printf("%d", vse_mnoshiteli(i));
	return (0);
}
