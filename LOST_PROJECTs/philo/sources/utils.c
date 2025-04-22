#include "../philo.h"

int	ft_atoi(const char *str)
{
	int		sign;
	int		res;

	sign = 1;
	res = 0;
	while ((*str > 8 && *str < 14) || *str == 32)
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		if (res * 10 < 0)
			return (-1);
		res *= 10;
		res += *str - '0';
		str++;
	}
	return (res * sign);
}

u_int64_t	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (0);
	return ((tv.tv_sec * (u_int64_t)1000) + (tv.tv_usec / 1000));
}

int	ft_usleep(useconds_t time)
{
	u_int64_t	start;

	start = get_time();
	while ((get_time() - start) < time)
		usleep(time / 10);
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(char *)s1 - *(char *)s2);
}

void	ft_message(char *str, t_philo *philo)
{
	u_int64_t	time;

	pthread_mutex_lock(&philo->data->message);
	time = get_time() - philo->data->time_of_beginning;
	if (ft_strcmp(DIED, str) == 0 && philo->data->death == 0)
	{
		printf("%lu %d %s\n", time, philo->id, str);
		philo->data->death = 1;
	}
	if (ft_strcmp(EATING, str) == 0 && philo->data->death == 0)
		printf("%lu %d %s %d TIMES...\n", time, philo->id, str, philo->nb_meal_ate);
	else if (!philo->data->death)
		printf("%lu %d %s\n", time, philo->id, str);
	pthread_mutex_unlock(&philo->data->message);
}
