/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnavarre <rnavarre@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 09:37:24 by rnavarre          #+#    #+#             */
/*   Updated: 2021/12/20 13:41:58 by rnavarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <limits.h>
#include <stdbool.h>

inline static _Bool
	check_bounds(int nb, int min, int max)
{
	return (nb >= min && nb <= max);
}

static _Bool
	check_limits(t_philo *philo)
{
	if (!check_bounds(philo->diner_count, 1, 200)
		|| !check_bounds(philo->time_to_eat, 60, INT_MAX)
		|| !check_bounds(philo->time_to_die, 60, INT_MAX)
		|| !check_bounds(philo->time_to_sleep, 60, INT_MAX)
		|| !check_bounds(philo->times_must_eat, 0, INT_MAX))
		write(0, "Limits exceeded\n", 16);
	else
	{
		if (philo->unlimited)
			philo->times_must_eat = -1;
		return (true);
	}
	return (false);
}

static _Bool
	init_mutex(t_philo *philo)
{
	int	i;

	i = 0;
	philo->chopstick_mutex_list = ft_calloc(sizeof(pthread_mutex_t),
			philo->diner_count);
	while (i < philo->diner_count)
	{
		pthread_mutex_init(philo->chopstick_mutex_list + i, NULL);
		i++;
	}
	if (!philo->chopstick_mutex_list)
		return (false);
	pthread_mutex_init(&philo->print_mutex, NULL);
	return (true);
}

static bool	check_numeric(char **args)
{
	while (*args)
	{
		while (**args)
		{
			if (!ft_isdigit(**args))
			{
				write(1, "illegal character\n", 18);
				return (false);
			}
			(*args)++;
		}
		args++;
	}
	return (true);
}

_Bool
	init_philo(t_philo *philo, char **args)
{
	ft_memset(philo, 0, sizeof(t_philo));
	philo->diner_count = ft_atoi(args[1]);
	philo->time_to_die = ft_atoi(args[2]);
	philo->time_to_eat = ft_atoi(args[3]);
	philo->time_to_sleep = ft_atoi(args[4]);
	if (args[5])
		philo->times_must_eat = ft_atoi(args[5]);
	else
	{
		philo->times_must_eat = 0;
		philo->unlimited = true;
	}
	if (!check_numeric(args + 1) || !check_limits(philo))
		return (false);
	philo->diners = ft_calloc(sizeof(t_diner), philo->diner_count);
	if (!philo->diners || !init_mutex(philo))
		return (false);
	philo->start_time = now();
	return (true);
}
