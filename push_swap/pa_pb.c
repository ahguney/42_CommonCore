#include "push_swap.h"

int 	push(t_list **stack_0, t_list **stack1)
{
	t_list *tmp;

	if (!(*stack_0))
		return (0);
	tmp = *stack_0;
	*stack_0 = (*stack_0)->next;
	tmp->next = (*stack1);
	*stack1 = tmp;
	return (1);
}

int	pa(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_b) == 0)
		return (-1);
	push(stack_b, stack_a);
	ft_putendl_fd("pa", 1);
	return (0);
}

int	pb(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) == 0)
		return (-1);
	push(stack_a, stack_b);
	ft_putendl_fd("pb", 1);
	return (0);
}
