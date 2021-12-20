/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnavarre <rnavarre@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 09:38:25 by rnavarre          #+#    #+#             */
/*   Updated: 2021/12/14 11:13:38 by rnavarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>

void
	print_state(char *str, t_diner *diner)
{
	uint64_t		diff;

	pthread_mutex_lock(&diner->parent->print_mutex);
	diff = now() - diner->parent->start_time;
	if (!diner->parent->diners_exit && diner->state != diner_dead)
		printf("%llu %i %s\n", diff, diner->id, str);
	pthread_mutex_unlock(&diner->parent->print_mutex);
}
