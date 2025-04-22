/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdakhlao <sdakhlao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:57:11 by sdakhlao          #+#    #+#             */
/*   Updated: 2024/12/10 23:00:02 by sdakhlao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define ERR_IN_2 "INVALID INPUT VALUES"
# define TH_ERR "ERROR WHILE CREATING THREADS"
# define TAKE_FORKS "has taken a fork"
# define THINKING "is thinking"
# define SLEEPING "is sleeping"
# define EATING "is eating || HE ATE"
# define DIED "died"

struct	s_data;

typedef struct s_philo
{
	struct s_data	*data;				// Tableau de donnees
	pthread_t		t1;
	u_int64_t		time_until_death;	// Temps auquel le philosophe meurt
	int				is_eating;			// Si le philosophe est entrain de mange
	int				id;					// ID du philosophe
	int				nb_meal_ate;		// Nombre de repas que le philosophe a manger
	pthread_mutex_t	*l_fork;			// Mutex pour la fourchette a gauche du philosophe
	pthread_mutex_t	*r_fork;			// Mutex pour la fourchette a droite du philosophe
	pthread_mutex_t	cadenas;			// Mutex général du philosophe
}	t_philo;

typedef struct s_data
{
	int				nb_of_philo;		// Nombre total de philosophes
	int				nb_of_meals;		// Nombre de repas minimum requis pour chaque philosophe
	int				death;				// Flag indiquant si un philosophe est mort
	int				they_ate_enough;	// Flag indiquant si tous les philosophes ont mangé suffisamment
	t_philo			*philo;				// Tableau des philosophes
	u_int64_t		time_to_die;		// Temps avant la mort d'un philosophe s'il ne mange pas
	u_int64_t		time_to_eat;		// Temps pour manger
	u_int64_t		time_to_sleep;		// Temps pour dormir
	u_int64_t		time_of_beginning;	// Temps de début de la simulation
	pthread_t		*tid;				// ID des threads
	pthread_mutex_t	*fork;				// Tableau des mutex pour les fourchettes
	pthread_mutex_t	message;			// Mutex pour synchroniser les messages
	pthread_mutex_t	lock;				// Mutex général pour les accès globaux
}	t_data;

// actions.c
void		take_forks(t_philo *philo);
void		is_eating(t_philo *philo);

// routine.c
void		*routine(void *philos);
void		*monitor(void *philos);

// case_one.c
int			case_one(t_data *data);

// malloc_mutex.c
int			mutex_data(t_data *data);
int			malloc_data(t_data *data);

// pars.c
int			check_values(t_data *data);
int			scan_args(int argc, char **argv);

// utils.c
void		ft_message(char *str, t_philo *philo);
int			ft_usleep(useconds_t time);
int			ft_atoi(const char *str);
u_int64_t	get_time(void);

// init.c
int			init_all(t_data *data, char **argv, int argc);

//error_exit.c
void		cleanup(t_data *data);
int			error(char *str, t_data *data);

// threads.c
int			thread_things(t_data *data);

#endif
