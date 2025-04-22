#include "../philo.h"

void	*monitor(void *philos)
{
	t_philo	*philo;

	philo = (t_philo *) philos;
	while (philo->data->death == 0)
	{
		pthread_mutex_lock(&philo->cadenas);
		if (philo->data->they_ate_enough >= philo->data->nb_of_philo)
			philo->data->death = 1;
		pthread_mutex_unlock(&philo->cadenas);
	}
	return ((void *)0);
}

// int	guetteur(t_philo *philo)
// {
// 	if (get_time() > philo->time_until_death)
// 	{
// 		ft_message(DIED, philo);
// 		return (1);
// 	}
// 	if (philo->nb_meal_ate == philo->data->nb_of_meals)
// 		philo->data->they_ate_enough++;
// 	return (0);
// }

void	*supervisor(void *philo_pointer)
{
	t_philo	*philo;

	philo = (t_philo *) philo_pointer;
	while (philo->data->death == 0)
	{
		pthread_mutex_lock(&philo->cadenas);
		if (get_time() >= philo->time_until_death && philo->is_eating == 0)
			ft_message(DIED, philo);
		if (philo->nb_meal_ate == philo->data->nb_of_meals)
		{
			pthread_mutex_lock(&philo->data->lock);
			philo->data->they_ate_enough++;
			philo->nb_meal_ate++;
			pthread_mutex_unlock(&philo->data->lock);
		}
		pthread_mutex_unlock(&philo->cadenas);
	}
	return ((void *)0);
}

void	*routine(void *philos)
{
	t_philo	*philo;

	philo = (t_philo *) philos;
	philo->time_until_death = get_time() + philo->data->time_to_die;
	if (pthread_create(&philo->t1, NULL, &supervisor, (void *)philo))
		return ((void *)1);
	while (!philo->data->death)
	{
		take_forks(philo);
		is_eating(philo);
	}
	if (pthread_join(philo->t1, NULL))
		return ((void *)1);
	return ((void *)0);
}
