/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:45:12 by jdenis            #+#    #+#             */
/*   Updated: 2024/02/08 10:59:38 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdbool.h>
# include <unistd.h>

# define MAX_PHILOS 200

typedef struct s_philo
{
	pthread_t		thread;
	int				id_number;
	int				num_of_philos;
	int				num_to_eat;
	int				meals_eaten;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start_time;
	size_t			last_meal;
	bool			eating;
	bool			*dead;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
}					t_philo;

typedef struct s_data
{
	bool			dead_flag;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	t_philo			*philos;
}					t_data;

int		thread_philo(t_data *data, pthread_mutex_t *forks);
void	exit_philo(t_data *data, pthread_mutex_t *forks, char *msg);
void	destroy_data(t_data *data, pthread_mutex_t *forks);
void	init_data(t_data *data, t_philo *philos);
void	init_forks(pthread_mutex_t *forks, int nb_philos);
void	init_philosophers(t_philo *philos, t_data *data,
			pthread_mutex_t *forks, char **argv);
int		handle_arg(int argc, char **argv);
int		ft_atoi(const char *str);
int		ft_usleep(size_t milliseconds, t_philo *philo);
size_t	get_current_time(void);
void	print_lock(char *str, t_philo *philo);
bool	philo_dead(t_philo *philo);

void	eat(t_philo *philo);
void	eat_odd(t_philo *philo);
void	think(t_philo *philo);
void	rompiche(t_philo *philo);
void	*monitoring(void *philo);

#endif