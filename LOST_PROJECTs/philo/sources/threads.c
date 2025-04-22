#include "../philo.h"

int	thread_things(t_data *data)
{
	int			i;
	pthread_t	t1;

	i = -1;
	data->time_of_beginning = get_time(); // meilleur endroit ?
	if (data->nb_of_meals > 0)
	{
		if (pthread_create(&t1, NULL, &monitor, &data->philo[0])) // meilleur endroit ?
			return (error(TH_ERR, data), 1);
	}
	while (++i < data->nb_of_philo)
	{
		if (pthread_create(&data->tid[i], NULL, &routine, &data->philo[i]))
			return (1);
		ft_usleep(1);
	}
	i = -1;
	ft_usleep(1);
	while (++i < data->nb_of_philo)
		pthread_join(data->tid[i], NULL);
	ft_usleep(1);
	return (0);
}
