/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:37:47 by jdenis            #+#    #+#             */
/*   Updated: 2024/02/13 18:15:42 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_usleep(size_t time, t_philo *philo)
{
	size_t	start;

	start = get_current_time();
	pthread_mutex_lock(philo->dead_lock);
	while (get_current_time() < start + time && !*philo->dead)
	{
		pthread_mutex_unlock(philo->dead_lock);
		usleep(10);
		pthread_mutex_lock(philo->dead_lock);
	}
	pthread_mutex_unlock(philo->dead_lock);
	return (0);
}
