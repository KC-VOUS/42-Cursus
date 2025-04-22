#include "../philo.h"

int	malloc_data(t_data *data)
{
	data->tid = malloc(sizeof(pthread_t) * data->nb_of_philo);
	if (!data->tid)
		return (1);
	data->philo = malloc(sizeof(t_philo) * data->nb_of_philo);
	if (!data->philo)
	{
		free(data->tid);
		return (1);
	}
	data->fork = malloc(sizeof(pthread_mutex_t) * data->nb_of_philo);
	if (!data->fork)
	{
		free(data->tid);
		free(data->philo);
		return (1);
	}
	return (0);
}

int	mutex_data(t_data *data)
{
	int	i;

	if (pthread_mutex_init(&data->message, NULL))
		return (1);
	if (pthread_mutex_init(&data->lock, NULL))
	{
		pthread_mutex_destroy(&data->message);
		return (1);
	}
	i = -1;
	while (++i < data->nb_of_philo)
	{
		if (pthread_mutex_init(&data->fork[i], NULL))
		{
			pthread_mutex_destroy(&data->message);
			pthread_mutex_destroy(&data->lock);
			while (--i >= 0)
				pthread_mutex_destroy(&data->fork[i]);
			return (1);
		}
	}
	return (0);
}
