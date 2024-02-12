/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 19:35:38 by jdenis            #+#    #+#             */
/*   Updated: 2024/02/08 10:57:30 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	arg_init(t_philo *philo, char **argv)
{
	philo->num_of_philos = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		philo->num_to_eat = ft_atoi(argv[5]);
	else
		philo->num_to_eat = -1;
}

void	init_philosophers(t_philo *philos, t_data *data,
			pthread_mutex_t *forks, char **argv)
{
	int	index;

	index = 0;
	while (index < ft_atoi(argv[1]))
	{
		arg_init(&philos[index], argv);
		philos[index].id_number = index + 1;
		philos[index].meals_eaten = 0;
		philos[index].start_time = get_current_time();
		philos[index].last_meal = get_current_time();
		philos[index].eating = false;
		philos[index].write_lock = &data->write_lock;
		philos[index].dead_lock = &data->dead_lock;
		philos[index].meal_lock = &data->meal_lock;
		philos[index].dead = &data->dead_flag;
		philos[index].left_fork = &forks[index];
		if (index == 0)
			philos[index].right_fork = &forks[philos[index].num_of_philos - 1];
		else
			philos[index].right_fork = &forks[index - 1];
		index++;
	}
}

void	init_forks(pthread_mutex_t *forks, int nb_philos)
{
	int	index;

	index = 0;
	while (index < nb_philos)
	{
		pthread_mutex_init(&forks[index], NULL);
		index++;
	}
}

void	init_data(t_data *data, t_philo *philos)
{
	data->philos = philos;
	data->dead_flag = false;
	pthread_mutex_init(&data->write_lock, NULL);
	pthread_mutex_init(&data->dead_lock, NULL);
	pthread_mutex_init(&data->meal_lock, NULL);
}

void	destroy_data(t_data *data, pthread_mutex_t *forks)
{
	int	index;

	index = 0;
	pthread_mutex_destroy(&data->write_lock);
	pthread_mutex_destroy(&data->dead_lock);
	pthread_mutex_destroy(&data->meal_lock);
	while (index < data->philos[0].num_of_philos)
	{
		pthread_mutex_destroy(&forks[index]);
		index++;
	}
}
