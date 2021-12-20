/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_diners.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnavarre <rnavarre@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 09:38:29 by rnavarre          #+#    #+#             */
/*   Updated: 2021/12/20 13:42:24 by rnavarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <stdbool.h>

void
	wait_diners(t_philo *philo)
{
	int		id;
	t_diner	*diner;

	id = 0;
	if (philo->diner_count == 1)
		return ;
	while (id < philo->diner_count)
	{
		diner = philo->diners + id++;
		pthread_join(diner->pthread, NULL);
	}
}
