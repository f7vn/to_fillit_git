#include <stdio.h>
#include <stdlib.h>

void polindromeh(int st, int i, char *line)
{
	if (st >= i)
		printf("EVERYTHINK GOOD\n");
	else if (line[st] == line[i])
		polindromeh(++st, --i, line);
	else
		printf("NOT_equal\n");
}

void polindrome(char *line)
{
	char *str;
	int i = 0;
	while (line[i])
		i++;
	polindromeh(0, --i, line);
}

int main(int argc, char *argv[])
{
	int i;
	int n;
	polindrome(argv[1]);
	//printf("%d\n", atoi(argv[1]));
	//n = nat_zna4(i, 1);
	return 0;
}
