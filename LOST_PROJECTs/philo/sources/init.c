#include "../philo.h"

int	init_data(t_data *data, char **argv, int argc)
{
	data->death = 0;
	data->nb_of_meals = -1;
	data->they_ate_enough = 0;
	data->nb_of_philo = ft_atoi(argv[1]);
	data->time_to_die = (u_int64_t) ft_atoi(argv[2]);
	data->time_to_eat = (u_int64_t) ft_atoi(argv[3]);
	data->time_to_sleep = (u_int64_t) ft_atoi(argv[4]);
	if (argc == 6)
		data->nb_of_meals = ft_atoi(argv[5]);
	check_values(data);
	return (0);
}

int	init_philos(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_of_philo)
	{
		data->philo[i].id = i + 1;
		data->philo[i].data = data;
		data->philo[i].is_eating = 0;
		data->philo[i].nb_meal_ate = 0;
		data->philo[i].time_until_death = data->time_to_die;
		if (pthread_mutex_init(&data->philo[i].cadenas, NULL))
		{
			while (--i >= 0)
				pthread_mutex_destroy(&data->philo[i].cadenas);
			return (1);
		}
	}
	return (0);
}

int	init_forks(t_data *data)
{
	int	i;

	i = 0;
	mutex_data(data);
	data->philo[i].r_fork = &data->fork[i];
	data->philo[i].l_fork = &data->fork[data->nb_of_philo - 1];
	while (++i < data->nb_of_philo)
	{
		data->philo[i].r_fork = &data->fork[i];
		data->philo[i].l_fork = &data->fork[i - 1];
	}
	return (0);
}

int	init_all(t_data *data, char **argv, int argc)
{
	if (init_data(data, argv, argc))
		return (1);
	if (malloc_data(data))
		return (1);
	if (init_philos(data))
		return (1);
	if (init_forks(data))
		return (1);
	return (0);
}
