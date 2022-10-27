#include <push_swap.h>

void    ft_free(t_structs *stack_a, t_structs *stack_b)
{
    free(stack_a);
    free(stack_b);
    write(1, "Error\n", 6);
    exit(EXIT_FAILURE);
}