#include <unistd.h>
int ft_printf(const char *str, ...);
int main()
{
    int a = ft_printf("%d ", 55);
    printf("%d", 2);
    int b = ft_printf("%x ", 12);
    printf ("%d", b);
    int c = ft_printf("%s", "furkan");
}