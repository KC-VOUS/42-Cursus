#include "../philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 5 && argc != 6)
		return (printf("Bad Args\n"), 1);
	if (scan_args(argc, argv))
		return (printf("INVALID INPUT CHARACTER\n"), 1);
	if (init_all(&data, argv, argc))
		return (printf("can't init\n"), 1);
	if (data.nb_of_philo == 1)
		case_one(&data);
	if (thread_things(&data))
		return (error(TH_ERR, &data), 1);
	cleanup(&data);
	return (0);
}
