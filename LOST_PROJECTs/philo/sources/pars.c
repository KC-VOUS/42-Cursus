#include "../philo.h"

int	scan_args(int argc, char **argv)
{
	int		i;
	int		j;
	char	**str;

	str = argv;
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] >= '0' && str[i][j] <= '9')
				j++;
			else
				return (1);
		}
		i++;
	}
	return (0);
}

int	check_values(t_data *data)
{
	if (data->nb_of_philo <= 0 || data->time_to_die <= 0
		|| data->time_to_eat <= 0 || data->time_to_sleep <= 0
		|| data->nb_of_meals == 0)
		return (error(ERR_IN_2, NULL), 1);
	return (0);
}
