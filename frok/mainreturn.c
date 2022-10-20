#include <unistd.h>
int ft_printf(const char *str, ...);
int main()
{
    int a = ft_printf("%d", 55);
    ft_printf("%d", a);
    int b = ft_printf("%x", 12);
    ft_printf("%d", b);
    int c = ft_printf("%s", "furkan");
    ft_printf ("%d", c);
}