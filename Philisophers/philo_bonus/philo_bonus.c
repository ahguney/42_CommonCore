#include "philo_bonus.h"

void	free_all(t_table *table)
{
	free(table->philo_index);
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
	if (!check_args(table, argc, argv) || !init(table, argc, argv))
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_table	*table;

	table = malloc(sizeof(t_table));
	if (!table || !start(table, argc, argv))
		return (0);
	if (!create_philo(table))
		free_all(table);
	return (1);
}
