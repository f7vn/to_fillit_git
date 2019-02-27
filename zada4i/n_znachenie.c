#include <stdio.h>
#include <stdlib.h>

void n_znachenie()
{
	int i;

	scanf("%d\n", &i);
	if (i != 0)
	{
		printf("%d\n", i);
		scanf("%d\n", &i);
			if (i != 0)
				n_znachenie();
	}
}

int main(int argc, char *argv[])
{
	n_znachenie();
	return 0;
}
