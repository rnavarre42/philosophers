/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_diner_threads.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnavarre <rnavarre@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 09:38:19 by rnavarre          #+#    #+#             */
/*   Updated: 2021/12/14 09:14:27 by rnavarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <unistd.h>

void
	start_diner_threads(t_philo *philo)
{
	int		count;
	t_diner	*diner;

	count = philo->diner_count;
	diner = philo->diners;
	while (count > 0)
	{
		pthread_create(&diner->pthread, NULL, diner_loop, diner);
		diner++;
		count--;
		usleep(50);
	}
}
