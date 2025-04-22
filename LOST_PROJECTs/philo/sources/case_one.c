#include "../philo.h"

int	case_one(t_data *data)
{
	data->time_of_beginning = get_time();
	ft_message(TAKE_FORKS, &data->philo[0]);
	ft_usleep(data->time_to_die);
	ft_message(DIED, &data->philo[0]);
	return (cleanup(data), 0);
}
