#include "push_swap.h"

int	swap(t_list **stack)
{
	t_list	*tmp;
	int		i;
	int a;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	tmp = *stack;
	i = tmp->index;
	tmp->index = tmp->next->index;
	tmp->next->index = i;
	a = tmp->content;
	tmp->content = tmp->next->content;
	tmp->next->content = a;
	return (0);
}

int	sa(t_list **stack_a)
{
	if (swap(stack_a) == -1)
		return (-1);
	ft_putendl_fd("sa", 1);
	return (0);
}

int	sb(t_list **stack_b)
{
	if (swap(stack_b) == -1)
		return (-1);
	ft_putendl_fd("sb", 1);
	return (0);
}

int	ss(t_list **stack_a, t_list **stack_b)
{	
	if ((ft_lstsize(*stack_a) < 2) || (ft_lstsize(*stack_b) < 2))
		return (-1);
	swap(stack_a);
	swap(stack_b);
	ft_putendl_fd("ss", 1);
	return (0);
}
