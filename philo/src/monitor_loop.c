/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnavarre <rnavarre@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 09:36:53 by rnavarre          #+#    #+#             */
/*   Updated: 2021/12/20 13:42:16 by rnavarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdbool.h>
#include <unistd.h>

void	monitor_loop(t_philo *philo)
{
	int		id;
	_Bool	nobody_eat_more;
	t_diner	*diner;

	while (!philo->diners_exit)
	{
		id = 0;
		nobody_eat_more = false;
		while (id < philo->diner_count && !philo->diners_exit)
		{
			diner = philo->diners + id++;
			should_die(diner);
			philo->diners_exit = (diner->state == diner_dead);
			nobody_eat_more |= (diner->times_eat < philo->times_must_eat);
		}
		if (philo->times_must_eat > -1)
			philo->diners_exit |= !nobody_eat_more;
	}
}
