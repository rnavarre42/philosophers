/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_diners.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnavarre <rnavarre@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 09:37:17 by rnavarre          #+#    #+#             */
/*   Updated: 2021/12/20 13:42:53 by rnavarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

void	init_diners(t_philo *philo)
{
	int				i;
	t_diner			*diner;

	i = 0;
	diner = philo->diners;
	while (i < philo->diner_count)
	{
		diner->id = i + 1;
		diner->parent = philo;
		diner->chopstick_min_mutex = philo->chopstick_mutex_list + i;
		diner->chopstick_max_mutex = philo->chopstick_mutex_list + i + 1;
		diner->time_to_death = now() + diner->parent->time_to_die;
		diner++;
		i++;
	}
	diner--;
	diner->chopstick_min_mutex = philo->chopstick_mutex_list;
	diner->chopstick_max_mutex = philo->chopstick_mutex_list + i - 1;
}
