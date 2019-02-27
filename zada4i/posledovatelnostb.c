#include <stdio.h>
#include <stdlib.h>

void posledovatelnostb()
{
	int i;

	scanf("%d\n", &i);
	if (i == 0)
		exit(0);
	if (i % 2 == 0)
	{
		printf("ВЫВОД %d\n", i);
		posledovatelnostb();
	}
	else
		posledovatelnostb();
}

int main(int argc, char *argv[])
{
	posledovatelnostb();
	return 0;
}
