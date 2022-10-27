#include <push_swap.h>

int	check_atoi_numbers(char *string)
{
	char	*temp;

	temp = string;
	if (*temp == 0)
		return (0);
	while (*temp)
	{
		if (*temp >= '0' && *temp <= '9')
			temp++;
		else
			return (0);
	}
	return (1);
}

long int	ft_atoi_push(char *str)

{
	long int	res;
	int			sign;

	res = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r'
		|| *str == '\v' || *str == '\f')
			str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	if (!check_atoi_numbers(str))
		return (1);
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		if (res > 2147483647 || res < -2147483648)
			return (1);
		str++;
	}
	return (sign * res);
}