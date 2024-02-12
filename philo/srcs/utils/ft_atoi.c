/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 19:37:56 by jdenis            #+#    #+#             */
/*   Updated: 2024/01/26 19:39:33 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_atoi(const char *str)
{
	int					i;
	int					signe;
	unsigned long long	base;

	base = 0;
	signe = 1;
	i = 0;
	while ((str[i] < 14 && str[i] > 8) || str[i] == 32)
	{
		i++;
	}
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe = signe * -1;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		base = (base * 10) + str[i] - '0';
		i++;
	}
	return (base * signe);
}
