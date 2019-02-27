#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int x = 0;
	int y = 0;
	char **arr;
	arr = (char **)malloc(sizeof(char *) * 5);

	while(x <=4 )
	{
		arr[x] = (char *)malloc(sizeof(char *) * 5);
		x++;
	}
	x = 0;
	while (x <= 4)
	{
		y = 0;
		while(y <= 4)
		{
			arr[x][y] = '1';
			y++;
		}
		x++;
	}

	// arr[0] = "00000";
	// arr[1] = "11111";
	// arr[2] = "22222";
	// arr[3] = "33333";
	// arr[4] = "44444";
	x = 0;
	while (x <= 4)
	{
		printf("%s\n", arr[x]);
		x++;
	}
	return 0;
}
