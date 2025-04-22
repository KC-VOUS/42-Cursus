#include "../philo.h"

void	cleanup(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_of_philo)
	{
		pthread_mutex_destroy(&data->philo[i].cadenas);
		pthread_mutex_destroy(&data->fork[i]);
	}
	pthread_mutex_destroy(&data->message);
	pthread_mutex_destroy(&data->lock);
	free(data->tid);
	free(data->philo);
	free(data->fork);
	exit(EXIT_SUCCESS);
}

int	error(char *str, t_data *data)
{
	printf("%s\n", str);
	if (data)
		cleanup(data);
	return (1);
}
