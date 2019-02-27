#include <stdio.h>
#include <stdlib.h>

// int nat_zna4(int i)
// {
// 	if (i == 1)
// 		return (1);
// 	if(nat_zna4(--i))
// 	{
// 		printf("%d", i);
// 	}
// 	return (i);
// }

int nat_zna4(int i, int n)
{
	printf("%d\n", n);
	if (i == n)
		return (n);
	return (nat_zna4(i, n + 1));
}

int main(int argc, char const *argv[])
{
	int i;
	int n;
	i = atoi(argv[1]);
	//printf("%d\n", atoi(argv[1]));
	n = nat_zna4(i, 1);
	return 0;
}
