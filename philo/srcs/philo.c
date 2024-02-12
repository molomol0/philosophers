/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:40:13 by jdenis            #+#    #+#             */
/*   Updated: 2024/02/08 10:56:08 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	philo_dead(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead == true)
	{
		pthread_mutex_unlock(philo->dead_lock);
		return (true);
	}
	pthread_mutex_unlock(philo->dead_lock);
	return (false);
}

void	*routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (philo->id_number % 2 == 0)
		ft_usleep(1, philo);
	while (!philo_dead(philo))
	{
		if (philo->id_number % 2 == 0)
			eat(philo);
		else
			eat_odd(philo);
		rompiche(philo);
		think(philo);
	}
	return (NULL);
}

int	thread_philo(t_data *data, pthread_mutex_t *forks)
{
	pthread_t	monitor;
	int			index;

	index = 0;
	if (pthread_create(&monitor, NULL, &monitoring, data->philos) != 0)
		exit_philo(data, forks, "Error: Failed to create thread\n");
	while (index < data->philos[0].num_of_philos)
	{
		if (pthread_create(&data->philos[index].thread, NULL,
				&routine, &data->philos[index]) != 0)
			exit_philo(data, forks, "Error: Failed to create thread\n");
		index++;
	}
	if (pthread_join(monitor, NULL) != 0)
		exit_philo(data, forks, "Error: Failed to join thread\n");
	index = 0;
	while (index < data->philos[0].num_of_philos)
	{
		if (pthread_join(data->philos[index].thread, NULL) != 0)
			exit_philo(data, forks, "Error: Failed to join thread\n");
		index++;
	}
	return (0);
}
