/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:41:50 by jdenis            #+#    #+#             */
/*   Updated: 2024/02/02 17:35:11 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	rompiche(t_philo *philo)
{
	print_lock("is sleeping", philo);
	ft_usleep(philo->time_to_sleep, philo);
}
