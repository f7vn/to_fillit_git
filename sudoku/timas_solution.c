void valid_x_y(int *x, int *y)
{
	if (*x > 8)
	{
		(*y)++;
		(*x) = 0;
	}
}

void solution(int ***mtx, int x, int y)
{
	int i;
	if (y == 9)
		return (1);
	i = 0;
	while(++i <= 9)
	{
		if (valid(*mtx, x, y, i))
		{
			valid_x_y(&x, &y);
			if (solution(mtx, x, y))
				return (1);
		}
	}
	return (0);
}

int main(int argc, char const *argv[]) {
	/* code */
	return 0;
}
