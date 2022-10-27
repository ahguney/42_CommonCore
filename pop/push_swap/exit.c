#include "push_swap.h"

void ft_control(t_structs *stack_a, t_structs *stack_b, char **split1)
{
	char **splitted;

	splitted = split1;
	while (*splitted != 0)
	{
		if (ft_atoi_push(*splitted) == 1)
		ft_free(stack_a, stack_b, split1);
	}
}

void	ft_check_error(int argc, char **argv)
{
	int i = 1;
	t_structs *stack_a;
	t_structs *stack_b;
	char **split1;
	if (argc < 2)
		return (0);
	stack_a = malloc(sizeof(t_structs));
	stack_b = malloc(sizeof(t_structs));
	if (argc == 2)
	{
		if (argv[1] == 0)
		ft_free(stack_a, stack_b);
		if (argv[1] != 0)
		{
			split1 = ft_split(argv[1], ' ');
			ft_control(stack_a, stack_b, split1);

		}
	}
	return (1);
}