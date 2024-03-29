#include "philo.h"

void	free_all(t_table *table)
{
	free(table->philos);
	free(table->forks);
	free(table);
}

void	error_manage(void *kill, char *msg, int code)
{
	if (code == FREE)
		free(kill);
	printf("%s", msg);
}

int	start(t_table *table, int argc, char **argv)
{
	if (!check_args(table, argc, argv))
		return (0);
	if (!init(table, argc, argv))
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_table	*table;

	table = malloc(sizeof(t_table));
	if (!table)
		return (0);
	if (!start(table, argc, argv))
		return (0);
	if (!create_philo(table))
		free_all(table);
	return (0);
}
