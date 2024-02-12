/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 19:30:41 by jdenis            #+#    #+#             */
/*   Updated: 2024/02/08 10:58:26 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	is_number(char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if (str[index] < '0' || str[index] > '9')
			return (-1);
		index++;
	}
	return (0);
}

int	are_numbers(char **argv)
{
	size_t	index;

	index = 1;
	while (argv[index])
	{
		if (is_number(argv[index]) == -1)
			return (-1);
		index++;
	}
	return (0);
}

int	is_positive(char **argv)
{
	size_t	index;

	index = 1;
	while (argv[index])
	{
		if (ft_atoi(argv[index]) < 0)
			return (-1);
		index++;
	}
	return (0);
}

int	handle_arg(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
	{
		printf("Wrong number of arguments\n");
		return (-1);
	}
	else
	{
		if (ft_atoi(argv[1]) > 200)
		{
			printf("Too many philosophers\n");
			return (-1);
		}
		if (are_numbers(argv) == -1 || is_positive(argv) == -1)
		{
			printf("Wrong argument\n");
			return (-1);
		}
	}
	return (0);
}
