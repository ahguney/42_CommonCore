#include <unistd.h>
#include <stdarg.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i = 0;
	if (!str)
		str = "(null)";
	while (*str)
		i += write(1, str++, 1);
	return (i);
}

int	ft_putnbr(long int n)
{
	int	i = 0;
	if (n < 0)
	{
		i += write(1, "-", 1);
		n = -n;
	}
	if (n < 10)
		i += ft_putchar(n + '0');
	else
	{
		i += ft_putnbr(n / 10);
		i += ft_putnbr(n % 10);
	}
	return (i);
}

int	hex(unsigned int hexa)
{
	int	i = 0;

	if (hexa >= 16)
	{
		i += hex(hexa / 16);
		i += hex(hexa % 16);
	}
	else if (hexa > 9)
		i += ft_putchar(hexa + 'W');
	else
		i += ft_putchar(hexa + '0');
	return (i);
}

int	ft_printf(const char *s, ...)
{
	int		i = -1;
	int		n = 0;
	va_list	ap;//argument pointer

	va_start(ap, s);//read ap after s
	while (s[++i])
	{
		if (s[i] == '%')
		{
			i++;
			if (s[i] == 's')
				n += ft_putstr(va_arg(ap, char *));
			else if (s[i] == 'x')
				n += hex(va_arg(ap, unsigned int));
			else if (s[i] == 'd')
				n += ft_putnbr(va_arg(ap, int));
		}
		else
			n += write(1, &s[i], 1);
	}
	va_end(ap);
	return (n);
}

#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int	size;

	size = 0;

	size = ft_printf("%s\n", "toto");
	printf("%d\n", size);
	size = printf("%s\n", "toto");
	printf("%d\n", size);
	size = ft_printf("Magic %s is %d\n", "number", 42);
	printf("%d\n", size);
	size = printf("Magic %s is %d\n", "number", 42);
	printf("%d\n", size);
	size = ft_printf("Hexadecimal for %d is %x\n", 42, 42);
	printf("%d\n", size);
	size = printf("Hexadecimal for %d is %x\n", 42, 42);
	printf("%d\n", size);
	size = ft_printf("%d %d %x\n", INT_MAX, INT_MIN, UINT_MAX);
	printf("%d\n", size);
	size = ft_printf("%d %d %x\n", INT_MAX, INT_MIN, UINT_MAX);
	printf("%d\n", size);
	size = ft_printf("%d, %d\n", 0, -24);
	printf("%d\n", size);
	size = ft_printf("%d, %d\n", 0, -24);
	printf("%d\n", size);
	printf("%d\n", size);
	ft_printf("Hello world %\n");
	return (0);
}
