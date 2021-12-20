/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diner_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnavarre <rnavarre@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 09:37:00 by rnavarre          #+#    #+#             */
/*   Updated: 2021/12/20 13:13:05 by rnavarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

static void
	eat_diner(t_diner *diner)
{
	uint64_t	eat_time;

	pthread_mutex_lock(diner->chopstick_min_mutex);
	print_state("has taken a fork", diner);
	pthread_mutex_lock(diner->chopstick_max_mutex);
	print_state("has taken a fork", diner);
	diner->state = diner_eating;
	diner->time_to_death = now() + diner->parent->time_to_die;
	eat_time = diner->parent->time_to_eat;
	print_state("eating", diner);
	dsleep(eat_time, diner->parent);
	diner->times_eat++;
	pthread_mutex_unlock(diner->chopstick_min_mutex);
	pthread_mutex_unlock(diner->chopstick_max_mutex);
}

static void
	sleep_diner(t_diner *diner)
{
	uint64_t	sleep_time;

	sleep_time = diner->parent->time_to_sleep;
	diner->state = diner_sleeping;
	print_state("sleep", diner);
	dsleep(sleep_time, diner->parent);
}

static void
	think_diner(t_diner *diner)
{
	diner->state = diner_thinking;
	print_state("thinking", diner);
}

void
	*diner_loop(void *data)
{
	t_diner	*diner;

	diner = data;
	while (!diner->parent->diners_exit && diner->state != diner_dead)
	{
		eat_diner(diner);
		sleep_diner(diner);
		think_diner(diner);
	}
	return (data);
}
