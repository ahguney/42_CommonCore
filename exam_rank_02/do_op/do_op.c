#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int	num1 = atoi(argv[1]);
	int	num2 = atoi(argv[3]);
	int	op = argv[2][0];
	int	res;

	if (argc == 4)
	{
		if (op == '+')
			res = num1 + num2;
		else if (op == '-')
			res = num1 - num2;
		else if (op == '*')
			res = num1 * num2;
		else if (op == '/')
			res = num1 / num2;
		else if (op == '%')
			res = num1 % num2;
		printf("%d\n", res);
	}
	else
		write(1, "\n", 1);
	return (0);
}
