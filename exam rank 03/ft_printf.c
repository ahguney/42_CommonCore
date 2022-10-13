#include <stdarg.h>
#include <unistd.h>

void putstr(char *str, int *len)
{
    if (!str)
    str = "(null)";
    while (*str)
    {
        *len += write(1, str++, 1);
    }
}

void    put_digit(long long int nbr, int base, int *len)
{
    if (nbr <0)
    {
        nbr *= -1;
        *len += write(1, "-", 1);
    }
    if (nbr >= base)
    put_digit((nbr / base), base, len);
    *len += write(1, &"0123456789abcdef"[nbr% base], 1);
}

int ft_printf(const char *str, ...)
{
    va_list ap;

    int len = 0;
    va_start(ap, str);
    while (*str)
    {
        if (*str == '%' && *(str + 1))
        {
            str++;
            if (*str == 's')
            putstr(va_arg(ap, char *), &len);
            else if (*str == 'd')
            {
                put_digit((long long int)va_arg(ap, int), 10, &len);
            }
            else if (*str == 'x')
            {
                put_digit((long long int)va_arg(ap, unsigned int), 16, &len);
            }
            else
           len += write(1, str, 1);
            str++;
        }
    }
    return (va_end(ap), len);
}

int main()
{
  int a =  ft_printf("%x", 55);
  ft_printf("%d", a);
}