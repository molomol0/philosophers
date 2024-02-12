/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lock.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:46:07 by jdenis            #+#    #+#             */
/*   Updated: 2024/02/08 10:59:14 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_lock(char *str, t_philo *philo)
{
	pthread_mutex_lock(philo->write_lock);
	pthread_mutex_lock(philo->dead_lock);
	pthread_mutex_lock(philo->meal_lock);
	if (*philo->dead == false && philo->eating == false)
	{
		pthread_mutex_unlock(philo->meal_lock);
		pthread_mutex_unlock(philo->dead_lock);
		printf("%lu %d %s\n", (get_current_time() - philo->start_time),
			philo->id_number, str);
		pthread_mutex_lock(philo->dead_lock);
		pthread_mutex_lock(philo->meal_lock);
	}
	pthread_mutex_unlock(philo->meal_lock);
	pthread_mutex_unlock(philo->dead_lock);
	pthread_mutex_unlock(philo->write_lock);
}
