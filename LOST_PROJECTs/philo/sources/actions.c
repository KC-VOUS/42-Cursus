#include "../philo.h"

void	odd_take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	ft_message(TAKE_FORKS, philo);
	pthread_mutex_lock(philo->r_fork);
	ft_message(TAKE_FORKS, philo);
}

void	even_take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	ft_message(TAKE_FORKS, philo);
	pthread_mutex_lock(philo->l_fork);
	ft_message(TAKE_FORKS, philo);
}

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->cadenas);
	if (philo->id % 2 == 0)
		even_take_forks(philo);
	else
		odd_take_forks(philo);
	//philo->time_until_death = get_time() + philo->data->time_to_die; // pas sur de l'endroit
	pthread_mutex_unlock(&philo->cadenas);
}

void	done_eating(t_philo *philo)
{
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	ft_message(SLEEPING, philo);
	ft_usleep(philo->data->time_to_sleep);
	ft_message(THINKING, philo);
}

void	is_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->cadenas);
	philo->is_eating = 1;
	philo->time_until_death = get_time() + philo->data->time_to_die; // toujours pas
	philo->nb_meal_ate++;
	ft_message(EATING, philo);
	ft_usleep(philo->data->time_to_eat);
	philo->is_eating = 0;
	done_eating(philo);
	pthread_mutex_unlock(&philo->cadenas);
}
