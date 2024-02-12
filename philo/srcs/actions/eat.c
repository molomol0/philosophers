/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:41:37 by jdenis            #+#    #+#             */
/*   Updated: 2024/02/08 10:59:22 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	eat_odd(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_lock("has taken a fork", philo);
	if (philo->num_of_philos == 1)
	{
		ft_usleep(philo->time_to_die, philo);
		pthread_mutex_unlock(philo->left_fork);
		return ;
	}
	pthread_mutex_lock(philo->right_fork);
	print_lock("has taken a fork", philo);
	print_lock("is eating", philo);
	pthread_mutex_lock(philo->meal_lock);
	philo->eating = true;
	philo->last_meal = get_current_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal_lock);
	ft_usleep(philo->time_to_eat, philo);
	philo->eating = false;
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	print_lock("has taken a fork", philo);
	pthread_mutex_lock(philo->left_fork);
	print_lock("has taken a fork", philo);
	print_lock("is eating", philo);
	pthread_mutex_lock(philo->meal_lock);
	philo->eating = true;
	philo->last_meal = get_current_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal_lock);
	ft_usleep(philo->time_to_eat, philo);
	philo->eating = false;
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}
