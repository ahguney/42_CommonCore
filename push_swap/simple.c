#include "push_swap.h"

static int	get_min(t_list **stack)
{
	t_list	*tmp;
	int		min;

	tmp = *stack;
	min = tmp->index;
	while (tmp)
	{
		if (tmp->index < min)
			min = tmp->index;
		tmp = tmp->next;
	}
	return (min);
}

static void	sort3(t_list **stack_a)
{
	t_list	*tmp;

	tmp = *stack_a;
	while (!is_sorted(stack_a))
	{
		if ((tmp->content > tmp->next->next->content)
			&& (tmp->next->content < tmp->next->next->content))
			ra(stack_a);
		else if (tmp->content > tmp->next->content)
			sa(stack_a);
		else
			rra(stack_a);
		tmp = *stack_a;
	}
}

static void	sort4_5(t_list **stack_a, t_list **stack_b)
{
	int		min;
	t_list	*tmp;

	tmp = *stack_a;
	while (!is_sorted(stack_a))
	{
		tmp = *stack_a;
		min = get_min(stack_a);
		if (tmp->index == min)
		{
			pb(stack_a, stack_b);
			if (ft_lstsize(*stack_a) == 3)
				break ;
		}
		else if (tmp->next->index == min)
			ra(stack_a);
		else
			rra(stack_a);
	}
	if (!is_sorted(stack_a))
		sort3(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
}

void	simple_sort(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (size == 2)
		sa(stack_a);
	else if (size == 3)
		sort3(stack_a);
	else if (size == 4 || size == 5)
		sort4_5(stack_a, stack_b);
}
