/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:42:00 by jdenis            #+#    #+#             */
/*   Updated: 2024/02/13 18:18:25 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	think(t_philo *philo)
{
	print_lock("is thinking", philo);
	while (get_current_time() - philo->last_meal < 0.9 * philo->time_to_die)
		ft_usleep(1, philo);
}
